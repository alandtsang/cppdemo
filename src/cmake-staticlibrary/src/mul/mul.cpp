#include "mul.h"
#include "add/add.h"

int mul(int x, int y) {
  int result = 0;

  for (int i = 0; i < x; i++) {
    result = add(result, y);
  }
  return result;
}
