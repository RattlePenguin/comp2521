/**
 *  Implement a function to delete the first instance of a value from a list, if
 * it exists. Use the two different list representations and explain how they
 * differ.
 */

#include <List.h>
#include <stdio.h>
#include <stdlib.h>

/**
struct node {
  int value;
  struct node *next;
};
*/

/**
struct list {
        struct node *head;
};
*/

struct node *listDelete(struct node *list, int value);

int main() {
  struct node *l = calloc(1, sizeof(*l));
  ListAppend(l, 1);
  ListAppend(l, 2);

  ListPrint(l);

  printf("Enter node to delete: ");
  int value;
  scanf("%d", &value);

  l = listDelete(l, value);
  ListPrint(l);
}

// Deletes the first instance of value from list.
// Returns the head of the linked list.
struct node *listDelete(struct node *list, int value) { return list; }
