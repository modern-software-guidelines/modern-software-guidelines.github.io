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

See also the `size_t_*.c` examples in 01-memory-and-ownership/ .

## 1.3 Use "array index" syntax form rather than raw pointer arithmetic when dereferencing

Instead of `*(my_pointer+3)`, use `my_pointer[3]`. 

### Rationale

The actual arithmetic behind `my_pointer+3` when broken down to raw 
numbers works out to something more like 
`my_pointer+(sizeof(*my_pointer)*3)`. This is _surprising as hell_,
especially to newcomers. As it turns out, array index access does
basically the same thing (including the dereference), but doesn't
quietly rewrite an entire addend in the process.

### Example

#### Bad

`*(my_pointer+3)`

#### Good

`my_pointer[3]`

#### Exception

`my_pointer+3` _only_ if you're storing that address in
particular and not immediately dereferencing it. This tends
to be pretty rare, but 
