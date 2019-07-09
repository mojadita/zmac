%{
/* gendoc.l -- program to generate documentaton in the several
 * 			   formats.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD version 3.
 * This program tries to detect all the markup in the original
 * documentation and convert it to the different formats
 * avaiblable.
 */
#include <dlfcn.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gendoc.h"

#define DRIVER_CLASS_SYMBOL "drv_class"

#ifndef VERSION
#error VERSION undefined, you must define VERSION in your CFLAGS
#endif

#define E(id)	printf("<%s>", #id)

int flags = 0;
char *format = NULL;

struct gd_obj *drvr = NULL;

static char driver_class_symbol[] = DRIVER_CLASS_SYMBOL;
static void do_help(void);

#define Fn(_nm, ...) do{if (drvr && drvr->gd_clss && drvr->gd_clss->gd_##_nm && drvr->gd_clss->gd_##_nm(drvr, yytext,##__VA_ARGS__)) return 0;} while(0)

%}

h1				^"."
h2				^".."
h3				^"..."
h4				^"...."
h5				^"....."
h6				^"......"
t1				^" "
t2				^"  "
t3				^"   "
t4				^"    "
t5				^"     "
qt				^\|
hr				^--*
tt				_[^_]*_
zm				zmac
w				[A-Za-z](-?[A-Za-z0-9])*
np				\n([\ \t]*\n)+
l				{w}@{w}
eol				\n
fs				[.?!][\ \t]+
sp				[\ \t]+
oth				.

%%

{h1}				{ Fn(h1); }
{h2}				{ Fn(h2); }
{h3}				{ Fn(h3); }
{h4}				{ Fn(h4); }
{h5}				{ Fn(h5); }
{h6}				{ Fn(h6); }
{t1}				{ Fn(t1); }
{t2}				{ Fn(t2); }
{t3}				{ Fn(t3); }
{t4}				{ Fn(t4); }
{t5}				{ Fn(t5); }
{qt}				{ Fn(qt); }
{hr}				{ Fn(hr); }
{np}				{ Fn(np); }
{tt}				{ Fn(tt); }
{zm}				{ Fn(zm); }
{w}					{ Fn(w); }
{l}					{ Fn(l); }
{eol}				{ Fn(eol); }
{fs}/[A-Z]			{ Fn(fs); }
{sp}				{ Fn(sp); }
{oth}				{ Fn(oth); }

%%

int yywrap()
{
	return 1;
}

int main(int argc, char **argv)
{
	int op;

	while ((op = getopt(argc, argv, "f:hv")) != EOF) {
		switch (op) {
		case 'f': format = optarg; break;
		case 'h': flags |= FLAG_HELP; break;
		case 'v': flags |= FLAG_VERSION; break;
		}
	} /* while */

	if (flags & FLAG_VERSION) {
		printf(F("VERSION: %s\n"), VERSION);
	}
	if (flags & FLAG_HELP) {
		do_help();
	}
	if (flags & (FLAG_VERSION | FLAG_HELP)) {
		exit(EXIT_SUCCESS);
	}

    drvr = gd_new(format);
    if (!drvr) {
        /* no need to print an error, as it has already been done. */
        exit(EXIT_FAILURE);
    }

	argc -= optind;
	argv += optind;

	if (argc) {
		int i;
		for (i = 0; i < argc; i++) {
			yyin = fopen(argv[i], "rt");
			if (!yyin) {
				fprintf(stderr,
					F("fopen: %s: %s\n"),
					argv[i],
					strerror(errno));
				continue;
			}
			yylex();
			fclose(yyin);
		}
	} else {
		yylex();
	} /* if */
}

static void do_help(void)
{
	printf(F("Usage: gendoc [-hv] [-f format] [file ...]\n"));
	printf(F("where:\n"));
	printf(F(" -h Get help.  Shows this help string.\n"));
	printf(F(" -v Get version string.  Shows the version of this\n"));
	printf(F("	command.\n"));
	printf(F(" -f format\n"));
	printf(F("	Allows to specify the driver to be used for\n"));
	printf(F("	the output format.\n"));
	printf(F("\n"));
	printf(F("The program outputs the documentation in the\n"));
	printf(F("output format specified.\n"));
}

struct gd_obj *gd_new(char *name)
{
	void *dlfd = NULL;
	if (name) {
		static char *path[] = {
			"./gendoc-%1$s.so",
			"./.gendoc/gendoc-%1$s.so",
			"%2$s/.gendoc/gendoc-%1$s.so",
			"/lib/gendoc/gendoc-%1$s.so",
			NULL,
		};
		char buffer[PATH_MAX];
		char *home = getenv("HOME");
		int i;
		for (i = 0; path[i]; i++) {
			snprintf(buffer, sizeof buffer, path[i], name, home);
			printf(F("trying %s\n"), buffer);
			dlfd = dlopen(buffer, RTLD_LAZY | RTLD_GLOBAL);
			if (dlfd) break;
		}
	} else {
		fprintf(stderr, F("trying default driver\n"));
		dlfd = dlopen(NULL, RTLD_LAZY | RTLD_GLOBAL);
	}
	if (!dlfd) {
		fprintf(stderr, F("dlopen: %s\n"), dlerror());
		goto err_dlopen;
	}
    struct gd_clss * gd_clss = dlsym(dlfd, driver_class_symbol);
    if (!gd_clss) {
        fprintf(stderr, F("dlsym: %s\n"), dlerror());
        goto err_drvlib;
    }
    if (name && gd_clss->gd_name && strcmp(gd_clss->gd_name, name)) {
        fprintf(stderr,
            F("gd_new: name(%s) does not match driver name\n"),
            name);
        goto err_drvlib;
    }
    struct gd_obj *obj = malloc(sizeof *obj);
    if (obj == NULL) {
        fprintf(stderr,
            F("malloc: %s\n"),
            strerror(errno));
        goto err_drvlib;
    }
    /* construct the object */
    obj->gd_clss = gd_clss;
    obj->gd_dlfd = dlfd;
    obj->gd_priv = NULL;
    if (   gd_clss->gd_init
        && gd_clss->gd_init(obj)) {
		fprintf(stderr,
			F("gd_init: %s\n"),
			gd_clss->gd_error
				? gd_clss->gd_error(obj)
				: "unknown error (no gd_error() defined)\n");
		goto err_malloc;
    }
    return obj;

err_malloc:
    free(obj);
err_drvlib:
    dlclose(dlfd);
err_dlopen:
    return NULL;
} /*  gd_new */

/* DEFAULT DRIVER */
int gd_def_h1(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}

int gd_def_h2(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}
int gd_def_h3(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}
int gd_def_h4(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}
int gd_def_h5(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}
int gd_def_h6(struct gd_obj *o, char *s)
{
    E(h1); ECHO;
	return 0;
}
int gd_def_t1(struct gd_obj *o, char *s)
{
    E(t1); ECHO;
	return 0;
}
int gd_def_t2(struct gd_obj *o, char *s)
{
    E(t2); ECHO;
	return 0;
}
int gd_def_t3(struct gd_obj *o, char *s)
{
    E(t3); ECHO;
	return 0;
}
int gd_def_t4(struct gd_obj *o, char *s)
{
    E(t4); ECHO;
	return 0;
}
int gd_def_t5(struct gd_obj *o, char *s)
{
    E(t5); ECHO;
	return 0;
}
int gd_def_qt(struct gd_obj *o, char *s)
{
    E(qt); ECHO;
	return 0;
}
int gd_def_hr(struct gd_obj *o, char *s)
{
    E(hr); ECHO;
	return 0;
}
int gd_def_tt(struct gd_obj *o, char *s)
{
    E(tt); ECHO;
	return 0;
}
int gd_def_zm(struct gd_obj *o, char *s)
{
    E(zmac); ECHO;
	return 0;
}
int gd_def_w(struct gd_obj *o, char *s)
{
	E(w); ECHO;
	return 0;
}
int gd_def_np(struct gd_obj *o, char *s)
{
    E(np); ECHO;
	return 0;
}
int gd_def_l(struct gd_obj *o, char *s)
{
    E(l); ECHO;
	return 0;
}
int gd_def_eol(struct gd_obj *o, char *s)
{
    E(eol); ECHO;
	return 0;
}
int gd_def_sp(struct gd_obj *o, char *s)
{
    E(sp); ECHO;
	return 0;
}
int gd_def_oth(struct gd_obj *o, char *s)
{
    E(oth); ECHO;
	return 0;
}

struct gd_clss drv_class = {
    .gd_name = "",
    .gd_init = NULL,
    .gd_error = NULL,
    .gd_end = NULL,
	.gd_h1 = gd_def_h1,
	.gd_h2 = gd_def_h2,
	.gd_h3 = gd_def_h3,
	.gd_h4 = gd_def_h4,
	.gd_h5 = gd_def_h5,
	.gd_h6 = gd_def_h6,
	.gd_t1 = gd_def_t1,
	.gd_t2 = gd_def_t2,
	.gd_t3 = gd_def_t3,
	.gd_t4 = gd_def_t4,
	.gd_t5 = gd_def_t5,
	.gd_qt = gd_def_qt,
	.gd_hr = gd_def_hr,
	.gd_np = gd_def_np,
	.gd_tt = gd_def_tt,
	.gd_zm = gd_def_zm,
	.gd_w = gd_def_w,
	.gd_l = gd_def_l,
	.gd_eol = gd_def_eol,
	.gd_sp = gd_def_sp,
	.gd_oth = gd_def_oth,
};
