/* gendoc-c.c --- driver for gendoc.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Tue Jul  9 14:07:35 EEST 2019
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "gendoc.h"

static char pop_on_empty_stack[] = "POP ON EMPTY STACK";

#define STACK_SIZE 						100
#define PUSH(what)	do {					\
			if (!p->top) {					\
				p->error = "STACK OVERFLOW";\
				return -1;					\
			}								\
			p->stack[--p->top] = (_what);	\
		} while (0)
#define POP() (p->top < STACK_SIZE			\
		? p->stack[p->top++]				\
		: p->error = pop_on_empty_stack)

struct c_priv {
	char *error;
	char *stack[STACK_SIZE]; /* to remember state */
	int top;
};

int c_init(struct gd_obj *to_init)
{
	struct c_priv *p;
	to_init->gd_priv = p  = malloc(sizeof *p);
	assert(to_init->gd_priv != NULL);

	p->top = STACK_SIZE;

    return 0;
}

char *c_error(struct gd_obj *o)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    return p->error ? p->error : "NO ERROR";
}

void c_end(struct gd_obj *o)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	if (p->top != STACK_SIZE) {
		fprintf(stderr,
			F("STACK UNBALANCE: top(%d) != STACK_SIZE(%d)\n"),
			p->top, STACK_SIZE);
		o->gd_priv = NULL;
		free(p);
	}
}

int c_h1(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	printf("#");
    /* TODO: implement */
    return -1;
}

int c_h2(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
	printf("##");
    return -1;
}

int c_h3(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	printf("###");
    /* TODO: implement */
    return -1;
}

int c_h4(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	printf("####");
    /* TODO: implement */
    return -1;
}

int c_h5(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	printf("#####");
    /* TODO: implement */
    return -1;
}

int c_h6(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
	printf("######");
    /* TODO: implement */
    return -1;
}

int c_t1(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_t2(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_t3(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_t4(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_t5(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_qt(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_hr(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_np(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_tt(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_zm(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_w(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_l(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_eol(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_fs(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_sp(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_oth(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_nbsp(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int c_ext(struct gd_obj *o, char *s)
{
	struct c_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

/* driver structure class */
struct gd_clss drv_class = {
    .gd_name = "c",
    .gd_init = c_init,
    .gd_error = c_error,
    .gd_end = c_end,
    .gd_h1 = c_h1,
    .gd_h2 = c_h2,
    .gd_h3 = c_h3,
    .gd_h4 = c_h4,
    .gd_h5 = c_h5,
    .gd_h6 = c_h6,
    .gd_t1 = c_t1,
    .gd_t2 = c_t2,
    .gd_t3 = c_t3,
    .gd_t4 = c_t4,
    .gd_t5 = c_t5,
    .gd_qt = c_qt,
    .gd_hr = c_hr,
    .gd_np = c_np,
    .gd_tt = c_tt,
    .gd_zm = c_zm,
    .gd_w = c_w,
    .gd_l = c_l,
    .gd_eol = c_eol,
    .gd_fs = c_fs,
    .gd_sp = c_sp,
    .gd_oth = c_oth,
    .gd_nbsp = c_nbsp,
    .gd_ext = c_ext,
}; /* drv_class */
/* EOF */
