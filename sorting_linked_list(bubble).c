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

std *sorting_nodes(std *head,int no_nodes){			//*******sorting_nodes function definition******
	int i,j,copy;
	
	for(i=no_nodes-1;i>0;i--){						//here, we iterate only for 4 times if no_nodes=5
		std *ptr=head;								//here,ptr and ptr2 always start from head as they at the end at last iteration
		std *ptr2=NULL;
		for(j=i;j>0;j--){							//no_iterations=n-1
			ptr2=ptr;
			ptr=ptr->link;
			if(ptr2->data>ptr->data){
				copy=ptr2->data;
				ptr2->data=ptr->data;
				ptr->data=copy;
			}
		}
	}
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
	
	printf("Before sorting: ");
	
	std *ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	head=sorting_nodes(head,no_nodes);						//*********calling sorting the nodes function*****
	
	printf("\n");
	printf("After sorting: ");
	
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}
