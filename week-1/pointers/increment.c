#include <stdio.h>

void increment(int num);
void incrementWithPointer(int *pNum);

int main(void) {
	int num = 5;

	printf("initial: \t\t\tnum == %d\n", num);

	increment(num);
	printf("after increment: \t\tnum == %d\n", num);

	incrementWithPointer(&num);
	printf("after incrementWithPointer: \tnum == %d\n", num);
}

/// Increments num.
void increment(int num) {
	num++;
}

/// Dereferences pnum then increments it.
void incrementWithPointer(int *pNum) {
	(*pNum)++;
}
