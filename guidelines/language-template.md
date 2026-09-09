---
layout: default
title: Language set template
---

# Language set template

Create `guidelines/<language>/index.md`, copy this structure into it, and add
numbered section files beside it. Link to the general set and describe only the
guidance that is meaningfully specific to the language.

```markdown
---
layout: default
title: <Language> guidelines
---

# <Language> guidelines

Read the [general guidelines](/guidelines/general/) first. These pages add
guidance that is specific to <Language>.

## Sections

1. [Section title](/guidelines/<language>/01-section-title/)
```

Use the [section template]({{ '/guidelines/section-template/' | relative_url }})
for each numbered section.
