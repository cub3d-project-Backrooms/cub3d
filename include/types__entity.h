#ifndef TYPES__ENTITY_H
#define TYPES__ENTITY_H

#include "std__types__math.h"

typedef struct s_entity {
  t_vec pos;
  double move_speed;
  double rot_speed;
} t_entity;

#endif
