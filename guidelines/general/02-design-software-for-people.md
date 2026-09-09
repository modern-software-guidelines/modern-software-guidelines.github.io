---
layout: default
title: "2. Design software for people"
---

# 2. Design software for people

## 2.1 Make common tasks clear

Present the information and controls people need for the task at hand. Explain
errors in terms that help them recover.

### Rationale

Software that is technically correct but hard to use shifts cost and risk onto
its users and those who must support it.

### Example

When a form rejects a date, identify the field and show the accepted format
instead of only displaying "invalid input.""

## 2.2 Include people with different access needs

Support keyboard operation, meaningful labels, understandable feedback, and
appropriate contrast in interfaces people use.

### Rationale

Accessibility improves access for disabled people and makes the interface more
robust for everyone using different devices and conditions.

### Example

Give an icon-only button an accessible name, make it reachable by keyboard, and
move focus to a useful place when it opens a dialog.

## 2.3 Treat user feedback as suggestions, not instructions

Take user feedback seriously, especially when it identifies pain points,
confusion, missing capabilities, or unexpected behaviour. However, do not
assume that the user's proposed solution is necessarily the right one.
Understand the underlying need first, then choose a solution consistent with
the product's architecture, design principles, and the needs of other users.

## Rationale

Users have first-hand knowledge of the problems they encounter, but usually
only partial knowledge of the constraints and trade-offs involved in solving
them. A feature request often describes one possible solution to a real
problem rather than the problem itself.

Blindly implementing requested solutions can produce unnecessary complexity,
inconsistent behavior, overlapping features, or designs optimized for a single
workflow. Conversely, dismissing feedback because the suggested implementation
is unsuitable risks ignoring valuable evidence that something is wrong.

The goal is to identify the need behind the feedback and address that need
appropriately.

## Example

A user requests a new configuration option that disables an inconvenient behaviour.

**Don't**: Immediately add the option because it solves the user's reported problem.

**Do**: Investigate why the behavior is inconvenient. If it is undesirable for
most users, change the default behaviour. If different workflows require
different behavior, a configuration option may be appropriate. If the problem
results from a bug or confusing interface, fix that instead.

The user's suggestion may ultimately be the right solution, but it should be
adopted because it is the right solution, not necessarily because it was
requested.
