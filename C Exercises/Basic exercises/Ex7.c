#include<math.h>
#include<stdio.h> 
float radius;

float main(){
		printf("enter a positive float number :");
		scanf("%f", &radius);
		double r2 = pow((double)radius,2);
		float area =(float) (3.14159* r2);
		printf("The area of a circle of radius %f units is %f units. \n", radius, area);
}
