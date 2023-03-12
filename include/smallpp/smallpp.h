#ifndef SMALL_PP_H
#define SMALL_PP_H

#include <stdbool.h>
#include <stdlib.h>

#include "object.h"

/**
 * Initialize object vtable.
 *
 * Allocate memory for the vtable structure and copy all not implemented
 * super class function pointers.
 *
 * @param self
 * @param vtable     vtable object, should already contain all function pointers
 *                   and have functions that should be inherited pointing to NULL
 * @param super_type name of the super type
 */
#define spp_init_vtable(self, vtable, super_type)                                                                      \
    size_t methods_count = sizeof(struct super_type##_vtable) / sizeof(void *);                                        \
    for (size_t i = 0; i < methods_count; i++) {                                                                       \
        if (!((void **)(&(vtable)))[i]) {                                                                              \
            ((void **)(&(vtable)))[i] = ((void **)(((struct spp_object *)self)->vtable))[i];                           \
        }                                                                                                              \
    }                                                                                                                  \
    ((struct spp_object *)self)->vtable = (void *)&vtable;

/**
 * Call virtual method.
 */
#define spp_vcall(type, object, func, ...)                                                                             \
    ((struct type##_vtable *)((struct spp_object *)object)->vtable)->func((struct type *)object, ##__VA_ARGS__)

/**
 * Helper macro for object create boilerplate.
 *
 * Allocates memory for the given struct and call object init.
 */
#define spp_create(type, ...)                                                                                          \
    malloc(sizeof(struct type));                                                                                       \
    type##_init(self, ##__VA_ARGS__);

bool spp_isinstance(spp_object self, struct spp_type const *type);

#endif // SMALL_PP_H
