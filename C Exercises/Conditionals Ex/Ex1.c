#include <math.h>
#include <stdio.h>
char letter1 = 0;
char letter2 = 0;
int sum = 0;
void main(){

	printf("Enter first digit: ");
	scanf("%c", &letter1);
	printf("Enter second digit: ");
	scanf("%c", &letter2);
	
	if(letter1 == 'A'){
		sum += pow(16,1)* 11;
	}
	else if(letter1 == 'B'){
		sum += pow(16,1)* 12;
	}
	else if(letter1 == 'C'){
		sum += pow(16,1)* 13;
	}
	else if (letter1 == 'D'){
		sum += pow(16,1)* 14;
	}
	else if(letter1 == 'E'){
		sum += pow(16,1)* 15;
	}
	else if (letter1 == 'F'){
		sum += pow(16,1)* 16;
	}
	else{
		sum += pow(16,1)* (int)letter1;
	}
	
	if(letter2 == 'A'){
		sum += 10;
	}
	else if(letter2 == 'B'){
		sum += 11;
	}
	else if(letter2 == 'C'){
		sum += 12;
	}
	else if (letter2 == 'D'){
		sum += 13;
	}
	else if(letter2 == 'E'){
		sum += 14;
	}
	else if (letter2 == 'F'){
		sum += 15;
	}
	else{
		sum += (int) letter1;
	}
	
	printf("in hexamdecimal: %c %c is in decimal %d \n", letter1, letter2, sum);
}
