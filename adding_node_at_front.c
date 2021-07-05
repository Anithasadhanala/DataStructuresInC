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

std *adding_node_at_front(std*head,int adding){					//adding the new node at front
	std *current2=malloc(sizeof(std));
	current2->data=adding;
	current2->link=NULL;
	
	current2->link=head;
	head=current2;
	
	return head;
}

int main(){
	int number,i,no_nodes,adding;
	printf("Enter no_nodes: \n");
	scanf("%d",&no_nodes);
	printf("Enter adding_element: \n");
	scanf("%d",&adding);
	printf("Enter elements: \n");
	scanf("%d",&number);
	
	
	
	std *head=malloc(sizeof(std));							//creating head node
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){											
		head=creating_more_nodes(head,no_nodes);
	}
	
	printf("before adding: ");
	
	std*ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	head=adding_node_at_front(head,adding);            //*******calling the function of adding a node at front*******
	
	printf("after addding: ");
	
	ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}
