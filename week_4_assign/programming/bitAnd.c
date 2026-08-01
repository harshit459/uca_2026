#include <stdio.h>

int bitAnd(int num1, int num2) {
	int result = ~(~num1 | ~num2);
	return result;
}

int main() {
	int num1, num2;

	printf("Enter 2 numbers: ");
	scanf("%d %d", &num1, &num2);

	int result = bitAnd(num1, num2);

	printf("bit & of two no.s using ~ and | operations is: %d\n", result);

	return 0;
}
