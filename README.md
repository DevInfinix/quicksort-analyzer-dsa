# Quicksort Records Analyzer

<div align="center">

![C](https://img.shields.io/badge/language-C%20-programming-A8B400?logo=c&style=flat)
![License](https://img.shields.io/badge/license-MIT-blue?style=flat)
![Status](https://img.shields.io/badge/status-stable-brightgreen?style=flat)

</div>

---

## Overview

A simple C program that stores student records (ID, name, marks) and sorts
them using the **Quicksort** algorithm. The program demonstrates how different
**pivot strategies** (first, last, middle) affect sorting performance by
tracking comparisons, swaps, partitions, and recursive calls.

This project is part of the **Analysis of Algorithms** course assignment.

---

## Features

- **Add Records** — Store student data (ID, name, marks) up to 100 entries
- **Display Records** — View all stored student records in tabular format
- **Sort Records** — Quick sort by ID, name, or marks (ascending or descending)
- **Pivot Selection** — Choose first, last, or middle element as pivot
- **Analysis Metrics** — Track comparisons, swaps, partitions, and recursive calls
- **Step-by-step Output** — See pivot and partition sizes at every quicksort step

---

## How Quicksort Works

```
Input: [3, 6, 8, 10, 1, 2, 5]

1. Choose pivot (e.g., first element = 3)
2. Partition: smaller | pivot | larger
   → [1, 2] | [3] | [6, 8, 10, 5]
3. Recurse on left:  [1, 2]       → sorted
4. Recurse on right: [6, 8, 10, 5] → [5, 6, 8, 10]

Final: [1, 2, 3, 5, 6, 8, 10]
```

---

## Getting Started

### Prerequisites

- A C compiler (GCC recommended)

### Compilation

```bash
gcc quicksort_records.c -o quicksort_records
```

### Running

```bash
./quicksort_records
```

---

## Usage

```
===== QUICK SORT RECORD ORGANIZER =====
1. Add Record
2. Display Records
3. Sort Records
4. Exit
Enter choice:
```

1. **Add Record** — Enter student ID, name, and marks
2. **Display Records** — Shows all records in a table
3. **Sort Records** — Choose sort field, order, and pivot, then see the step-by-step sorting process and analysis report

---

## Analysis Report

After sorting, the program displays:

| Metric | Description |
|---|---|
| Comparisons | Number of times two records were compared |
| Swaps | Number of times two records were swapped |
| Partitions | Number of partition operations performed |
| Recursive calls | Number of times quicksort called itself |

---

## Project Structure

| File | Description |
|---|---|
| `quicksort_records.c` | Main source code |
| `FUTURE_SCOPE.md` | Planned improvements |
| `.gitignore` | Ignores compiled binaries |

---

## Built With

- **C** — Programming language
- **GCC** — Compiler

---

## Author

VIT student, Analysis of Algorithms course
