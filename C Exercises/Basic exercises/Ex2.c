/* Input and output your name, address and age to an appropriate structure.*/
/* Also includes ex5*/ 
/* Write a program to print several lines (such as your name and address). You may use either several printf instructions, each with a newline character in it, or one printf with several newlines in the string.*/
char name[25];
char age[25];
char adresse[50];		/*creating gloabal "String" variable with max size*/

unsigned char main()
{
	printf("Enter your name: ");		/*outputting a description phrase to the input*/
	scanf("%s", name);			/*reading out the string*/
	printf("Enter your age: ");
	scanf("%s", age);
	printf("Enter your adresse: ");
	scanf("%s", adresse);
	printf("your name is %s , your age is %s and your adresse is %s \n", name, age, adresse);
}

