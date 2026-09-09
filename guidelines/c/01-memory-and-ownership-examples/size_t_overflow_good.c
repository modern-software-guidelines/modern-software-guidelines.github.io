
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  size_t someOtherSize;
  size_t wontOverflowSize;
  size_t reqSize;

  reqSize = 6;
  someOtherSize = SIZE_MAX - (reqSize - 1);
  wontOverflowSize = SIZE_MAX - reqSize;

  printf("reqSize before overflow addition: %lu\n", reqSize);
  printf("SIZE_MAX = %lu\n", SIZE_MAX);

  if ((SIZE_MAX - someOtherSize) >= reqSize) {
    // NOTE: the way this works is that SIZE_MAX is
    // the point at which things overflow; if 
    // SIZE_MAX - addend is *less than* the base
    // you're adding to, that means you are *going to*
    // overflow if you actually do that addition. 
    reqSize += someOtherSize;
  } else {
    printf("reqSize overflow (1)! not adding!\n");
  }

  if ((SIZE_MAX - wontOverflowSize) >= reqSize) {
    reqSize += wontOverflowSize;
  } else {
    printf("reqSize overflow (2)! not adding!\n");
  }

  printf("reqSize after overflow addition: %lu\n", reqSize);
}
