#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("arr[0] = %d\n", arr[0]);
	printf("(arr + 1)[0] = %d\n", (arr + 1)[0]);
	return EXIT_SUCCESS;
}
