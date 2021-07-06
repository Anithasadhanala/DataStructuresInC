#include<stdio.h>
#include<stdlib.h>

struct Nodes{
	int data;
	struct Nodes *link;									//creating structure of a node
};
typedef struct Nodes std;

std *creating_more_nodes(std *head,int no_nodes){		// adding the nodes
	int number,i;
	
	std *ptr;											
	ptr=head;
	
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
std *adding_node_at_last(std *head,int adding){
	
	std *current2=malloc(sizeof(std));
	current2->data=adding;
	current2->link=NULL;
	
	std *ptr;
	ptr=head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	ptr->link=current2;
	return head;
}

int main(){
	int number,i,no_nodes,adding;
	printf("Enter no_nodes: ");
	scanf("%d",&no_nodes);
	printf("Enter adding_element: ");
	scanf("%d",&adding);
	printf("Enter elements: ");
	scanf("%d",&number);
	
	std *head=malloc(sizeof(std));							//creating head node
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){											
		head=creating_more_nodes(head,no_nodes);
	}
	printf("before adding the element: ");
	std*ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	head=adding_node_at_last(head,adding);            //*******calling the function of adding a node at last*******
	
	printf("after addding at last: ");
	
	ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}
