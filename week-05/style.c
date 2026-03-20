#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void freeList(struct Node *head) {
	if (head == NULL) {
	return;
	}
	// Frees the list by iterating through the list, using a temporary element and freeing the elements by using free (hopefully this comment is useful and helps out)
	struct Node *Temp = head;
	while (head != NULL) {
	    Temp = head;
	    head = head->next;
	    free(Temp);
	}
}
void print_list(struct Node *node) {
    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
    return;
}
struct Node *add(struct Node *a, int data) {
    // malloc the node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // set the node's data field
    newNode->data = data;
    // set the node's next field to NULL
    newNode->next = NULL;
	if (a == NULL) {
		a = newNode;
	} else {
        struct Node *lastNode = a;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
	}
	return a;
}
int main() {
	struct Node *head = NULL;
	head = add(head, 1);
	head = add(head, 2);
	head = add(head, 3);
	head = add(head, 4);
	print_list(head);
	freeList(head);
	return 0;
}
