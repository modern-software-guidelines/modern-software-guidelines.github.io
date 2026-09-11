---
layout: default
title: "C 1. Memory and ownership"
---

# 1. Memory and ownership

## 1.1 Make ownership explicit

For every allocated resource, make it clear which code owns it, how ownership
is transferred, and which function releases it.

### Rationale

C does not enforce ownership. Making it part of the interface prevents leaks,
double frees, and use after free errors.

### Example

Document whether `widget_create` returns an owned `Widget *`, and provide one
matching `widget_destroy` function. Do not make callers infer ownership from a
parameter name.

## 1.2 Check sizes and results at boundaries

Validate lengths before arithmetic or allocation, and check functions that can
fail before using their result.

### Rationale

Unchecked integer conversion, arithmetic, and failed allocation can become
memory-safety or reliability failures.

### Example

Before adding a header length to a payload length, reject values that would
overflow `size_t`; only allocate after the checked total is known.

#### Bad

```c

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
```

#### Good

```c
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
```

## 1.3 Use "array index" syntax form rather than raw pointer arithmetic when dereferencing

Instead of `*(my_pointer+3)`, use `my_pointer[3]`. 

### Rationale

The actual arithmetic behind `my_pointer+3` when broken down to raw 
numbers works out to `my_pointer+(sizeof(*my_pointer)*3)`. 
This is _surprising_, especially to newcomers. As it turns out, array 
index access does basically the same thing (including the dereference), 
but doesn't quietly rewrite an entire addend in the process.

### Example

#### Bad

`*(my_pointer+3)`

#### Good

`my_pointer[3]`

#### Exception

`my_pointer+3` if you're calculating an address with an offset
and intend to use the resulting calculation later -- for instance
if you're intending to only write _part_ of a buffer to a
file, like so:

```c
const char *msg = "hello world";
write(1, msg+6, 5); // write "world" to stdout
```
