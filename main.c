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
  spp_init_vtable(self, vtable, spp_object);

  self->some_value = val;

  return self;
}

struct derived_object {
  struct my_object super;
  int different_value;
};

struct derived_object_vtable {
  struct my_object_vtable super;
  int (*get_different_value)(struct derived_object *);
};

int derived_object_calculate(struct my_object *self) {
  return self->some_value * ((struct derived_object *)self)->different_value;
}

int derived_object_get_different_value(struct derived_object *self) {
  return self->different_value;
}

struct derived_object *derived_object_create(int val, int val2) {
  struct derived_object *self = malloc(sizeof(struct derived_object));
  self->super = *my_object_create(val);

  static struct derived_object_vtable vtable = {
      .super =
          {
              .calculate = derived_object_calculate,
          },
      .get_different_value = derived_object_get_different_value,
  };
  spp_init_vtable(self, vtable, my_object);

  self->different_value = val2;

  return self;
}

int main() {
  struct my_object *obj = my_object_create(5);
  printf("%d\n", spp_vcall(my_object, obj, calculate));
  printf("%d\n", spp_vcall(spp_object, obj, hash));

  struct derived_object *der = derived_object_create(5, 3);
  printf("%d\n", spp_vcall(my_object, der, calculate));
  printf("%d\n", spp_vcall(derived_object, der, get_different_value));

  spp_vcall(spp_object, obj, destroy);
  return 0;
}
