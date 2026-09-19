#include <stdio.h>
#include <stdlib.h>

#include "List.h"

struct node *reverseList(struct node *head);

int main(void) {
  // Create a linked list of length 5 in ascending order {1,2...5}
  struct node *head = NULL;
  for (int i = 0; i < 5; ++i) {
    struct node *new = malloc(sizeof(*new));
    new->value = 5 - i;
    new->next = head;
    head = new;
  }

  printf("before:\n");
  ListPrint(head);

  head = reverseList(head);

  printf("after:\n");
  ListPrint(head);
  return 0;
}

/** Reverses a linked list recursively.
        This modifies the original list!
*/
struct node *reverseList(struct node *head) { return head; }
