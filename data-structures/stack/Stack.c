#include <stdlib.h>

#include "Stack.h"

// Creates a new empty stack
Stack StackNew(void) {
	Stack s = calloc(1, sizeof(Stack));
	s->capacity = 32;
	s->items = malloc((size_t) s->capacity * sizeof(int));

	return s;
}

// Frees all memory allocated to the stack
void StackFree(Stack s) {
	free(s->items);
	free(s);
}

// Pushes an item onto the stack
void StackPush(Stack s, int item) {
	if (s->numItems >= s->capacity) {
		s->items = realloc(s->items , (size_t) (2 * s->capacity) * (int) sizeof(int));
		s->capacity *= 2;
	}

	s->items[s->numItems++] = item;
}

// Pops an item from the stack and returns it
// Assumes that the stack is not empty
int StackPop(Stack s) {
	return s->items[--s->numItems];
}

// Returns the number of items on the stack
int StackSize(Stack s) {
	return s->numItems;
}
