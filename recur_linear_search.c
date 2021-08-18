#include<stdio.h>

int finding_index(int *arr,int size,int search,int i){
	
	if(i>size-1){
		return -1;
	}
	if (arr[i]==search){
		return i;
	}
	i++;

	return finding_index(arr,size,search,i);
}

int main(){
	int size,search,i,index;
	scanf("%d%d",&size,&search);
	int arr[size];
	for (i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	i=0;
	index=finding_index(arr,size,search,i);
	if (index==-1){
		printf("Element not found");
	}
	else{
		printf("%d ",index);
	}
	
}
