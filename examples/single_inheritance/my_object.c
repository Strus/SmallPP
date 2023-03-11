#include "smallpp/object.h"
#include "smallpp/smallpp.h"

struct my_object {
    struct spp_object super;
    int some_value;
};

struct my_object_vtable {
    struct spp_object_vtable super;
    int (*calculate)(struct my_object *);
};

int my_object_calculate(struct my_object *self) {
    return self->some_value * 2;
}

void my_object_init(struct my_object *self, int val) {
    spp_object_init(&self->super);

    static struct my_object_vtable vtable = {
        .calculate = my_object_calculate,
    };
    spp_init_vtable(self, vtable, spp_object);

    self->some_value = val;
}

struct my_object *my_object_create(int val) {
    struct my_object *self = spp_create(my_object, val);
    return self;
}
