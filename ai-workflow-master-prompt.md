# AI Code Editor Workflow Master Prompt

When you start work in a new project, paste the contents of this file at the top of your prompt. It tells you exactly how to build, commit, document, and ship the project.

---

## 1. Codebase Analysis (Do This First)

Before writing **or changing** any code:

1. Read every file in the working directory.
2. Understand the project structure, purpose, and language.
3. Find the base file and the target/final file if they exist.
4. If asked to simplify or rewrite: make the code look like a **second-year engineering student** wrote it. That means:
   - Fewer functions (merge small helpers into larger ones).
   - Simpler logic.
   - Names that make sense (`i`, `j`, `temp`, `arr` — not `partitionOrchestrator`).
   - No advanced patterns, macros, or "clever" tricks.
   - Enough comments to explain what is happening, but not so many that it looks AI-generated.
   - Code that fits on one screen page when possible.

---

## 2. Git Commit Strategy

### Commit Tags (Always CAPS + colon)

| Tag | When to use |
|-----|-------------|
| `INIT:` | First commit / project boilerplate |
| `FEAT:` | New feature or function added |
| `REFACTOR:` | Code cleanup, rename, restructure (no behavior change) |
| `FIX:` | Fix a non-critical error |
| `BUG:` | Fix a logic bug that changes behavior |
| `DOCS:` | README, comments, documentation |
| `CHORE:` | Housekeeping (remove files, etc.) |
| `ASSETS:` | Screenshots, images, media |
| `UI:` | Formatting, menu layout, visual changes |

### Rules

- Make **small, incremental commits**. 3–6 per feature is ideal. 10–15 total for a student project is fine.
- Each commit should be a logical unit of work.
- Use **present tense** in commit messages: `FEAT: add recursion depth counter`, not `added` or `adds`.
- Push frequently: `git add . && git commit -m "..." && git push`

---

## 3. Branching & Pull Request Strategy

Use the main branch (`master`) for a linear history. It is simpler for a college project.

If branching is required, follow this pattern:

```bash
# 1. Make sure you are on master and up to date
git checkout master
git pull origin master

# 2. Create a feature branch
git checkout -b feature/add-<feature-name>

# 3. Do work, commit incrementally
git add .
git commit -m "FEAT: description here"
git push -u origin feature/add-<feature-name>

# 4. Create the Pull Request
gh pr create --base master --fill

# 5. Merge and clean up
git checkout master
git merge --no-ff feature/add-<feature-name>
git push origin master
git branch -d feature/add-<feature-name>
```

**Minimum requirement:** At least 1 Pull Request must be created using `gh pr create`.

---

## 4. GitHub Repository Creation

Use the `gh` CLI:

```bash
gh auth login              # Only if not already logged in
gh repo create <repo-name> --public --source=. --remote=origin --push \
    --description "<short description>"
```

### Repo Naming

- Lowercase, hyphen-separated.
- Max 3-4 words.
- Must clearly describe what the program does.
- Examples:
  - `quicksort-analyzer-dsa`
  - `student-record-sorter`
  - `aoa-minishell`
  - `c-algorithm-viz`

---

## 5. Adding Collaborators

After creating the repo, add collaborators with push access:

```bash
gh api -X PUT /repos/<owner>/<repo-name>/collaborators/<github-username> \
    -f permission=push
```

Example:

```bash
gh api -X PUT /repos/DevInfinix/quicksort-analyzer-dsa/collaborators/cmrittikaoli-ux \
    -f permission=push
```

Repeat for each collaborator. They will get an email invite.

---

## 6. README.md Style Guide

The README must look like a real project, not AI-generated. Follow this exact structure:

### Header (Centered)

```markdown
<div align="center">

# <Project Name>

<One-line subtitle that a human would actually write. No "transformative framework" nonsense.>

[![Language](https://img.shields.io/badge/Language-...-...&style=for-the-badge)](...)
[![Stars](https://img.shields.io/github/stars/.../...?style=for-the-badge&color=gold)](...)
[![Forks](https://img.shields.io/github/forks/.../...?style=for-the-badge&color=blue)](...)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<br/>

**<One honest sentence describing what it does.>**

[Features](#features) • [How It Works](#how-it-works) • [Quick Start](#quick-start) • [Contributors](#contributors)

</div>
```

### Body Sections (in order)

1. **Why This Exists** — 1–2 short paragraphs. "In our Algorithms class, we..." — honest, no marketing speak.
2. **Features** — 4–8 bullet points. Short. No jargon. "Add student records", "Sort by marks ascending/descending", etc.
3. **How It Works** — Plain English explanation + a simple code block example (not mermaid unless necessary). Show the actual algorithm step by step with a small example.
4. **Demo** — Screenshots in a grid. 2-column table if you have 4 screenshots:

   ```markdown
   | 1. Add Records | 2. View Records |
   | :---: | :---: |
   | <img src="assets/screenshots/01.png" width="100%"/> | <img src="assets/screenshots/02.png" width="100%"/> |
   | *Caption* | *Caption* |
   ```

5. **Quick Start** — Compile + run commands. Include `git clone`, `gcc`, and execution steps.

   ```bash
   git clone https://github.com/<owner>/<repo>.git
   cd <repo>
   gcc -Wall -Wextra <file>.c -o <binary>
   ./<binary>
   ```

6. **Analysis Report / Metrics** — Show example output from the program and explain what each line means.
7. **Repository Structure** — Simple tree:

   ```
   repo-name/
   ├── assets/
   │   └── screenshots/
   ├── .gitignore
   ├── LICENSE
   ├── README.md
   └── <main-file>.c
   ```

8. **Contributors** — HTML table with GitHub avatars + names (see template below).
9. **License** — "MIT — use for any academic work."

### Contributors Table Template

```html
<div align="center">
<table>
  <tr>
    <td align="center" width="25%">
      <a href="https://github.com/<username>">
        <img src="https://github.com/<username>.png" width="90px;" alt="<username>"/><br />
        <sub><b><username></b></sub>
      </a><br />
      <sub><role></sub>
    </td>
    <!-- Repeat <td> for each contributor -->
  </tr>
</table>
</div>
```

---

## 7. Screenshot Generation Protocol

If you have a real program that can run, you **must** try to capture real terminal output. Here is the priority order:

### Option A: Real Screenshot (Best)
1. Compile the program: `gcc -Wall quicksort_records.c -o quicksort_records`
2. Run it and capture the screen (PrtScn or OS screenshot tool).
3. Crop to the terminal window.
4. Save as `assets/screenshots/<number>_<name>.png`.

### Option B: Generated Terminal Screenshot (Fallback)
If running a screenshot tool is not possible, generate a high-quality PNG programmatically using Python + PIL:

```python
from PIL import Image, ImageDraw, ImageFont

# 1. Create image with dark background (#181a1f or Catppuccin Mocha)
# 2. Add rounded corners (radius=12), 1px border
# 3. Add macOS-style title bar with red/yellow/green dots on the left
# 4. Title = program name or tab name
# 5. Use monospace font (consola.ttf on Windows)
# 6. Color the text:
#    - Shell prompts ($): green
#    - Headers: blue/gray
#    - User input: yellow
#    - Code/data: light gray
# 7. Save as PNG to assets/screenshots/
```

Save a Python script as `generate_screenshots.py`, run it, then **delete** the script after.

File naming:
- `01_main_menu.png`
- `02_display_records.png`
- `03_sorting_partition.png`
- `04_analysis_report.png`

Commit screenshots in an `ASSETS:` commit **before** the README commit.

---

## 8. .gitignore Template

Always start your project with a `.gitignore`:

```
# Compiled
*.exe
*.o
*.out
*.obj

# IDE
.vscode/
.idea/
```

---

## 9. LICENSE File

Use MIT:

```
MIT License

Copyright (c) 2026 <Your Name / Team Name>, <Contributor1>, <Contributor2>, ...

Permission is hereby granted, free of charge, ...
```

Commit with `LICENSE:` tag.

---

## 10. Expected Commit History Order

Minimum 8 commits (10-15 is ideal):

1. `INIT:` — Base code + .gitignore
2. `REFACTOR:` — Simplify a function or rename variables
3. `FEAT:` — Add a feature (e.g., counter, new sort field)
4. `FEAT:` — Add another feature
5. `CHORE:` — Remove unused files (e.g., `FUTURE_SCOPE.md`)
6. `ASSETS:` — Add screenshots
7. `DOCS:` — Final README
8. `LICENSE:` — Add LICENSE (or combine with DOCS)
9. `MERGE:` — Merge PR (if branching was used)

---

## 11. Push Workflow

After final commit:

```bash
git add .
git commit -m "DOCS: final README update"
git push origin master
```

Verify the push:
```bash
git log --oneline
gh repo view  # Confirm repo exists and is public
```

---

## End of Master Prompt

When you are done with everything, report back with:

- ✅ Repository URL
- ✅ Total commit count and log
- ✅ Branch name and PR link (if applicable)
- ✅ Contributor list confirmed added
- ✅ README screenshot links verified

Then delete this master prompt file from the project directory.
