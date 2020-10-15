#include <stdlib.h>
#include <stdio.h>
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int x;
void main(){
	printf("Enter number you want to look for in the Array : ");
	scanf("%d", &x);
	int *pa;
	for(int i=0; i<100; i++){
		pa = &a[i];
		if(x == *pa){
			printf("the number %d is safed with the index %d \n", x, i);
			exit(0);
		}
	}
	printf("There is no corresponding value in the Array. \n");
}
