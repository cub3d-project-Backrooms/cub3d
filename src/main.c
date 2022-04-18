#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

const extern int worldMap[24][24];

int main(void) {
  t_engine engine;
  t_camera camera = {
      .pos = {12, 5},
      .dir = {-1, 0},
      .plane = {0, 0.66},
  };
  engine__init(&engine, camera);
  engine__run(&engine);
  return (0);
}
