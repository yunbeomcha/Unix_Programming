#include <stdio.h>
#include <stdlib.h>

int main(){
	int x[10];
	int i;
	int sum = 0;
	for(i = 0; i<10; i++){
	scanf("%d",&x[i]);
	if(x[i] > 0){
	sum += x[i];
	}	
}
	printf("%d\n", sum);
	return 0;
}
