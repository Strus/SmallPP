#ifndef TYPE_H
#define TYPE_H

#define SPP_TYPE_MAX_LENGTH 30

/**
 * Represent type.
 */
struct spp_type {
    struct spp_type *super;
    char name[SPP_TYPE_MAX_LENGTH + 1];
};

const char *spp_type_get_name(struct spp_type *type);

#endif // !TYPE_H
