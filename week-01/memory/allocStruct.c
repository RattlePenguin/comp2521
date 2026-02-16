/**
 *  Modify the code below so that it allocates the struct on the heap, instead of the stack.
 */

struct node {
	int value;
	struct node *next;
};

int main(void) {
	struct node n;
	n.value = 42;
	n.next = NULL;
}
