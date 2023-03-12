#ifndef TYPE_H
#define TYPE_H

#define SPP_TYPE_MAX_LENGTH 30

/**
 * Represent type.
 */
struct spp_type;
typedef struct spp_type *spp_type;

struct spp_type *spp_type_get_super(spp_type type);

/**
 * Get type name.
 */
const char *spp_type_get_name(spp_type type);

/**
 * Initalize type.
 *
 * @param type        type to initialize
 * @param super_type  super type (cannot be NULL)
 * @param name        type name (cannot be NULL)
 */
void spp_type_init(spp_type *type, spp_type super_type, const char *name);

#endif // !TYPE_H
