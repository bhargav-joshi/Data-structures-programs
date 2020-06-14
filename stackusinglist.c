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



void push(LL *l,int ele)//insertBeginning() of Singly LL
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	
	newrec->next=l->start;
	l->start=newrec;	
}

void display(LL *l)//display of Singly Ll
{
	node *p;
	if(l->start==NULL)
	{
		printf("stack is empty\n");
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

int pop(LL *l)//deleteBeginning() of Singly LL
{//p must refer to node to delete
	node *p;
	if(l->start==NULL)
	{
		return -1;
	}
	p=l->start;
    l->start=l->start->next;
   
	return p->data;
}

int stacktop(LL *l)
{
	if(l->start==NULL)
	return -1;
	else
	return l->start->data;
}

int main()
{
	int ch,ele;
LL l1;
l1.start=NULL;
	while(1)
	{
		printf("1:push\n2:pop\n3:stacktop\n4:display\n5:exit\n");
		printf(" enter choice\n");
		scanf("%d",&ch);
		if(ch==5)
		break;
		switch(ch)
		{
			case 1:printf("enter element to push\n");
			       scanf("%d",&ele);
			       push(&l1,ele);
			       printf("updated stack\n");
			       display(&l1);
			       break;
			case 2: ele=pop(&l1);
			         if(ele==-1)
					 printf("stack underflow\n");
					 else
					 printf("element popped =%d\n",ele);
					  printf("updated stack\n");
			       display(&l1);
					 break;
			case 3:ele=stacktop(&l1);
			       if(ele==-1)
					 printf("stack underflow\n");
					 else
					 printf("stack top element =%d\n",ele);
					 break;
			case 4: display(&l1);break;
			default:printf("invalid choice\n");      
		}
	}
return 0;
}
