#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *a = calloc(1, sizeof(int));
	*a = 9;

	int **b = calloc(1, sizeof(int *));
	*b = a;

	int ***c = calloc(1, sizeof(int **));
	*c = b;

	printf("%d\n", *a);
	printf("%d\n", **b);
	printf("%d\n", ***c);

	printf("%p\n", (void *) a);
	printf("%p\n", (void *) b);
	printf("%p\n", (void *) c);

	return 0;
}
