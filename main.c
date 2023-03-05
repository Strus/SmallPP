#include <stdio.h>
#include <stdlib.h>
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
void my_object_temp(struct spp_object *self) {}

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

#if 0
struct my_object_derived {
  struct my_object super;
  int some_other_value;
};

void my_object_derived_describe(struct my_object *self) {
  printf("This is my object some_value, but different: %d\n",
         self->some_value * 3);
}

struct my_object_derived *my_object_derived_create(int val, int other_val) {
  struct my_object_derived *self = malloc(sizeof(struct my_object_derived));
  self->super = *my_object_create(val);

  static const struct my_object_vtable vtable = {
      .super =
          {
              .destroy = spp_object_destroy,
          },
      .describe = my_object_derived_describe,
  };
  self->super.super.vtable = (void *)&vtable;

  self->some_other_value = other_val;

  return self;
}
#endif
