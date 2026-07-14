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
	// create l and r pointers
	for (int l = 0, r = (int) strlen(s) - 2; l < r; ++l, --r) {
		if (s[l] != s[r]) { // if chars are different, not palindrome
			return false;
		}
	}
	return true;
}
