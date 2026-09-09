---
layout: default
title: Guidelines for modern software authoring
---

# Guidelines for modern software authoring

Software earns trust when it is useful, understandable, easy and safe to alter,
and respectful of the people who depend on it. These guidelines are a compact
starting point for individuals, projects, and teams who want to develop good
habits.

They are principles to apply with judgment, not rules to follow mechanically.
The details of a medical device, a personal website, and a distributed database
will differ; the responsibility to understand consequences does not.

## What this is not

- A comprehensive guide to good software authoring
- An endorsement or admonition against LLMs; however; LLMs are prohibited from
  contributing to this project
- A comprehensive standard such as CERT, MISRA, or JSV-AF
- Guidelines for writing secure software

## Start here

- Start with the [general guidelines]({{ '/guidelines/general/' | relative_url }}), which apply regardless of language.
- Add language-specific guidance for [C]({{ '/guidelines/c/' | relative_url }}) or [Rust]({{ '/guidelines/rust/' | relative_url }}).
- Copy the [language-set template]({{ '/guidelines/language-template/' | relative_url }}) when adding another language, then use the [section template]({{ '/guidelines/section-template/' | relative_url }}) for its sections.

## How to contribute

Prefer specific, testable guidance. Explain the problem a recommendation solves,
and include an example when it would prevent a common misunderstanding. Keep
this site focused on durable practice rather than a particular framework or tool.

## Licensing

These guidelines are granted to the public domain under the
[CC0 Deed](https://creativecommons.org/publicdomain/zero/1.0/).
