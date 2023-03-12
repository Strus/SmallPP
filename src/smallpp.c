#include "smallpp/smallpp.h"
#include "smallpp/object.h"
#include <stdio.h>
#include <string.h>

bool spp_isinstance(struct spp_object *self, struct spp_type const *type) {
    if (!self || !type) {
        return false;
    }

    if (self->type == type) {
        return true;
    }

    struct spp_type *super = self->type->super;
    while (super) {
        if (super == type) {
            return true;
        }

        super = self->type->super;
    }

    return false;
}
