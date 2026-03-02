#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int a;
	int b;
} Item;

bool isStableSort(Item original[], Item sorted[], int size);

int main(void) {
	Item original[6] = {
		{ 2, 1 },
		{ 1, 0 },
		{ 5, 0 },
		{ 2, 2 },
		{ 4, 3 },
		{ 4, 4 }
	};

	// b key is in the right order
	Item stable[6] = {
		{ 1, 0 },
		{ 2, 1 },
		{ 2, 2 },
		{ 4, 3 },
		{ 4, 4 },
		{ 5, 0 }
	};

	// b key not in the right order
	Item unstable[6] = {
		{ 1, 0 },
		{ 2, 1 },
		{ 2, 2 },
		{ 4, 4 },
		{ 4, 3 },
		{ 5, 0 }
	};

	if (isStableSort(original, stable, 6)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	
	if (isStableSort(original, unstable, 6)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}

	return 0;
}

// Returns true if the sorted array is stable, false otherwise.
bool isStableSort(Item original[], Item sorted[], int size) {
	if (original && sorted && size) return false;
	return false;
}
