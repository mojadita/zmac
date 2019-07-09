/* gendoc-mdoc.c --- driver for gendoc.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Tue Jul  9 09:35:42 EEST 2019
 * Copyright: (C) 2019 Luis Colorado.  All rights reserved.
 * License: BSD
 */

#include "gendoc.h"

int mdoc_init(struct gd_obj *to_init)
{
    /* TODO: implement */
    return -1;
}

char *mdoc_error(struct gd_obj *o)
{
    /* TODO: implement */
    return "unimplemented mdoc_error()";
}

void mdoc_end(struct gd_obj *o)
{
    /* TODO: implement */
}

int mdoc_h1(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_h2(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_h3(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_h4(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_h5(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_h6(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_t1(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_t2(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_t3(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_t4(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_t5(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_qt(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_hr(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_np(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_tt(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_zm(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_w(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_l(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_eol(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_fs(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_sp(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

int mdoc_oth(struct gd_obj *o, char *s)
{
    /* TODO: implement */
    return -1;
}

/* driver structure class */
struct gd_clss drv_class = {
    .gd_name = "mdoc",
    .gd_init = mdoc_init,
    .gd_error = mdoc_error,
    .gd_end = mdoc_end,
    .gd_h1 = mdoc_h1,
    .gd_h2 = mdoc_h2,
    .gd_h3 = mdoc_h3,
    .gd_h4 = mdoc_h4,
    .gd_h5 = mdoc_h5,
    .gd_h6 = mdoc_h6,
    .gd_t1 = mdoc_t1,
    .gd_t2 = mdoc_t2,
    .gd_t3 = mdoc_t3,
    .gd_t4 = mdoc_t4,
    .gd_t5 = mdoc_t5,
    .gd_qt = mdoc_qt,
    .gd_hr = mdoc_hr,
    .gd_np = mdoc_np,
    .gd_tt = mdoc_tt,
    .gd_zm = mdoc_zm,
    .gd_w = mdoc_w,
    .gd_l = mdoc_l,
    .gd_eol = mdoc_eol,
    .gd_fs = mdoc_fs,
    .gd_sp = mdoc_sp,
    .gd_oth = mdoc_oth,
}; /* drv_class */
/* EOF */
