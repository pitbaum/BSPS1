#include <stdio.h>
#include <string.h>
char longText[1000];
char shrtString[10];
int count=0;
char *pT;
char *pS;
char *pH;

void main()
{
	char ch;
	int index = 0;
	printf("input the word you look for: ");
	while( scanf("%c", &ch) ==1 ){
        	shrtString[index] = ch;
        	index++;
        	if(ch == '\n')
        		break;
        }
        index = 0;
	printf("input the text to search in: ");
	while( scanf("%c", &ch) ==1 ){
        	longText[index] = ch;
        	index++;
        	if(ch == '\n')
        		break;
        }
        
	
	for(int i=0; longText[i] != '\n'; i++)
	{
		pT = &longText[i];
		pS = &shrtString[0];
		
		if(*pT == *pS)
		{
			int j = 0;
			while(*pS != '\n')
			{
				char *pH;
				char help[10];
				pT = &shrtString[j];
				pS = &longText[i+j];
				if(*pT == *pS)
				{
					printf("came here");
					pH = &help[j];
					*pH = *pT;
					j++;
				}
				else
				{
					if(strcmp(shrtString, help) == 0)
					{
						count ++;
						break;
					}
					
				}
			}
		}
	}
	printf("%d \n", count);
}
