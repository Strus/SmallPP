#include <stdlib.h>

struct spp_object {
    void *vtable;
};

struct spp_object_vtable {
    void (*destroy)(struct spp_object *);
    int (*hash)(struct spp_object *);
};

void spp_object_destroy(struct spp_object *self) {
    free(self);
}
int spp_object_hash(struct spp_object *self) {
    return 0;
}

struct spp_object *spp_object_create() {
    struct spp_object *self = malloc(sizeof(struct spp_object));

    static const struct spp_object_vtable vtable = {
        .destroy = spp_object_destroy,
        .hash = spp_object_hash,
    };
    self->vtable = (void *)&vtable;

    return self;
}

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
