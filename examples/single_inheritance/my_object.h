#ifndef MY_OBJECT_H
#define MY_OBJECT_H

#include "smallpp/object.h"

struct my_object;

struct my_object_vtable {
    struct spp_object_vtable super;
    int (*calculate)(struct my_object *);
};

struct spp_type *my_object_type();

int my_object_calculate(struct my_object *self);

struct my_object *my_object_create(int val);

#endif // MY_OBJECT_H
