/**
 *  Using the below linked list representation,
 *  Write a function to sum the values in the list. Implement it first using
 * while and then using for.
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

int listSum(struct node *l);

int main() {
  struct node *l = calloc(1, sizeof(*l));
  ListAppend(l, 5);
  ListAppend(l, 4);

  ListPrint(l);

  printf("ListSum: %d\n", listSum(l));
}

int listSum(struct node *l) {
  int sum = 0;
  for (struct node *cur = l; cur != NULL; cur = cur->next) {
    sum += cur->value;
  }
  return sum;
}
