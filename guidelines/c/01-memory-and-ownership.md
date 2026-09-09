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
