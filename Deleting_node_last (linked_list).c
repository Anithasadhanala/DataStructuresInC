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

std *deleting_node_at_last(std *head){					//******callind the deleting a node at the last function******
	std*ptr=head;
	std*ptr2=head;
	
	while(ptr->link!=NULL){
		ptr2=ptr;
		ptr=ptr->link;
	
	
	
	}
	ptr2->link=NULL;
	free(ptr);
	ptr=NULL;
	
	return head;
}

int main(){
	int number,i,no_nodes;
	printf("Enter no_nodes: \n");
	scanf("%d",&no_nodes);
	printf("Enter elements: \n");
	scanf("%d",&number);
	
	std *head=malloc(sizeof(std));							//creating head node
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){											
		head=creating_more_nodes(head,no_nodes);
	}
	printf("before deleting the element: \n");
	
	std*ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	head=deleting_node_at_last(head);   //*******calling the function of deleting a node *******
	
	printf("after deleting last node: ");
	
	ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}

