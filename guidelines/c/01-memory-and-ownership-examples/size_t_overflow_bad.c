
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  size_t someOtherSize;
  size_t reqSize;

  someOtherSize = SIZE_MAX-5;
  reqSize = 6;

  printf("reqSize before overflow addition: %ld\n", reqSize);

  reqSize += someOtherSize;

  printf("reqSize after overflow addition: %ld\n", reqSize);
}
