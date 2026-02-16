/**
 *  Implement a function to delete the first instance of a value from a list, if it exists.
 *  Use the two different list representations and explain how they differ.
 */

struct node {
    int value;
    struct node *next;
};

/**
struct list {
	struct node *head;
};
*/

struct node *listDelete(struct node *list, int value);
