#include <stdlib.h>

#include "Stack.h"

typedef struct queue {
	Stack s1;
	Stack s2;
} *Queue;

Queue QueueNew(void);

void QueueFree(Queue q);

void QueueEnqueue(Queue q, int item);

int QueueDequeue(Queue q);
