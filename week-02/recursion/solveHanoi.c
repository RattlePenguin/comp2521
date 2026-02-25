#include <stdio.h>

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod);

int main(void) {
	printf("Enter size of tower: ");
	int size = 0;
	scanf("%d", &size);

	solveHanoi(size, "A", "C", "B");
}


void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
}
