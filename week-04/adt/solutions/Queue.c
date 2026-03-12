#include "Queue.h"

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

void QueueEnqueue(Queue q, int item) {
	StackPush(q->s1, item);
}

int QueueDequeue(Queue q) {
	if (StackSize(q->s2) > 0) {
		return StackPop(q->s2);
	}

	while (StackSize(q->s1) > 0) {
		StackPush(q->s2, StackPop(q->s1));
	}
	return StackPop(q->s2);
}
