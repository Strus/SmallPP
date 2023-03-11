#include "smallpp/object.h"
#include "smallpp/smallpp.h"

struct my_object {
    struct spp_object super;
    int *array;
    int len;
};

struct my_object_vtable {
    struct spp_object_vtable super;
    int (*calculate)(struct my_object *);
};

void my_object_destroy(struct spp_object *super) {
    struct my_object *self = (struct my_object *)super;
    free(self->array);
}

int my_object_calculate(struct my_object *self) {
    return self->len * 2;
}

void my_object_init(struct my_object *self, int val) {
    spp_object_init(&self->super);

    static struct my_object_vtable vtable = {
        .super =
            {
                .destroy = my_object_destroy,
            },
        .calculate = my_object_calculate,
    };
    spp_init_vtable(self, vtable, spp_object);

    self->array = malloc(sizeof(int) * val);
    self->len = val;
}

struct my_object *my_object_create(int val) {
    struct my_object *self = spp_create(my_object, val);
    return self;
}
