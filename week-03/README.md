# Introduction
You could think of sorting as a broad topic, while each sorting algorithm is a specific implementation.
In the future, the implementation you use might become less important.
Instead, you may be looking for certain properties (speed, stability) that are required in your program.

# Reminders
- HELP sessions start this week.

# Topics
- Sorting Algorithms
    - Bubble, Insertion, Selection
    - Merge, Quick (Naive, Random, Median of 3)
    - Bucket, Radix
    - Stability, Efficiency
- Abstract Data Types

## Sorting Algorithms
Your goal for this topic should be to:
- Name all sorting algorithms in this course.
- Know the general steps or concept of the algorithm.
- Comfortably state the worst, average and best case time complexity, stability, space complexity and whether it's adaptive or not for each sort.

Stable sorts maintain the order of elements with the same key.
This could be beneficial or needed in other programs, such as Radix sort or multi-level sorting.
```
Initial: 6 10a 4a 2a 8 2b 4b 9 10b 2c

Stable Output: 2a 2b 2c 4a 4b 6 8 9 10a 10b

Unstable Output: 2a 2c 2b 4a 4b 6 8 9 10b 10a
```
A stable sorting algorithm is deterministic and *always* produces a stable output.
An unstable sorting algorithm could be deterministic and could also produce a stable output.
It is important to try a variety of input cases to determine whether a sort is stable or not.

Adaptive sorts take advantage of the existing order of elements in the input data.
- Bubble and Insertion are adaptive sorts.
- Quicksort is not adaptive, even though its best-case scenario has a better time complexity.

