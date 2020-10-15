#include <stdio.h>
void main(){
	char ch;
	int index=0;
	char list[50];
        while( scanf("%c", &ch) ==1 ){
        	list[index] = ch;
        	index++;
        	if(ch == '\n')
        		break;
        }
 
        for(int i = 0; i < index; i++){
        	char a = list[index-1-i];
        	printf("%c", a);
        }
	printf("\n");
}
