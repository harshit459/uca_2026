#include <stdio.h>

int fitBits(int num, int bits) {

	int tempNum = 0;
	int shift = 32 + (~bits+1);

	tempNum = ((num << shift)) >> shift;

	if((tempNum ^ num) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int num, bits;

	printf("Enter number and bits: ");
	scanf("%d %d", &num, &bits);

	int result = fitBits(num, bits);

	printf("%d\n", result);

	return 0;
}
