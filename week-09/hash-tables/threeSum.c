// Given an array of integers and a target sum S, determine whether the array contains three integers that sum to S.
// Try to find a solution that is O(n2) on average.

#include <stdio.h>
#include <stdbool.h>

bool threeSum(int arr[], int size, int sum);

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };

	if (threeSum(arr, 5, 11)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}


bool threeSum(int arr[], int size, int sum) {
	// TODO
}
