#include<stdio.h> 
float temperatureC;
float main(){
	scanf("%d", &temperatureC);
	float temperatureF = temperatureC *9/5 +32;
	printf("the temperature in C is %f \n", temperatureC);
	printf("the temperature in F is %f \n", temperatureF);
	printf("%f degrees Celsius converts to %f degrees Fahrenheit \n", temperatureC, temperatureF);
}
