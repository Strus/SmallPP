#include <stdio.h>
#include <string.h>

#include "smallpp/object.h"
#include "smallpp/smallpp.h"
#include "smallpp/type.h"

bool spp_isinstance(struct spp_object *self, struct spp_type const *type) {
    if (!self || !type) {
        return false;
    }

    if (self->type == type) {
        return true;
    }

    struct spp_type *super = spp_type_get_super(self->type);
    while (super) {
        if (super == type) {
            return true;
        }

        super = spp_type_get_super(super);
    }

    return false;
}
