---
layout: default
title: "3. Build and maintain responsibly"
---

# 3. Build and maintain responsibly

## 3.1 Prefer standard algorithms and established solutions

Established, proven solutions should be preferred unless the problem domain
requires something novel.

### Rationale

Standard solutions are usually better understood, better tested, easier to
maintain, and less surprising to future developers. Custom algorithms introduce
additional complexity and risk that must be justified by a concrete
requirement.

### Example

Using the standard library sort over a custom sort, unless profiling justifies
a different sort and the trade-offs are known.

## 3.2 Keep changes small and explainable

Use the simplest design that meets the need. Follow established project patterns
where they fit, and record decisions whose trade-offs are not obvious.

### Rationale

Focused changes are easier to review, test, revert, and maintain. Clear design
decisions prevent later maintainers from repeating expensive investigation.

### Example

Add a focused validation function at an existing input boundary instead of
duplicating validation across every consumer of the value.

## 3.3 Protect data and permissions

Validate external input, enforce authorization explicitly, and collect and keep
only the data needed for the purpose.

### Rationale

Sensitive data and authority are difficult to recover once exposed. Treating
boundaries deliberately reduces security and privacy failures.

### Example

Check that the current account owns a requested record on the server; do not
rely on a hidden client-side control to enforce that rule.

## 3.4 Verify important behavior

Review meaningful changes and exercise their intended outcomes, failure paths,
and compatibility requirements before release.

### Rationale

Tests and review are evidence about behavior. They are most useful when they
cover the consequences people depend on rather than only internal details.

### Example

For a password reset, test a successful reset, an expired link, an attempt to
reuse a link, and that a reset does not expose whether an email address exists.
