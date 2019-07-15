/* gendoc-html.c --- driver for gendoc.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Tue Jul  9 14:42:24 EEST 2019
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD
 */

#include <assert.h>
#include <stdlib.h>

#include "gendoc.h"

enum tags {
	 TAG_NONE, TAG_MARK,
	 TAG_H1, TAG_H2, TAG_H3, TAG_H4, TAG_H5, TAG_H6,
}; /* tags */

struct nest {
	int type;
	struct nest *next;
};

struct html_priv {
	/* TODO: put all state information here.
	 */
	struct nest *top;
};

int html_init(struct gd_obj *to_init)
{
	struct html_priv *p;
	to_init->gd_priv = p  = malloc(sizeof *p);
	assert(to_init->gd_priv != NULL);

	p->top = NULL;
    return 0;
}

char *html_error(struct gd_obj *o)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return "unimplemented html_error()";
}

void html_end(struct gd_obj *o)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
}

int html_h1(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_h2(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_h3(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_h4(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_h5(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_h6(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_t1(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_t2(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_t3(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_t4(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_t5(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_qt(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_hr(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_np(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_tt(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_zm(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_w(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_l(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_eol(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_fs(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_sp(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_oth(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_nbsp(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

int html_ext(struct gd_obj *o, char *s)
{
	struct html_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}

/* driver structure class */
struct gd_clss drv_class = {
    .gd_name = "html",
    .gd_init = html_init,
    .gd_error = html_error,
    .gd_end = html_end,
    .gd_h1 = html_h1,
    .gd_h2 = html_h2,
    .gd_h3 = html_h3,
    .gd_h4 = html_h4,
    .gd_h5 = html_h5,
    .gd_h6 = html_h6,
    .gd_t1 = html_t1,
    .gd_t2 = html_t2,
    .gd_t3 = html_t3,
    .gd_t4 = html_t4,
    .gd_t5 = html_t5,
    .gd_qt = html_qt,
    .gd_hr = html_hr,
    .gd_np = html_np,
    .gd_tt = html_tt,
    .gd_zm = html_zm,
    .gd_w = html_w,
    .gd_l = html_l,
    .gd_eol = html_eol,
    .gd_fs = html_fs,
    .gd_sp = html_sp,
    .gd_oth = html_oth,
    .gd_nbsp = html_nbsp,
    .gd_ext = html_ext,
}; /* drv_class */
/* EOF */
