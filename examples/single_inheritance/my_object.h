#include "smallpp/object.h"

struct my_object;

struct my_object_vtable {
    struct spp_object_vtable super;
    int (*calculate)(struct my_object *);
};

int my_object_calculate(struct my_object *self);

struct my_object *my_object_create(int val);
