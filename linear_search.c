#include<stdio.h>
int main(void){
	int i,arr[100],siz,search,count=0;
	scanf("%d%d",&siz,&search);
	
	for(i=0;i<siz;i++){
		scanf("%d",&arr[i]);
	}
	for (i=0;i<siz;i++){
		if(arr[i]==search){
			printf("index of search: %d",i);
			count=1;
			break;
		}
	}
	if(count==0){
		printf("Search not found");
    }
}
