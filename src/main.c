#include "engine.h"
#include "std__types.h"
#include <stdio.h>
#include <stdlib.h>

const extern int worldMap[24][24];

int main(int argc, t_const_string argv[]) {
  (void)argc;
  (void)argv;
  t_engine engine;

  engine__init(&engine);
  engine__run(&engine);
  return (0);
}
