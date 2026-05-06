# Introduction
You've made it!!!

Heaps allows us to form a binary-tree-like structure when storing values in an array.
A max heap ensures that a parent will always be greater than or equal to its children.
A min heap ensures that parents are lesser than or equal to their children.

Insertion and deletion are $O(logn)$ time due to the heapify operation.
Heaps allow us to **obtain** the largest or smallest value in $O(1)$ time.

Tries are tree-like data structures that enable prefixing keys as continuous memory / strings (e.g. words, binary).
Ends of keys have indicators.
Insertion and deletion operations on tries are much like linked lists, utilising recursion.

# Reminders
- Assignment 2 is due today...

# Topics
- Heaps
    - Arrays
    - Min and Max Heap
    - Push, Top, Pop, Heapify
- Tries
    - Data structure
    - Prefixing
    - Insertion, Deletion, Lookup

## Heaps
While heaps are visualised using a binary tree, they actually use an array to store their values.
To access children like the binary tree:

For a parent at index $i$, the left child is at $2i + 1$ and the right child at $2i + 2$.

### Operations
The most important operation is heapify a.k.a. fixUp / fixDown.
This is usually performed at insertion or deletion, and targeted at the affected node.
From the target node, we compare values up and down the height.
If values are in the wrong position (e.g. greater child in a max heap) then a swap is made between parent and child.
Doing this for the height of the heap is $O(logn)$ time.

Insertion and deletion are similar:

A new value is inserted at the end of the heap in $O(1)$ time.
Then fix up maintains the heap property in $O(logn)$ time.
Therefore, insertion is $O(logn)$.

A value is deleted by swapping it with the last element then popping in $O(1)$ time.
Then fix down maintains the heap property in $O(logn)$ time.
In a max heap, the swap is made with the bigger child.
Therefore, deletion is $O(logn)$.

### Analysis
If we insert $n$ values one by one, we end up with an $O(nlogn)$ time complexity.
However, we can actually build a heap in $O(n)$ time if we have every value already in our array.
This requires some mathematical analysis that can be found online.

A heap can be used to obtain the $k$ greatest or smallest values in a list.
This is usually done by maintaining a min or max heap of size $k$.

Be careful!
A min heap is used to find the greatest $k$ values, because we want to pop the smallest value in the heap at each stage.
v.v.

## Tries
Manipulating a trie is similar to linked lists or trees.

