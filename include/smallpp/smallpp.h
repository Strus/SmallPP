#ifndef SMALL_PP_H
#define SMALL_PP_H

#include <stdlib.h>

#define spp_init_vtable(self, vtable, super_type)                                                                      \
    size_t methods_count = sizeof(struct super_type##_vtable) / sizeof(void *);                                        \
    for (size_t i = 0; i < methods_count; i++) {                                                                       \
        if (!((void **)(&(vtable)))[i]) {                                                                              \
            ((void **)(&(vtable)))[i] = ((void **)(((struct spp_object *)self)->vtable))[i];                           \
        }                                                                                                              \
    }                                                                                                                  \
    ((struct spp_object *)self)->vtable = (void *)&vtable;

#define spp_vcall(type, object, func, ...)                                                                             \
    ((struct type##_vtable *)((struct spp_object *)object)->vtable)->func((struct type *)object, ##__VA_ARGS__)

#define spp_create(type, ...)                                                                                          \
    malloc(sizeof(struct type));                                                                                       \
    type##_init(self, ##__VA_ARGS__);

#endif // SMALL_PP_H
