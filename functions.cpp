#include "functions.h"


// Return the maximum between 2 int
int max2(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}


// Return the maximum between 3 int
int max3(int x, int y, int z) {
  return max2(x, max2(y, z));
}
