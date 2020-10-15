#include <stdio.h>
#include <stdlib.h>
int number;
int step;
void main(){
	scanf("%d", &number);
	if(number <1){
	printf("Error");
	exit(0);
	}
	printf("initial value is %d \n", number);
	step = 0;
	while(number>1){
		if(number%2 == 0){
			number = number/2;
			step++;
		}
		else{
			number = (number*3)+1;
			step++;
		}
		printf("next value is %d \n", number);
	}
	printf("final value %d , number of steps %d \n", number, step);
} 
