#include <stdio.h>
#include <string.h>

#include "smallpp/object.h"

struct my_object {
  struct spp_object super;
  int some_value;
};

struct my_object_vtable {
  struct spp_object_vtable super;
  int (*calculate)(struct my_object *);
};

int my_object_calculate(struct my_object *self) { return self->some_value * 2; }

struct my_object *my_object_create(int val) {
  struct my_object *self = malloc(sizeof(struct my_object));
  self->super = *spp_object_create();

  static struct my_object_vtable vtable = {
      .calculate = my_object_calculate,
  };
  spp_init_vtable(self, vtable);

  self->some_value = val;

  return self;
}

int main() {
  struct my_object *obj = my_object_create(5);
  printf("%d\n", spp_vcall(my_object, obj, calculate));
  printf("%d\n", spp_vcall(spp_object, obj, hash));

  spp_vcall(spp_object, obj, destroy);
  return 0;
}
