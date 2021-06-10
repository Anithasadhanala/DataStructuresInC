#include<stdio.h>
int finding_min(int a,int b){
	int temp;
	temp=a;
	if(b<a){
		a=b;
		b=temp;
	}
	return a;
}
int main(){
	int arr[100],size,search,f1,f2,fs,offset,a,i,m=0,pass;
	scanf("%d%d",&size,&search);
	for (i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	f1=0;
	f2=1;
	
	while(fs<size){											//f(k) in actual fibonacci
		fs=f1+f2;
		f1=f2;
		f2=fs;
	}
	offset=-1;												//offset initialising
	while(fs>1){
		
		a=finding_min(offset+f1,size-1);					//a is very important***
		if(search==arr[a]){
			printf("Index of search is: %d",a);
			m=1;
			break;
		}
		else if (search>arr[a]){							//search>f(k) then (offset=a) and (k=k-1)
			offset=a;
			fs=f2;
			f2=f1;
			f1=fs-f2;
		}
		else if (search<arr[a]){							//search<f(k)  then (k=k-2)
			fs=f1;
			f2=f2-f1;
			f1=fs-f2;
		}
	}
	if(f2 && arr[offset+1]==search){						 
		if(m==1){
			pass;											 //here we get two outputs if the search is not the last so,m is used**** inorder to skip repetition
		}
		else{											     // if the search is at the last index then the above steps will not give the answer
			printf("Index of search is: %d",offset+1);
			m=1;
		}
		
	}
	if(m==0){											
		printf("Search is absent");
	}
	
}
