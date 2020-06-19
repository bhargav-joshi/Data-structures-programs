#include<stdio.h>
#define MAX 10
typedef struct
{
	int a[MAX];
	int top;
}stack;
void push(stack *s,int ele)
{
	if(s->top==MAX-1)
	{
	printf("stack overflow\n");
	return;
    }
    s->top++;
    s->a[s->top]=ele;
}
int isempty(stack *s)
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
int stacktop(stack *s)
{
	if(isempty(s))
	return -1;
	return s->a[s->top];
}
int pop(stack *s)
{
	int x;
	if(isempty(s))
	return -1;
	x=s->a[s->top];
	s->top--;
	return x;
	
}
void display(stack *s)
{int i;
	if(isempty(s))
	
	{
	printf("stack underflow\n");
	return;
    }
    else
    {
    	for(i=s->top;i>=0;i--)
    	printf(" %d\t",s->a[i]);
    	printf("\n");
    	
	}
}
int main()
{
	int ch,ele;
	stack s;
	s.top=-1;
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
			       push(&s,ele);
			       break;
			case 2: ele=pop(&s);
			         if(ele==-1)
					 printf("stack underflow\n");
					 else
					 printf("element popped =%d\n",ele);
					 break;
			case 3:ele=stacktop(&s);
			       if(ele==-1)
					 printf("stack underflow\n");
					 else
					 printf("stack top element =%d\n",ele);
					 break;
			case 4: display(&s);break;
			default:printf("invalid choice\n");      
		}
	}
return 0;
}
