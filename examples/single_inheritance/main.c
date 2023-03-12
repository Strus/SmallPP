#include <stdio.h>
#include <string.h>

#include "my_object.h"
#include "smallpp/smallpp.h"

int main() {
    struct my_object *obj = my_object_create(5);
    // printf("%s (expected \"my_object\")\n", spp_vcall(spp_object, obj, get_type));
    printf("%d (expected 10)\n", spp_vcall(my_object, obj, calculate));
    printf("%lu (expected %lu)\n", spp_vcall(spp_object, obj, hash), (unsigned long)obj);
    printf("%d (expected 1)\n", spp_isinstance((struct spp_object *)obj, my_object_type()));
    printf("%d (expected 1)\n", spp_isinstance((struct spp_object *)obj, spp_object_type()));

    spp_vcall(spp_object, obj, destroy);
    return 0;
}
