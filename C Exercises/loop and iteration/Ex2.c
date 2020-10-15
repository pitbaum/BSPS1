#include <stdio.h>
int sum = 0;
void main(){
	int x = 0;
	while(x != -999){
		printf("Enter number: ");
		scanf("%d", &x);
		sum += x;
	}
	sum += 999;
	printf("sum of the numbers entered : %d \n ", sum);
}
