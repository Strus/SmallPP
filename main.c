#include <stdio.h>
#include <stdlib.h>

struct spp_object {
  void *vtable;
};

struct spp_object_vtable {
  void (*destroy)(struct spp_object *);
};

void spp_object_destroy(struct spp_object *self);

struct spp_object *spp_object_create() {
  struct spp_object *self = malloc(sizeof(struct spp_object));

  static const struct spp_object_vtable vtable = {
      .destroy = spp_object_destroy,
  };
  self->vtable = (void *)&vtable;

  return self;
}

void spp_object_destroy(struct spp_object *self) { free(self); }

#define spp_vcall(type, object, func, ...)                                     \
  ((struct type##_vtable *)((struct type *)object)->super.vtable)              \
      ->func((struct type *)object, ##__VA_ARGS__)

// ###########################################

struct my_object {
  struct spp_object super;
  int some_value;
};

struct my_object_vtable {
  struct spp_object_vtable super;
  void (*describe)(struct my_object *);
};

void my_object_describe(struct my_object *self) {
  printf("This is my object some_value: %d\n", self->some_value);
}

struct my_object *my_object_create(int val) {
  struct my_object *self = malloc(sizeof(struct my_object));
  self->super = *spp_object_create();

  static const struct my_object_vtable vtable = {
      .super =
          {
              .destroy = spp_object_destroy,
          },
      .describe = my_object_describe,
  };
  self->super.vtable = (void *)&vtable;

  self->some_value = val;

  return self;
}

// ###########################################

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

// ###########################################

int main() {
  struct my_object *obj = my_object_create(5);
  struct my_object_derived *obj_derived = my_object_derived_create(5, 10);

  spp_vcall(my_object, obj, describe);
  spp_vcall(my_object, obj_derived, describe);

  free(obj);
  return 0;
}
