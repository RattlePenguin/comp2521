#include <stdio.h>

#include "Queue.h"

int main(void) {
	Queue q = QueueNew();

	for (int i = 0; i < 10; ++i) {
		QueueEnqueue(q, i);
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d ", QueueDequeue(q));
	}
	return 0;
}
