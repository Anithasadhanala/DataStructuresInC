#include<stdio.h>
int main(){
	int arr[100],size,copy,i,j;
	scanf("%d",&size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	for(i=1;i<size;i++){
		copy=arr[i];
		j=i-1;
		while(copy<arr[j] && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=copy;
	}
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	
}
