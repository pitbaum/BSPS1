#include <stdio.h>
int a;
int b;
int c;
int *pA = &a;
int *pB = &b;
int *pC = &c;
int pH1;
int pH2;
void main()
{
	scanf("%d %d %d", &a, &b , &c);
	pH1 = *pB;
	*pB = *pA;
	pH2 = *pC;
	*pC = pH1;
	*pA = pH2;
	printf("%d , %d , %d \n", a, b, c);
	
}
