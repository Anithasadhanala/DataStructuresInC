#include<stdio.h>
int* finding_sorted_arr(int size,int *arr){
	int i,j,min;
	for (i=0;i<size;i++){
		for(j=i;j<size;j++){
			min=arr[i];
			if(min>arr[j]){
				min=arr[j];
				arr[j]=arr[i];
				arr[i]=min;
			}
		}
	}
	return arr;
}

int finding_ind_of_search(int *arr2,int siz,int search){
	int beg=0,mid,end=siz-1;
	mid=((beg+end)/2)+1;
	
	while(1){
		if(arr2[mid]==search){
			return mid;
		}
		else if(arr2[mid]<search){
			beg=mid+1;
			mid=((beg+end)/2)+1;
		}
		else if(arr2[mid]>search){
			end=mid;
			mid=((beg+end)/2)+1;
		}
	}
	return mid;
}
void main(){
	int i,arr[100],siz,search,index,*sorted_arr;
	scanf("%d%d",&siz,&search);

	for(i=0;i<siz;i++){
		scanf("%d",&arr[i]);
	}
	sorted_arr=finding_sorted_arr(siz,arr);

	index=finding_ind_of_search(sorted_arr,siz,search);

	printf("Index of search is: %d",index);
	
	
	
}
