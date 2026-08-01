#include <stdio.h>

int sign(int num) {

	int Msb = num >> 31;
	int signOpr = !!num;
	return Msb | signOpr;	
}

int main() {
	int num;

	printf("Enter the number: ");
	scanf("%d", &num);

	int signNum = sign(num);

	printf("%d\n", signNum);

	return 0;
}
