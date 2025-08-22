#include "../include/dla.h"

// 定义网格，0 表示空，1 表示粒子
int grid[GRID_SIZE][GRID_SIZE] = {0};

// 初始化中心种子
void init_grid() { grid[GRID_SIZE / 2][GRID_SIZE / 2] = 1; }

// 检查粒子是否在边界外
int is_out_of_bounds(int x, int y) {
  return x < 0 || y < 0 || x >= GRID_SIZE || y >= GRID_SIZE;
}

// 检查粒子是否与现有粒子接触
int is_touching_particle(int x, int y) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // 仅当邻居位置在网格内时才检查粒子状态
    if (!is_out_of_bounds(nx, ny) && grid[nx][ny] == 1) {
      return 1;
    }
  }
  return 0;
}

// 随机生成粒子的初始位置
Particle generate_particle() {
  Particle p;
  int edge = rand() % 4; // 随机选择边界
  if (edge == 0) {       // 上边
    p.x = rand() % GRID_SIZE;
    p.y = 0;
  } else if (edge == 1) { // 右边
    p.x = GRID_SIZE - 1;
    p.y = rand() % GRID_SIZE;
  } else if (edge == 2) { // 下边
    p.x = rand() % GRID_SIZE;
    p.y = GRID_SIZE - 1;
  } else { // 左边
    p.x = 0;
    p.y = rand() % GRID_SIZE;
  }
  return p;
}

// 粒子的随机行走模拟
void walk_particle(Particle *p) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int step = 0; step < WALK_STEPS; step++) {
    int direction = rand() % 4; // 随机方向
    p->x += dx[direction];
    p->y += dy[direction];

    // 如果粒子超出边界，返回到起点
    if (is_out_of_bounds(p->x, p->y)) {
      *p = generate_particle();
    }

    // 如果粒子接触现有粒子
    /* if (is_touching_particle(p->x, p->y)) { */
    /* if (!is_out_of_bounds(p->x, p->y) && is_touching_particle(p->x, p->y)) {
      double chance = (double)rand() / RAND_MAX;
      if (chance <= ATTACH_PROB) { // 以一定概率吸附
        grid[p->x][p->y] = 1;

        // 复制产生一个新粒子
        Particle new_particle = generate_particle();
        walk_particle(&new_particle);

        return; // 当前粒子固定后退出
      } */
    if (!is_out_of_bounds(p->x, p->y) && is_touching_particle(p->x, p->y)) {
      double chance = (double)rand() / RAND_MAX;
      if (chance <= ATTACH_PROB) { // 以一定概率吸附
        grid[p->x][p->y] = 1;
        return; // 当前粒子固定后退出
      }
    }
  }
}

// 打印网格
void print_grid() {
  for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
      printf(grid[x][y] ? "#" : ".");
    }
    printf("\n");
  }
}
