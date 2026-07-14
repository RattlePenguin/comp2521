#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(void) {
	printf("Enter a word: ");
	char input[64];
	if (fgets(input, sizeof(input), stdin) == NULL) {
		exit(EXIT_FAILURE);
	}

	if (isPalindrome(input)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}

	return 0;
}

bool isPalindrome(char *s) {
	return false;
}
