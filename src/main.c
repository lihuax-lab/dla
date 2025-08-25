#include "../include/dla.h"
#include "../include/header.h"

int main(void) {
  srand(time(NULL));
  init_grid();

  for (int i = 0; i < MAX_PARTICLES; i++) {
    Particle p = generate_particle();
    walk_particle(&p);
  }

  print_grid();
  return EXIT_SUCCESS;
}
