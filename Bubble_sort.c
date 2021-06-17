#include<stdio.h>
#include<stdlib.h>
int main(){
	int *arr,size,i;
	scanf("%d",&size);
	arr=(int*)malloc(sizeof(int)*size);
	
	for (i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int copy,j;

	for(j=0;j<size;j++){
	
			for(i=0;i<size-j;i++){
				
			while(arr[i]>arr[i+1]){
				copy=arr[i+1];
				arr[i+1]=arr[i];
				arr[i]=copy;
				i++;
			}
		}	
	}
	for (i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	
	
	
	
}
