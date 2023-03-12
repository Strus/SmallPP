#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smallpp/object.h"

void spp_object_destroy(struct spp_object *self) {
    free(self);
}

unsigned long spp_object_hash(struct spp_object *self) {
    return (unsigned long)self;
}

struct spp_type *spp_object_type() {
    static struct spp_type *type = NULL;
    if (type) {
        return type;
    }

    type = malloc(sizeof(struct spp_type));
    type->super = NULL;
    strncpy(type->name, "spp_object", SPP_TYPE_MAX_LENGTH);

    return type;
}

void spp_object_init(struct spp_object *self, struct spp_type *type) {
    static const struct spp_object_vtable vtable = {
        .destroy = spp_object_destroy,
        .hash = spp_object_hash,
    };
    self->vtable = (void *)&vtable;
    self->type = type;
}
