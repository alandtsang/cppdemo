#include <ctime>
#include <cstdlib>
#include "utils.h"

int GetRandomNum(int range, int start) {
  if (range - start <= 0) {
    return 0;
  }
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  std::srand((time_t) ts.tv_nsec);
  return std::rand() % (range - start) + start;
}
