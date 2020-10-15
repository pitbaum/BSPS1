/* Input two numbers and work out their sum, average and sum of the squares of the numbers.*/

int a,b,c;

int main()
{	
	printf("Enter a number: ");
	scanf("%d", &a);
	printf("Enter a second number: ");
	scanf("%d", &b);			/* input of a and b, Note: the & sign*/
	printf("a= %d and b= %d \n", a, b);		/* output*/
	int c = a + b;
	printf("%d \n", c);
}

