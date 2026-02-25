#include <stdio.h>

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod);

int main(void) {
	printf("Enter size of tower: ");
	int size = 0;
	scanf("%d", &size);

	solveHanoi(size, "A", "C", "B");
}


void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
	if (numDisks == 0) return;

	solveHanoi(numDisks - 1, fromRod, otherRod, toRod);
	printf("Move disk from rod %c to rod %c\n", *fromRod, *toRod);
	solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}
