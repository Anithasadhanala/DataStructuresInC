#include<stdio.h>
#include<stdlib.h>

struct Nodes{											//creating node structure
	int data;
	struct Nodes *link;
};
typedef struct Nodes std;

std *creating_other_nodes(std*head,int no_nodes){		// function for inserting the nodes
	int i,number;
	
	std *ptr;											//ptr is for itellating so,that we add a node after head
	ptr=head;
	
	for(i=0;i<no_nodes-1;i++){
		
		scanf("%d",&number);
		
		std *current=malloc(sizeof(std));			// second node to infinity are named by allocating memory as "current"
		current->data=number;
		current->link=NULL;
		
		ptr->link=current;
		ptr=ptr->link;								//incrementing the ptr for adding another node after adding the current
	}
	return head;
}

int main(){

	int no_nodes,i,number;
	
	scanf("%d",&no_nodes);
	scanf("%d",&number);
	
	std *head=malloc(sizeof(std));					//creating head node
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){									//if no_nodes>1 only we execute the function
		head=creating_other_nodes(head,no_nodes);
	}
	std*ptr=head;									//creating ptr in main function for itellating and printing
	
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
	
	
}
