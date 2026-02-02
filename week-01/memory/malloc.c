#include <stdio.h>
#include <stdlib.h>

int *stackInt(void);
int *heapInt(void);

int main(void) {
	int *myStackInt = stackInt();
	printf("myStackInt == %d\n", *myStackInt);
	
	int *myHeapInt = heapInt();

	printf("myHeapInt == %p\n", (void *) myHeapInt);
	printf("*myHeapInt == %d\n", *myHeapInt);

	free(myHeapInt);
	return 0;
}

int *stackInt(void) {
	int a = 5;
	return &a;
}

int *heapInt(void) {
	int *a = malloc(sizeof(int));
	*a = 10;
	return a;
}
