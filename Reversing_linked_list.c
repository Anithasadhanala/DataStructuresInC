#include<stdio.h>
#include<stdlib.h>

struct Nodes{
	int data;
	struct Nodes *link;
};

typedef struct Nodes std;

std *inserting_more_nodes(std *head,int no_nodes){
	int number,i;
	std *ptr=head;
	for(i=0;i<no_nodes-1;i++){
		scanf("%d",&number);
		
		std *current=malloc(sizeof(std));
		current->data=number;
		current->link=NULL;
		
		ptr->link=current;
		ptr=ptr->link;
	}
	return head;
}

std *reversing_nodes(std *head){             // *********function definition of reversing**********
	std *ptr=NULL;
	std *ptr2=NULL;
	
	while(head!=NULL){
		ptr2=head->link;					//here ptr2 points to second node
		head->link=ptr;						//changing head node link as null using the ptr
		ptr=head;							// if we wanted to move the head node last and every time we iterate -
											//-head link only changes using ptr (previous node)
		head=ptr2;							//incrementing head node for changing link of next node using ptr2
	}
	head=ptr;				//after the loop head =NULL and last node is ptr...so,to put last node as head node head=ptr			
	return head;
}

int main(){
	int no_nodes,number;
	printf("Enter no_nodes: ");
	scanf("%d",&no_nodes);
	printf("Enter the elements: ");
	scanf("%d",&number);
	
	std *head=malloc(sizeof(std));
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){
		head=inserting_more_nodes(head,no_nodes);
	}
	
	printf("Before reversing: ");
	
	std *ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
	head=reversing_nodes(head);						//*********calling reversing the nodes function*****
	
	printf("\n");
	printf("After reversing: ");
	
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}
