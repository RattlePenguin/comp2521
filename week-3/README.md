# Introduction
Stable sorts maintain the order of elements with the same key. This could be beneficial or needed in other programs, such as Radix sort.
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

# Reminders
# Topics
- Big O Notation
- Sorting Algorithms
    - Bubble, Insertion, Selection
    - Merge, Quick (Naive, Random, Median of 3)
    - Bucket, Radix
    - Stability, Efficiency
