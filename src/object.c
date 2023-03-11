#include <stdlib.h>

#include "smallpp/object.h"

void spp_object_destroy(struct spp_object *self) {
    free(self);
}

unsigned long spp_object_hash(struct spp_object *self) {
    return (unsigned long)self;
}

void spp_object_init(struct spp_object *self) {
    static const struct spp_object_vtable vtable = {
        .destroy = spp_object_destroy,
        .hash = spp_object_hash,
    };
    self->vtable = (void *)&vtable;
}
