#ifndef OBJECT_H
#define OBJECT_H

#include "smallpp/type.h"

/**
 * Base object.
 *
 * Every custom object should inherit from it.
 */
struct spp_object {
    spp_type type;
    void *vtable;
};
typedef struct spp_object *spp_object;

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
    void (*destroy)(spp_object);

    /**
     * Calculate hash.
     */
    unsigned long (*hash)(spp_object);
};

/**
 * Destructor.
 */
void spp_object_destroy(spp_object self);

/**
 * Calculate hash.
 */
unsigned long spp_object_hash(spp_object self);

/**
 * Get type.
 */
spp_type spp_object_type();

/**
 * Initializer.
 *
 * Should be called in custom object constructor.
 */
void spp_object_init(spp_object self, spp_type type);

#endif // OBJECT_H
