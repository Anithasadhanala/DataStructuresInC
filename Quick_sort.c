#include<stdio.h>
#include<stdlib.h>

int partition(int *arr,int start,int end){		// partition func
	
	int i,copy1,copy2,pivot=arr[end];
	int p_index=start;							// used to swap index wise..
	
	for(i=start;i<end;i++){
		
		if(arr[i]<pivot){						// if 7 9 2 3 6 here,first put all items that are < pivot (6)

			copy1=arr[p_index];					// so,2 3 7 9 6
			arr[p_index]=arr[i];
			arr[i]=copy1;
			p_index++;
		}
	}
	copy2=arr[p_index];							//now put 6 in its correct positon...
	arr[p_index]=pivot;   	
	arr[end]=copy2;
	return p_index;
}

void quick_sort(int *arr,int start,int end){
	int pivot=arr[end],p;						//pivot is always the last element...
	
	if(start<end){
		p=partition(arr,start,end);				//calling partition_func
		quick_sort(arr,start,p-1);				//this shows that this function is recursive...
		quick_sort(arr,p+1,end);
	}
}

int main(){
	int size,*arr,i;
	scanf("%d",&size);
	arr=(int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int start=0,end=size-1;
	
	quick_sort(arr,start,end);					//calling the quick_sort
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
