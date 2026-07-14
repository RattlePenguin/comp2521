#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool twoSum(int arr[], int size, int target);

int main(void) {
	printf("Enter size of array: ");
	int size;
	scanf("%d", &size);

	printf("Enter array values: ");
	int *arr = malloc(sizeof(size));
	for (int i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}

	printf("Enter target sum: ");
	int target;
	scanf("%d", &target);
	if (twoSum(arr, size, target)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

bool twoSum(int arr[], int size, int target) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i] + arr[j] == target) return true;
		}
	}
	return false;
}
