<div align="center">

# Quicksort Analyzer (DSA)

Sort student records with Quicksort — and watch the algorithm do its thing step by step.

[![Language](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![Course](https://img.shields.io/badge/Course-Analysis%20of%20Algorithms%20(AOA)-F34F29?style=for-the-badge&logo=git&logoColor=white)](https://github.com/DevInfinix/quicksort-analyzer-dsa)
[![Stars](https://img.shields.io/github/stars/DevInfinix/quicksort-analyzer-dsa?style=for-the-badge&color=gold)](https://github.com/DevInfinix/quicksort-analyzer-dsa/stargazers)
[![Forks](https://img.shields.io/github/forks/DevInfinix/quicksort-analyzer-dsa?style=for-the-badge&color=blue)](https://github.com/DevInfinix/quicksort-analyzer-dsa/network/members)
[![Issues](https://img.shields.io/github/issues/DevInfinix/quicksort-analyzer-dsa?style=for-the-badge&color=brightgreen)](https://github.com/DevInfinix/quicksort-analyzer-dsa/issues)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<br/>

**A C program that sorts student records (ID, name, marks) using Quicksort, with configurable pivot strategy and live performance metrics.**

[Features](#features) • [How It Works](#how-quicksort-works) • [Demo](#demo) • [Quick Start](#quick-start) • [Metrics](#analysis-report) • [Contributors](#contributors)

</div>

---

## Why This Exists

In our Analysis of Algorithms class, we learned Quicksort on paper with integer arrays. This project takes that concept and applies it to real student records — so you can see exactly how the algorithm behaves when the data is more complex than just numbers.

---

## Features

- **Add / View Records** — Store up to 100 students (ID, name, marks) and display them in a table
- **Sort by Any Field** — Sort by ID, name, or marks, in either ascending or descending order
- **Choose Your Pivot** — First element, last element, or middle element as the pivot
- **Step-by-Step Trace** — See the pivot value and partition sizes at every recursive call
- **Performance Counters** — Comparisons, swaps, partitions, and recursive call counts

---

## How Quicksort Works

Quicksort is a **divide-and-conquer** algorithm. You pick one element as the pivot, then move everything smaller to its left and everything larger to its right. Then you do the same for each side — recursively.

```
Input:  [3, 6, 8, 10, 1, 2, 5]
Pivot = first element (3)

After partition: [1, 2] | 3 | [6, 8, 10, 5]
Recurse on left:  [1, 2]              (already sorted)
Recurse on right: [6, 8, 10, 5]      → [5, 6, 8, 10]

Result: [1, 2, 3, 5, 6, 8, 10]
```

The program does this on student records instead of single integers. When you sort by marks, for example, it compares the `marks` field of each struct.

### Complexity

| Case | Time | Space (stack) | When it happens |
| :--- | :---: | :---: | :--- |
| **Best** | O(n log n) | O(log n) | Pivot always splits work evenly |
| **Average** | O(n log n) | O(log n) | Typical random data |
| **Worst** | O(n²) | O(n) | Bad pivots on sorted/reverse data |

---

## Demo

### 1. Main Menu & Adding Records

<img src="assets/screenshots/01_main_menu.png" alt="Main Menu" width="100%"/>

Add students one at a time. Each entry is also saved to a backup array, so you can re-sort without re-adding.

### 2. Viewing Records

<img src="assets/screenshots/02_display_records.png" alt="Display Records" width="100%"/>

Records are shown in a simple tab-separated table.

### 3. Sorting & Partition Trace

<img src="assets/screenshots/03_sorting_partition.png" alt="Partition Details" width="100%"/>

After choosing sort field, order, and pivot strategy, the program shows every partition step — which element was the pivot and how many records ended up on each side.

### 4. Analysis Report

<img src="assets/screenshots/04_analysis_report.png" alt="Analysis Report" width="100%"/>

After sorting finishes, you get the final record list plus a summary of how many comparisons, swaps, partitions, and recursive calls it took.

---

## Quick Start

You'll need a C compiler like GCC.

```bash
git clone https://github.com/DevInfinix/quicksort-analyzer-dsa.git
cd quicksort-analyzer-dsa
gcc -Wall -Wextra quicksort_records.c -o quicksort_records
```

Then run it:

**Linux / macOS:**
```bash
./quicksort_records
```

**Windows:**
```powershell
.\quicksort_records.exe
```

---

## Analysis Report

Here is an example of what the output looks like after one sort run:

```
--- Analysis Report ---
Comparisons     : 14
Swaps           : 4
Partitions      : 3
Recursive calls : 7
-----------------------
```

| Metric | What it counts |
|---|---|
| **Comparisons** | How many times two records were compared |
| **Swaps** | How many times two records were exchanged in memory |
| **Partitions** | How many times the list was split around a pivot |
| **Recursive calls** | How many times `quicksort()` called itself |

---

## Repository Structure

```
quicksort-analyzer-dsa/
├── assets/
│   └── screenshots/
│       ├── 01_main_menu.png
│       ├── 02_display_records.png
│       ├── 03_sorting_partition.png
│       └── 04_analysis_report.png
├── .gitignore
├── LICENSE
├── README.md
└── quicksort_records.c
```

---

## Contributors

Built as a team for the Analysis of Algorithms (AOA) course.

<div align="center">
<table>
  <tr>
    <td align="center" width="25%">
      <a href="https://github.com/DevInfinix">
        <img src="https://github.com/DevInfinix.png" width="90px;" alt="DevInfinix"/><br />
        <sub><b>DevInfinix</b></sub>
      </a><br />
      <sub>Lead Developer</sub>
    </td>
    <td align="center" width="25%">
      <a href="https://github.com/cmrittikaoli-ux">
        <img src="https://github.com/cmrittikaoli-ux.png" width="90px;" alt="cmrittikaoli-ux"/><br />
        <sub><b>cmrittikaoli-ux</b></sub>
      </a><br />
      <sub>Contributor</sub>
    </td>
    <td align="center" width="25%">
      <a href="https://github.com/kilmngrrr">
        <img src="https://github.com/kilmngrrr.png" width="90px;" alt="kilmngrrr"/><br />
        <sub><b>kilmngrrr</b></sub>
      </a><br />
      <sub>Contributor</sub>
    </td>
    <td align="center" width="25%">
      <a href="https://github.com/ayurdapatil">
        <img src="https://github.com/ayurdapatil.png" width="90px;" alt="ayurdapatil"/><br />
        <sub><b>ayurdapatil</b></sub>
      </a><br />
      <sub>Contributor</sub>
    </td>
  </tr>
</table>
</div>

---

## License

MIT — use it for any academic work or learning project.
