#include <stdio.h>
float payment(int pHours, int pRate){
	float sum = 0;
	if(pHours-40 <= 0){
		sum =  pRate * pHours;
	}
	else if(pHours > 40 && pHours <= 60){
		sum = pRate * pHours;
		sum += pRate * ((pHours%40) * 1.5);
	}
	else{
		sum = pRate * pHours;
		sum += pRate * ((pHours%40) * 1.5);
		sum += pRate * ((pHours%60)* 2);
	}
	
	return sum;
}

void main(){
	int x1;
	int x2;
	float total;
	while(x2 > 0){
	printf("Enter a number of hours \n");
	scanf("%d", &x1);
	printf("Enter paymentrate \n");
	scanf("%d", &x2);
	float pay = payment(x1, x2);
	total += pay;
	printf("Pay at %d pence/hr for %d hours is %f pounds \n", x2, x1, pay);
	}
	printf("Total pay is %f \n", total);
}

