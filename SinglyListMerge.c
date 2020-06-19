#include<stdio.h>//not for devcpp
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct
{node *start;
}LL;

void insertEnd(LL *l,int ele)
{
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=NULL;
	
	if(l->start==NULL)
	l->start=newrec;
	
	else
	{
		p=l->start;
		while(p->next!=NULL)
		p=p->next;
		
		p->next=newrec;
		
	}
}
void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	p=l->start;
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void merge(LL *l1,LL *l2)
{
	node *p;
	p=l1->start;
	
	while(p->next!=NULL)
	p=p->next;	
	p->next=l2->start;
	l2->start=NULL;//l2 is empty now
}

int main()
{
	LL l1,l2;
	int n1,n2,ele,i;
    l1.start=NULL;
    l2.start=NULL;
    
    printf(" enter nos elements in first linked list\n ");
    scanf("%d",&n1);
    
     printf(" enter no os elements in second linked list\n ");
    scanf("%d",&n2);
    
    printf(" enter elements in first linked list\n");
    for(i=0;i<n1;i++)
    {
    	printf(" enter %d element \n",(i+1));
    	scanf("%d",&ele);
    	insertEnd(&l1,ele);
	}
	 printf(" enter elements in second linked list\n");
    for(i=0;i<n2;i++)
    {
    	printf(" enter %d element \n",(i+1));
    		scanf("%d",&ele);
    	insertEnd(&l2,ele);
	}
	printf(" first linked list\n");
	display(&l1);
	printf(" second linked list\n");
	display(&l2);
	
	merge(&l1,&l2);
	printf(" after merging\n");
	display(&l1);
	return 0; }
