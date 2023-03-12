#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smallpp/type.h"

const char *spp_type_get_name(struct spp_type *type) {
    return type->name;
}

void spp_type_init(struct spp_type **type, struct spp_type *super_type, const char *name) {
    assert(super_type && "super_type cannot be NULL");
    assert(name && "name cannot be NULL");

    *type = malloc(sizeof(struct spp_type));
    (*type)->super = super_type;
    strncpy((*type)->name, name, SPP_TYPE_MAX_LENGTH);
}
