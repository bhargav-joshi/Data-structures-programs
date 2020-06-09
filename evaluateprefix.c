#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 15
typedef struct
{
	int a[MAX];
	int top;
	
}stack;

void push(stack *s,int ele)
{
	s->top++;
	s->a[s->top]=ele;
}
int pop(stack *s)
{
	int x;
	x=s->a[s->top];
	s->top--;
	return x;
}
int main()
{
	stack s;
	s.top=-1;
	char pre[10];
	int op1,op2,i,v;
	char x;
	printf(" enter prefix expression \n");
	gets(pre);
	for(i=strlen(pre)-1;i>=0;i--)
	{
		x=pre[i];
		
		if(isdigit(x))
		push(&s,(int)x-'0');
	
	else
	{
		op1=pop(&s);
		op2=pop(&s);
		switch(x)
		{
			case '+':v=op1+op2;break;
			case '-':v=op1-op2;break;
			case '*':v=op1*op2;break;
			case '/':v=op1/op2;break;
			case '%': v=op1%op2;break;
		}
		push(&s,v);
	}
	
}
printf(" result = %d",pop(&s));
return 0;
}
