#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct
{node *start;
}LL;

//insertEnd() of Singly LL
void Enqueue(LL *l,int ele)
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
//display() of Singly LL
void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("Queue is empty\n");
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
//deleteBeginning() of Singly LL
int Dequeue(LL *l)
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

int Queuefront(LL *l)
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
		printf("1:ENQUE\n2:DEQUEUE\n3:QUEUEFRONT\n4:DISPLAY\n5:EXIT\n");
		printf(" enter choice\n");
		scanf("%d",&ch);
		if(ch==5)
		break;
		switch(ch)
		{
			case 1:printf("enter element to enque\n");
			       scanf("%d",&ele);
			       Enqueue(&l1,ele);
			       printf("updated queue\n");
			       display(&l1);
			       break;
			case 2: ele=Dequeue(&l1);
			         if(ele==-1)
					 printf("queue underflow\n");
					 else
					 printf("element dequeued =%d\n",ele);
					 printf("updated queue\n");
			       display(&l1);
					 break;
			case 3:ele=Queuefront(&l1);
			       if(ele==-1)
					 printf("queue underflow\n");
					 else
					 printf("queue front element =%d\n",ele);
					 break;
			case 4: display(&l1);break;
			default:printf("invalid choice\n");      
		}
	}
return 0;
}
