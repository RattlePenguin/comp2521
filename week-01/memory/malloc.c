#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int stackInt = 5;
	printf("stackInt == %d\n", stackInt);
	
	int *heapInt = malloc(sizeof(int));
	*heapInt = 10;

	printf("heapInt == %p\n", (void *) heapInt);
	printf("*heapInt == %d\n", *heapInt);

	return 0;
}
