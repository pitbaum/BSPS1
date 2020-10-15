#include <stdio.h>
char ch;
int len = 1;
int sizes[25];
	
void main(){
	for(int i = 0; i<25; i++){
		sizes[i] = 0;	
	}
	
	while( ch = getchar(), ch >= 0){
		if(ch == ' '){
			sizes[len-2] +=1;
			len = 0;
		}
		len++;
		if(ch == '\n'){
			sizes[len-3] +=1;
			break;
		}
	}
	
	for(int i = 0; i<25;i++){
		printf("length %d : %d occurences \n", i+1, sizes[i]);
	}
}
