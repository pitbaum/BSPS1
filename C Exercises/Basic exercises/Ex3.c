/* Write a program that works out the largest and smallest values from a set of 10 inputted numbers.*/


int listofnumbers[10];
int main()
{

	for(int x=0;x<10;x++){
		printf("Enter a number: ");
		scanf("%d", &listofnumbers[x]);
	}	

	int var = listofnumbers[0];
	for(int x=0; x<10;x++){
		if(listofnumbers[x] < var){
			var = listofnumbers[x];
		}
	}
	printf("the smallest number is: %d \n", var);
}
