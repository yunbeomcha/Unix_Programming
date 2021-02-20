#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b,c;
	int max, min;
	scanf("%d %d %d", &a, &b,&c);
	if(a >= b && a>=c){
	max = a;
	if(b<= c){
		min =b;
	}
	else{
	min = c;
	}	
	}
	else if(b >= a && b>=c){
	max = b;
	if(c <= a){
	min =c;	
	}
	else {
	min =a;
	}
	}
	else{
	max =c;
	if(a <= b){
	min = a;
	}
	else {
	min =b;
	}
}
	printf("%d %d\n",max, min); 
	return 0;
}
