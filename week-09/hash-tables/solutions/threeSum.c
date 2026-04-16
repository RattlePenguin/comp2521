// Given an array of integers and a target sum S, determine whether the array contains three integers that sum to S.
// Try to find a solution that is O(n2) on average.

#include <stdio.h>
#include <stdbool.h>

#include "HashTable.h"

bool threeSum(int arr[], int size, int sum);

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };

	if (threeSum(arr, 5, 11)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	if (threeSum(arr, 5, 5)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

bool threeSum(int arr[], int size, int sum) {
	HashTable ht = HashTableNew();

	for (int i = 0; i < size; i++) {
		if (HashTableContains(ht, sum - arr[i])) {
			HashTableFree(ht);
			return true;
		}
		
		for (int j = 0; j < i; j++) {
			HashTableInsert(ht, arr[i] + arr[j], 0);
		}
	}

	HashTableFree(ht);
	return false;
}
