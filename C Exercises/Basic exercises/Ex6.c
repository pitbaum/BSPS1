#include<stdio.h> 
int number;
int main(){
	printf("enter a number");
	scanf("%d", &number);
	if(number < 3){
			printf("error the number must be bigger than 3");
	}
	else{
		int x1 = number;
		int x2 = number-1;
		int x3 = number-2;
		printf("%d , %d , %d \n", x1, x2, x3);
		printf("%d , %d , %d \n", x2, x3, x1);
		printf("%d, %d, %d \n", x2, x1, x3);
		printf("%d, %d, %d \n", x1, x3, x2);
		printf("%d, %d, %d \n", x3, x2, x1);
		printf("%d, %d, %d \n", x3, x1, x2);
	}
}
