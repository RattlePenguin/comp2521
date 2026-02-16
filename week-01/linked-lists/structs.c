/**
 *  Consider the following two linked list representations below.
 *  1. Compare the two representations diagramatically.
 *  2. How is an empty list represented in each case?
 *  3. What are the advantages of having a separate list struct as in Representation 2?
 */

// Representation 1
struct node {
    int value;
    struct node *next;
};


// Representation 2
struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};


int listLength(struct list *list);
