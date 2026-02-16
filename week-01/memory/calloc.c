#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *m = malloc(sizeof(int));
	printf("%d\n", *m); // Undefined behaviour

	int *c = calloc(1, sizeof(int));
	printf("%d\n", *c);

	return 0;
}

