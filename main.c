#include <stdio.h>

extern int add(int a, int b);

int main() {
  printf("add(3, 6) = %d\n", add(3, 6));
  return 0;
}
