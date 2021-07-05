#include<stdio.h>
#include<stdlib.h>

struct Friends{
	int nums;
	struct Friends *link;
};
typedef struct Friends std;

int main(){
	int number,number2,number3;
    	scanf("%d%d%d",&number,&number2,&number3);
    
    
	std *head=malloc(sizeof(std));
	head->nums=number;
	head->link=NULL;
	
	std *current=malloc(sizeof(std));
	current->nums=number2;
	current->link=NULL;				
	head->link=current;
	
	current=malloc(sizeof(std));
	current->nums=number3;
	current->link=NULL;
	head->link->link=current;
	
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->nums);
		ptr=ptr->link;
	}
}
