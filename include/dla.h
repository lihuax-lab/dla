#ifndef DLA_H
#define DLA_H

#include "header.h"

// 粒子结构
typedef struct {
  int x, y;
} Particle;

// 函数声明
void init_grid();
Particle generate_particle();
void walk_particle(Particle *p);
void print_grid();

#endif // DLA_H
