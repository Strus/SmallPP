#ifndef MY_OBJECT_H
#define MY_OBJECT_H

#include "smallpp/object.h"

struct my_object;
typedef struct my_object *my_object;

struct my_object_vtable {
    struct spp_object_vtable super;
    int (*calculate)(my_object);
};

spp_type my_object_type();

int my_object_calculate(my_object self);

my_object my_object_create(int val);

#endif // MY_OBJECT_H
