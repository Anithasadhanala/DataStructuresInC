#include<stdio.h>
int main(){
	int arr[100],size,i,j,min;
	scanf("%d",&size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<size;i++){
		min=arr[i];
		
		for(j=i;j<size;j++){
			if(arr[j]<min){
				
				min=arr[j];
				arr[j]=arr[i];
			}
			arr[i]=min;
		}
}	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
