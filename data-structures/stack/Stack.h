typedef struct stack {
	int numItems;
	int capacity;
	int *items;
} *Stack;

// Creates a new empty stack
Stack StackNew(void);

// Frees all memory allocated to the stack
void StackFree(Stack s);

// Pushes an item onto the stack
void StackPush(Stack s, int item);

// Pops an item from the stack and returns it
// Assumes that the stack is not empty
int StackPop(Stack s);

// Returns the number of items on the stack
int StackSize(Stack s);
