/* gendoc.h -- type definitions and constants for the gendoc
 *             utility.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Mon Jul  8 08:43:29 EEST 2019
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD
 */
#ifndef _GENDOC_H
#define _GENDOC_H

#ifdef _CB
#error _CB clashes with the definition used here.
#endif

struct gd_obj {
	struct gd_clss  *gd_clss; /* virtual functions */
	void            *gd_dlfd; /* from dlopen */
	void			*gd_priv; /* private info */
	/* this can be extended in the different drivers
	 * for storage of private data. */
};

struct gd_obj *gd_new(char *name);  /* gets a new instance. */

struct gd_clss {
    char             *gd_name;                       /* driver name */
	int               (*gd_init)(struct gd_obj *to_init);/* get the instance */
    char             *(*gd_error)(struct gd_obj *o); /* print error */
	void              (*gd_end)(struct gd_obj *o);	 /* called at end. */

	/* ... callback pointers for the driver to be called upon
	 * on each detected token. */
#define _CB(_n) int (*gd_##_n)(struct gd_obj *o, char *txt)
	_CB(h1); _CB(h2); _CB(h3); _CB(h4); _CB(h5);
	_CB(h6); _CB(t1); _CB(t2); _CB(t3); _CB(t4);
	_CB(t5); _CB(qt); _CB(hr); _CB(np); _CB(tt);
	_CB(zm); _CB(w);  _CB(l);  _CB(eol); _CB(fs);
    _CB(sp); _CB(oth); _CB(nbsp); _CB(ext);
#undef _CB
};

/* this macro is a convenience to printf(3) formats, to allow to
 * include automatically the source filename and the line where
 * this macro was used.  It appends on the left to the format
 * string (which must be a constant string literal) placeholders
 * for the source name and the line where this call was made, and
 * adds to the beginning of the parameter list the macros to
 * expand those. */
#define F(_fmt) "%s:%d: " _fmt, __FILE__, __LINE__

/* configuration flags. For the flags glolbal variable. */
#define FLAG_HELP		(1 << 0)
#define FLAG_VERSION	(1 << 1)

extern int flags; /* flags global variable */

extern char *format; /* output file format.  Used to select
					  * the driver to be used to do the
					  * conversions.  */

#endif /* _GENDOC_H */
