#include <stdio.h>

int logicalShift(int x, int n) {
	
	int mask = ~((~0 << 1) << (31 + (~n + 1)));

	return (x >> n) & mask;

}

int main() {

	int num, shift;

	printf("Enter number and no. of shifts: ");
	scanf("%x %d", &num, &shift);

	int result = logicalShift(num, shift);

	printf("Shifted number is: 0x%X\n", result);

	return 0;

}
