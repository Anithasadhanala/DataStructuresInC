#include<stdio.h>
#include<stdlib.h>

void merging(int*arr,int start,int end,int m,int size){
	int temp[size];
	int i,j,k;
	i=start;
	j=m+1;
	k=start;
	while(i<=m && j<=end){                 //untill we get any sub arr as empty(among the 2 sub_arrs)
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			k++;
			i++;
		}
		else{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	while(i<=m){                         //after empting one of the arr can be unempty
		temp[k]=arr[i];                  //   that unempty can be i so,empting this arr also
		k++;
		i++;
	}
	while(j<=end){						//after empting one of the arr can be unempty
		temp[k]=arr[j];                 //   that unempty can be j so,empting this arr also
		k++;
		j++;
	}
	for(i=start;i<=end;i++){
		arr[i]=temp[i];
	}
}

void merge_sort(int*arr,int size,int start,int end){
	int m;
	if(start<end){
	
		m=(start+end)/2;                          //finding the mid pint for dividing the arr

		merge_sort(arr,size,start,m);             //recursive calls
		merge_sort(arr,size,m+1,end);
	
		merging(arr,start,end,m,size);            //calling merging the elements after division
}
}

int main(){
	int size,*arr,i;
	scanf("%d",&size);
	arr=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int start=0,end=size;
	
	merge_sort(arr,size,start,end);            //calling merge_sort
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}	
	
}
