#include <stdio.h>
#include <string.h>

#include "my_object.h"
#include "smallpp/smallpp.h"

int main() {
    struct my_object *obj = my_object_create(5);
    printf("%d (expected 10)\n", spp_vcall(my_object, obj, calculate));
    printf("%lu (expected %lu)\n", spp_vcall(spp_object, obj, hash), (unsigned long)obj);

    spp_vcall(spp_object, obj, destroy);
    return 0;
}
