#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Enter length of array: ");

	int input;
	scanf("%d", &input);
	
	int array[input];

	for (int i = 0; i < input; ++i) {
		array[i] = i;
		printf("%d ", array[i]);
	}

	return EXIT_SUCCESS;
}
