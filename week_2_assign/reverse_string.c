#include <stdio.h>

void reverse_string(char *str) {
	int i = 0;
    	int j = 0;

   	 while (str[j] != '\0' && str[j] != '\n') {
        	j++;
   	 }

   	 j--; 

   	 while (i < j) {
       		char temp = str[i];
       		str[i] = str[j];
        	str[j] = temp;

        	i++;
        	j--;
   	 }
}

int main() {
	char str[100];

	printf("Enter the string: ");
	fgets(str, sizeof(str), stdin);

	reverse_string(str);

	printf("Reversal of string is: %s\n",str);
}
