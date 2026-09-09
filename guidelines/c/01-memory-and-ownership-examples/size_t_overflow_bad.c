
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  size_t some_other_size;
  size_t req_size;

  some_other_size = SIZE_MAX-5;
  req_size = 6;

  printf("req_size before overflow addition: %lu\n", req_size);

  req_size += some_other_size;

  printf("req_size after overflow addition: %lu\n", req_size);
}
