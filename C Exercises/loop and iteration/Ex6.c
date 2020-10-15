/* Ex7 will be skipped*/
int a = 0;
int e =0;
int o =0;
int u =0;
int i =0;
int rest = 0;
main(){
	char ch;
    while( scanf("%c", &ch) ==1) {
		if(ch == 'a'){
			a++;
		}
		else if(ch == 'e'){
			e++;
		}
		else if(ch == 'o'){
			o++;
		}
		else if(ch == 'u'){
			u++;
		}
		else if(ch == 'i'){
			i++;
		}
		else{
			rest++;
		}
		if(ch == '\n'){
        		break;
        	}
    }
	
	printf("Numbers of characters: \n");
	printf("a %d ; e %d ; i %d ; o %d ; u %d ; rest %d \n", a, e, i, o, u, rest);
	int sum = a+e+i+o+u+rest;
	a = (a*100)/sum;
	e = (e*100)/sum;
	i = (i*100)/sum;
	o = (o*100)/sum;
	u = (u*100)/sum;
	rest = (rest*100)/sum;
	printf("Percentages of total: \n");
	printf("a %d ; e %d ; i %d ; o %d ; u %d ; rest %d \n", a, e, i, o, u, rest);
}
