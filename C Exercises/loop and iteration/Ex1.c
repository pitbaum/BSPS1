int numberlist[10];
int sum;
int min;
int max;
main(){
	int x = 0;
	while(x<10){
		int number;
		scanf("%d", &number);
		numberlist[x] = number;
		x++;
	}
	sum = 0;
	min = numberlist[1];
	max = numberlist[1];
	for(int x=0; x<10; x++){
		sum += numberlist[x];
		if(numberlist[x] < min){
			min = numberlist[x];
		}
		if(numberlist[x] > max){
			max = numberlist[x];
		}
	}
	printf("average : %d ; min : %d ; max : %d \n", sum, min, max);
}
