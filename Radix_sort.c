#include<stdio.h>
#include<stdlib.h>

void counting_sort(int *arr,int size,int div){
	int count[10],i;
	for(i=0;i<10;i++){
		count[i]=0;
	}
	int temp[size];
	for(i=0;i<size;i++){
		count[(arr[i]/div)%10]++;
		
	}
	for(i=0;i<10;i++){
		count[i]=count[i]+count[i-1];
		
	}
	for(i=size-1;i>=0;i--){
		temp[count[(arr[i]/div)%10]-1]=arr[i];
		count[(arr[i]/div)%10]--;
		
	}
	for(i=0;i<size;i++){
		arr[i]=temp[i];
		
	}
}

int max_digits(int *arr,int size){
	int max,i;
	max=arr[0];
	for(i=0;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void radix_sort(int *arr,int size){
	int m,div;
	m=max_digits(arr,size);
	for(div=1;m/div>0;div*=10){
		counting_sort(arr,size,div);
	}
}

int main(){
	int size,*arr,i;
	scanf("%d",&size);
	arr=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,size);
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
