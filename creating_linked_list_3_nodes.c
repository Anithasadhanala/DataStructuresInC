#include<stdio.h>
#include<stdlib.h>

struct Friends{										//creating the node structure
	int nums;
	struct Friends *link;
};
typedef struct Friends std;							//simplifing the calling the node structure

int main(){
	int number,number2,number3;
    scanf("%d%d%d",&number,&number2,&number3);
    
	std *head=malloc(sizeof(std));					//allocating memory to head node
	head->nums=number;
	head->link=NULL;
	
	std *current=malloc(sizeof(std));				//second node memory allocation
	current->nums=number2;
	current->link=NULL;
	head->link=current;
	
	current=malloc(sizeof(std));					//if we use the new node for the third node
	current->nums=number3;							// then it consumes more memory
	current->link=NULL;
	head->link->link=current;						// this points to the second node and so,that new third node's 
													//name is second node's name by allocating new memory(no need to init)
	current=head;							// for itellating we use the last nodes's name
	while(current!=NULL){
		printf("%d ",current->nums);
		current=current->link;
	}
}
