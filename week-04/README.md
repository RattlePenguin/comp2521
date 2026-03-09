# Introduction
Abstract Data Types (ADT) may be what you encounter the most when you code in your career.
ADTs allow us to simply use complex data structures without compromising its integrity or bothering with its implementation.

It might help to think of Binary Tree nodes as Linked List nodes with two children instead of just one.
Remember that O(n) represents the entire tree, while O(log n) represents traversing down either child.

# Topics
- Abstract Data Types
- Binary Search Trees
    - Lookup
    - Insertion
    - Deletion
    - Traversal
- Analysis of Trees

## Abstract Data Types
ADTs are models where behaviour is defined, but their implementation is not made known to the user.
In Python, Java, C++, you may have heard of libraries, vectors, queues, arraylists.
These are ADTs as you as the user are not intended to know how they are implemented, just how they work and perform.

The interface contains all the function declarations made for the user to use, and is contained in the header `.h` file.
The implementation is contained in the `.c` file.

## Binary Search Trees
Binary trees are a data structure where nodes have only two children.
Binary search trees (BST) are binary trees where the left child must contain a value lesser than the parent, and the right child must contain a value greater than the parent.

Just like linked lists, BSTs are a recursive data structure.
A tree could also be a subtree, empty, or a single node.
Children are therefore subtrees of their own.
