 /* Ex3 was skipped, since the idea is the same as the one in conditional Ex1*/
#include <stdio.h>
int capital;
float rate;
int years;
float interest;
float capitalsum;
void main(){
	printf("Enter a start capital: ");
	scanf("%d", &capital);
	printf("Enter a rate in percent: ");
	scanf("%f", &rate);
	printf("Enter a number of years: ");
	scanf("%d", &years);
	for(int x = 0; x<years; x++){
		interest = capital * rate/100;
		capitalsum += interest;
		printf("year: %d  interest: %2f  Sum: %2f \n", years, interest, capitalsum);
	}
}
