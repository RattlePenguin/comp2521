/**
 *  Explain how stackInt and heapInt differ, and what happens if each one is called in main.
 */

#include <stdlib.h>

void stackInt(void);
void heapInt(void);

int main(void) {
	stackInt();
	// heapInt();
}

void stackInt(void) {
	int a = 5;
}

void heapInt(void) {
	int *a = malloc(sizeof(int));
	*a = 5;
}
