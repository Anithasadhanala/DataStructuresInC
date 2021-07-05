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
std *adding_node_at_a_postion(std *head,int adding,int position){		//****adding the node at a position function******
	std *current2=malloc(sizeof(std));
	std *ptr=head;
	int count=0;
	
	current2->data=position;
	current2->link=NULL;
	
	while(count<position-2){
		ptr=ptr->link;
		count++;
	}
	current2->link=ptr->link;
	ptr->link=current2;
	
	return head;
	
}
	
int main(){
	int number,i,no_nodes,adding,position;
	printf("Enter no_nodes: \n");
	scanf("%d",&no_nodes);
	printf("Enter adding_element and the position: \n");
	scanf("%d%d",&adding,&position);
	printf("Enter elements: \n");
	scanf("%d",&number);
	
	std *head=malloc(sizeof(std));							//creating head node
	head->data=number;
	head->link=NULL;
	
	if(no_nodes>1){											
		head=creating_more_nodes(head,no_nodes);
	}
	printf("before adding the element: \n");
	
	std*ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	
	head=adding_node_at_a_postion(head,adding,position);   //*******calling the function of adding a node at a given position*******
	
	printf("after addding node at given position: ");
	
	ptr=head;
	while(ptr!=NULL){								
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}

