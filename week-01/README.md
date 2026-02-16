# Introduction
This week, get back into the groove of working with C. Find some code you've written before and remind yourself how to read and understand what your code is doing.
Some good concepts to remember are structs, loops, functions, pointers, types, operators.

This course moves quickly, so be prepared and spend some free time studying too.

# Reminders
- Read our [FAQ](../README.md) again if you have to!

# Topics
- Revision
    - Pointers
    - Memory Allocation
- Recursion
- Analysis of Algorithms

## Pointers
If you're not good at handling pointers yet, there's no better time than RIGHTNOW!!!

Understand the difference between pointers and addresses.

Pointer arithmetic depends on the type of the pointer.
For example, incrementing (adding 1) to an int pointer will move up its address by sizeof(int) bytes which is 4 on most systems. On the other hand, incrementing a char pointer will only move it up by 1 byte.

## Memory Allocation
You should dynamically allocate memory when:
- Handling large amounts of memory.
- You need it to live outside of scope.
- Storing user input (security reasons).

You can do so with `malloc` or `calloc` from the C standard library.

## Recursion
Recursion is not just calling the same function in itself.
The point is to extract the "subproblem".
In doing so, you can utilise the solution to smaller subproblems to solve larger ones.

Recognise the "base case" and the "recursive case".

Recognise when you need to process before or after recursing. Or both.

## Linked Lists
### Why do we sometimes use `struct list` in addition to `struct node`?
- We can establish an empty list better using `struct list`.
- We can always keep track of the head of the list using `struct list`.
- We could add more to `struct list` to make it more useful, such as adding a tail pointer.

