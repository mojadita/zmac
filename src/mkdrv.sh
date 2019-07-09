FUNCS="h1 h2 h3 h4 h5 h6 t1 t2 t3 t4 t5 qt hr np tt zm w l eol fs sp oth nbsp ext"

for i
do
	if [ -f gendoc-$i.c ]
	then
		echo "gendoc-$i.c: already exists" >&2
		continue;
	fi
	(cat <<EOF1
/* gendoc-${i}.c --- driver for gendoc.
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: $(LANG=C date)
 * Copyright: (C) $(LANG=C date +%Y) Luis Colorado.  All rights reserved.
 * License: BSD
 */

#include <assert.h>
#include <stdlib.h>

#include "gendoc.h"

struct ${i}_priv {
	/* TODO: put all state information here.
	 */
};

int ${i}_init(struct gd_obj *to_init)
{
	struct ${i}_priv *p;
	to_init->gd_priv = p  = malloc(sizeof *p);
	assert(to_init->gd_priv != NULL);

    /* TODO: implement */
    return -1;
}

char *${i}_error(struct gd_obj *o)
{
	struct ${i}_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return "unimplemented ${i}_error()";
}

void ${i}_end(struct gd_obj *o)
{
	struct ${i}_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
}
EOF1

    for j in $FUNCS
    do
        cat <<EOF2

int ${i}_${j}(struct gd_obj *o, char *s)
{
	struct ${i}_priv *p = o->gd_priv;
	assert(o->gd_priv != NULL);
    /* TODO: implement */
    return -1;
}
EOF2
    done
    cat <<EOF3

/* driver structure class */
struct gd_clss drv_class = {
    .gd_name = "${i}",
    .gd_init = ${i}_init,
    .gd_error = ${i}_error,
    .gd_end = ${i}_end,
EOF3
    for j in $FUNCS
    do
		cat <<EOF4
    .gd_${j} = ${i}_${j},
EOF4
    done

    cat <<EOF5
}; /* drv_class */
/* EOF */
EOF5
    ) >gendoc-$i.c
done
