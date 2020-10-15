int x1;
int x2;

void main(){
	scanf("%d", &x1);
	scanf("%d", &x2);
	if(x1<x2){
		printf("Up \n");
	}
	else if(x1>x2){
		printf("down \n");
	}
	else if(x1 == x2){
		printf("equal \n");
	}
	else{
		printf("Error \n");
		exit(0);
	}
}
