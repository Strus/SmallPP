#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "smallpp/type.h"

struct spp_type {
    struct spp_type *super;
    char name[SPP_TYPE_MAX_LENGTH + 1];
};

spp_type spp_type_get_super(spp_type type) {
    return type->super;
}

const char *spp_type_get_name(spp_type type) {
    return type->name;
}

void spp_type_init(spp_type *type, spp_type super_type, const char *name) {
    assert(name && "name cannot be NULL");

    *type = malloc(sizeof(struct spp_type));
    (*type)->super = super_type;
    strncpy((*type)->name, name, SPP_TYPE_MAX_LENGTH);
}
