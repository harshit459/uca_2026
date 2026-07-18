#include <stdio.h>

int main(){
	int n;
	printf("Enter number: ");
	scanf("%d",&n);
	int a=1, b=1;
	int sum = 0;
	while(b <= n) {
		if(b % 2 == 0){
			sum += b;
		}
		int temp = b;
		b = a+b;
		a = temp;
	}
	printf("Sum of even fibonacci no.s: %d\n",sum);
	return 0;
}
