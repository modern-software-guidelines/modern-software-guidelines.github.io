---
layout: default
title: "Rust 1. Ownership and errors"
---

# 1. Ownership and errors

## 1.1 Let types express valid states

Use Rust's types to represent required values, optional values, and recoverable
failure instead of relying on sentinel values or undocumented conventions.

### Rationale

Types make invalid states harder to construct and let the compiler help callers
handle the cases that matter.

### Example

Return `Result<Config, ConfigError>` when parsing configuration instead of a
partially initialized `Config` with a separate error flag.

## 1.2 Keep `unsafe` small and justified

Use safe Rust by default. When `unsafe` is necessary, isolate the smallest
possible block and document the invariants that make it sound.

### Rationale

`unsafe` moves memory-safety obligations from the compiler to the author and
reviewer. A narrow boundary makes those obligations inspectable and testable.

### Example

Put a foreign-function call in a small wrapper that checks pointer validity and
lengths, then expose a safe Rust interface to the rest of the application.

## 1.3 Isolate `unsafe` code where possible

When `unsafe` code is required, it should be isolated to a submodule or even
crate in the workspace.

### Rationale

Isolating `unsafe` code makes it easier to maintain, and prevents polluting the
main path with `unsafe` code.

### Example

Move an unsafe FFI in workspace `foo` into a `foo-ffi` crate.
