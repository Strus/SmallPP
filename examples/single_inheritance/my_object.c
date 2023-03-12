#include <stdio.h>
#include <string.h>

#include "my_object.h"
#include "smallpp/object.h"
#include "smallpp/smallpp.h"

struct my_object {
    struct spp_object super;

    int *array;
    int len;
};

void my_object_destroy(spp_object super) {
    my_object self = (my_object)super;
    free(self->array);
}

int my_object_calculate(my_object self) {
    return self->len * 2;
}

spp_type my_object_type() {
    static spp_type type = NULL;
    if (type) {
        return type;
    }

    spp_type_init(&type, spp_object_type(), "my_object");

    return type;
}

void my_object_init(my_object self, int val) {
    spp_object_init(&self->super, my_object_type());

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

my_object my_object_create(int val) {
    my_object self = spp_create(my_object, val);
    return self;
}
