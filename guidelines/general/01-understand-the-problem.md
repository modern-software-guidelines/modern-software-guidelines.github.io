---
layout: default
title: "1. Understand the problem"
---

# 1. Understand the problem

## 1.1 Identify the people and outcome

Before choosing an implementation, describe who needs the change, what they are
trying to accomplish, and what outcome would show that it worked.

### Rationale

A clear outcome prevents a technically polished solution to the wrong problem.
It also gives reviewers and testers a shared basis for deciding whether the
work is complete.

### Example

Instead of “add search,” define: “A customer can find an order by its number and
see its current status without contacting support.”

## 1.2 Understand affected boundaries

Identify the data, interfaces, permissions, and systems that the change touches.

### Rationale

Many failures occur where one system, role, or trust level meets another.
Knowing the boundary early makes a safe design easier to choose.

### Example

For an uploaded file, determine who can upload it, where it is stored, who can
retrieve it, and how its type and size are validated.
