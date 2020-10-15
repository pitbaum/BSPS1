#include <stdio.h>
int replace(char list[]){
	int index = 0;
	int count;
         while( list[index] !=  '\n'){
         	if(list[index] == ' '){
         		list[index] = '-';
         		count++;
         	}
        	index++;
        }
	return count;
}

main(){
	char *cat = "The car sat";
	int n = replace(cat);
	printf("%d \n", n);
	printf("%s \n", cat);
}
