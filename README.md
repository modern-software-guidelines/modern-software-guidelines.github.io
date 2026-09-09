# Modern Software Authoring Guidelines

A Markdown-first starter site for a concise, practical set of software-authoring
guidelines. It uses GitHub Pages' built-in Jekyll support, so publishing needs
no build service or generated files.

## Publish on GitHub Pages

1. Create a Git repository and push this directory to GitHub.
2. In the repository's **Settings → Pages**, choose **Deploy from a branch**.
3. Select the `main` branch and the `/ (root)` directory.
4. GitHub will publish the site at the URL it shows on that page.

Edit the Markdown files in `guidelines/` to evolve the content. Each language or
general set has its own directory, with numbered section files. The navigation
in `_config.yml` controls the site header.

```
guidelines/
  general/
    index.md
    01-understand-the-problem.md
    02-design-software-for-people.md
    03-build-and-maintain.md
  c/
    index.md
    01-memory-and-ownership.md
  rust/
    index.md
    01-ownership-and-errors.md
  language-template.md
  section-template.md
```

`general/` is the shared baseline. A language directory adds guidance particular
to that language; it should not repeat the general material. Each section
contains numbered items. An item can have numbered subitems, then a rationale
and a concrete example.

## Local preview (optional)

GitHub Pages builds the site automatically. To preview it locally, install Ruby
and Bundler, then run:

```sh
bundle install
bundle exec jekyll serve
```

Open `http://localhost:4000`.
