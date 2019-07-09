/* gendoc-md.c --- driver for gendoc.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Tue Jul  9 14:42:24 EEST 2019
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD
 */

#include <assert.h>
#include <stdlib.h>

#include "gendoc.h"

struct md_priv {
	/* TODO: put all state information here.
	 */
};

int md_init(struct gd_obj *to_init)
{
	struct md_priv *p;
	to_init->gd_priv = p  = malloc(sizeof *p);
	assert(to_init->gd_priv != NULL);

    /* TODO: implement */
    return -1;
}

char *md_error(struct gd_obj *o)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return "unimplemented md_error()";
}

void md_end(struct gd_obj *o)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
}

int md_h1(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_h2(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_h3(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_h4(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_h5(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_h6(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_t1(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_t2(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_t3(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_t4(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_t5(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_qt(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_hr(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_np(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_tt(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_zm(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_w(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_l(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_eol(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_fs(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_sp(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_oth(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_nbsp(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int md_ext(struct gd_obj *o, char *s)
{
	struct md_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

/* driver structure class */
struct gd_clss drv_class = {
    .gd_name = "md",
    .gd_init = md_init,
    .gd_error = md_error,
    .gd_end = md_end,
    .gd_h1 = md_h1,
    .gd_h2 = md_h2,
    .gd_h3 = md_h3,
    .gd_h4 = md_h4,
    .gd_h5 = md_h5,
    .gd_h6 = md_h6,
    .gd_t1 = md_t1,
    .gd_t2 = md_t2,
    .gd_t3 = md_t3,
    .gd_t4 = md_t4,
    .gd_t5 = md_t5,
    .gd_qt = md_qt,
    .gd_hr = md_hr,
    .gd_np = md_np,
    .gd_tt = md_tt,
    .gd_zm = md_zm,
    .gd_w = md_w,
    .gd_l = md_l,
    .gd_eol = md_eol,
    .gd_fs = md_fs,
    .gd_sp = md_sp,
    .gd_oth = md_oth,
    .gd_nbsp = md_nbsp,
    .gd_ext = md_ext,
}; /* drv_class */
/* EOF */
