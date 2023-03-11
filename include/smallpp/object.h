#ifndef OBJECT_H
#define OBJECT_H

struct spp_object {
    void *vtable;
};

struct spp_object_vtable {
    void (*destroy)(struct spp_object *);
    unsigned long (*hash)(struct spp_object *);
};

void spp_object_destroy(struct spp_object *self);

unsigned long spp_object_hash(struct spp_object *self);

void spp_object_init(struct spp_object *self);

#endif // OBJECT_H
