/* I skipped ex9 since its the same just with seconds*/

float centimeter;
float main(){
	printf("input a centimeter value: ");
	scanf("%f", &centimeter);
	float inch = centimeter/2.54;
	int foot = inch/12;
	printf("%f centimeters is %d feet %1f inches", centimeter, foot, inch);
}