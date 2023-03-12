#ifndef OBJECT_H
#define OBJECT_H

#include "smallpp/type.h"

/**
 * Base object.
 *
 * Every custom object should inherit from it.
 */
struct spp_object {
    struct spp_type *type;
    void *vtable;
};

/**
 * Base object vtable.
 *
 * Contains all object-common methods.
 */
struct spp_object_vtable {
    /**
     * Destructor.
     *
     * All memory should be freed inside it.
     * You need to manually call the super destructor in custom destructor.
     */
    void (*destroy)(struct spp_object *);

    /**
     * Calculate hash.
     */
    unsigned long (*hash)(struct spp_object *);
};

/**
 * Destructor.
 */
void spp_object_destroy(struct spp_object *self);

/**
 * Calculate hash.
 */
unsigned long spp_object_hash(struct spp_object *self);

/**
 * Get type.
 */
struct spp_type *spp_object_type();

/**
 * Initializer.
 *
 * Should be called in custom object constructor.
 */
void spp_object_init(struct spp_object *self, struct spp_type *type);

#endif // OBJECT_H
