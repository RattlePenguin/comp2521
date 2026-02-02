#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Make an array of size 5.
	int arr[5] = { 1, 2, 3, 4, 5 };

	// Print the array in order.
	printf("arr = { ");
	for (int i = 0; i < 5; ++i) {
		printf("%d ", arr[i]);
	}
	printf("}");
	printf("\n");

	printf("arr[0] = %d\n", arr[0]);
	printf("(arr + 1)[0] = %d\n", (arr + 1)[0]);

	// An array is just a pointer to the first element of the array.
	int *myArrPtr = arr + 3;
	printf("myArrPtr = arr + 3");
	printf("\n");
	printf("myArrPtr[0] = arr[3] = %d\n", myArrPtr[0]);

	return EXIT_SUCCESS;
}
