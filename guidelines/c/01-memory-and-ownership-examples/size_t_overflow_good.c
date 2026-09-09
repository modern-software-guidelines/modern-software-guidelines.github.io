
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  size_t some_other_size;
  size_t wont_overflow_size;
  size_t req_size;

  req_size = 6;
  some_other_size = SIZE_MAX - (req_size - 1);
  wont_overflow_size = SIZE_MAX - req_size;

  printf("req_size before overflow addition: %lu\n", req_size);
  printf("SIZE_MAX = %lu\n", SIZE_MAX);

  if ((SIZE_MAX - some_other_size) >= req_size) {
    // NOTE: the way this works is that SIZE_MAX is
    // the point at which things overflow; if 
    // SIZE_MAX - addend is *less than* the base
    // you're adding to, that means you are *going to*
    // overflow if you actually do that addition. 
    req_size += some_other_size;
  } else {
    printf("req_size overflow (1)! not adding!\n");
  }

  if ((SIZE_MAX - wont_overflow_size) >= req_size) {
    req_size += wont_overflow_size;
  } else {
    printf("req_size overflow (2)! not adding!\n");
  }

  printf("req_size after overflow addition: %lu\n", req_size);
}
