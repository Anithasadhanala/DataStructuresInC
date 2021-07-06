#include<stdio.h>
#include<stdlib.h>

struct Nodes{											//creating structure of a node
	int data;
	struct Nodes *link;
};
typedef struct Nodes std;

std *inserting_more_nodes(std *head,int no_nodes){		//creating more nodes function definition
	int i,number;
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

std *deleting_node_at_a_position(std *head,int position_del){ //******deleting a node at a position function definition*****
	int count=0;
	std *ptr=head;
	std *ptr2=head;
	
	while(count<position_del-1){
		count+=1;
		ptr2=ptr;
		ptr=ptr->link;
	}	
	ptr2->link=ptr->link;
	free(ptr);
	ptr=NULL;
	
	return head;
}

int main(){
	int no_nodes,number,position_del;
	printf("Enter no_nodes: ");
	scanf("%d",&no_nodes);
	printf("Enter deleting node's position: ");
	scanf("%d",&position_del);
	printf("Enter elements: ");
	scanf("%d",&number);

	
	std *head=malloc(sizeof(std));
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){
		head=inserting_more_nodes(head,no_nodes);
	}
	std *ptr=head;
	
	printf("Before deleting a node: ");
	
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	head=deleting_node_at_a_position(head,position_del);		//***********calling the deleting a node function*******
	
	printf("After deleting the node: ");
	
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}

