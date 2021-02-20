#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[10], i,j , temp;
	for(i = 0; i<10; i++){
	scanf("%d", &arr[i]);	
	}
	for(j = 0; j < 10; j++){
	for(i = 0; i<10; i++){
		if(arr[i] > arr[j]){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		}
	}
}
	printf("정렬결과\n");
	for(i = 0; i<10; i++){
	printf("%d ", arr[i]);
	}
	printf("\n");
}
