#include <stdio.h>

int my_strlen(const char *str) {
	int length = 0;
	while(str[length] != '\0' && str[length] != '\n') {
		length++;
	}

	return length;
}

int main() {
	char str[100];

	printf("Enter the string: ");
	fgets(str, 100, stdin);
	printf("Length of string is: %d\n", my_strlen(str));

	return 0;
}
