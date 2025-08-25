#ifndef DLA_H
#define DLA_H

// 粒子结构
typedef struct {
  int x, y;
} Particle;

// 函数声明
void init_grid(void);
Particle generate_particle(void);
void walk_particle(Particle *p);
void print_grid(void);

#endif // DLA_H
