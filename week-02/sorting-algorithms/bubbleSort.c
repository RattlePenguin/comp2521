#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArr(int *arr, int size);
void bubbleSort(int *arr, int size);

int main(void) {
	printf("Enter size of array: ");
	int size;
	scanf("%d", &size);

	int *arr = malloc((unsigned long) size * sizeof(int));
	for (int i = 0; i < size; ++i) {
		arr[i] = size - i;
	}
	printArr(arr, size);
	bubbleSort(arr, size);
	printArr(arr, size);
}

void printArr(int *arr, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int *arr, int size) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = false;
			}
		}
	}
}
