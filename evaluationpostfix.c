#include<stdio.h>
#include<string.h>
#define MAX 50
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
int isoperand(char x)
{
	if(x>='0'&&x<='9')
	return 1;
	else
	return 0;
}
int EvaluatePostfix(char post[])
{
	stack s;
	s.top=-1;
	int op1,op2,i,v;
	char x;
	for(i=0;i<strlen(post);i++)
	{
		x=post[i];
		
		if(isoperand(x))
		push(&s,(int)x-'0');
	
	else
	{//X IS OPERATOR
		op2=pop(&s);
		op1=pop(&s);
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
return pop(&s);
}
int main()
{
	char post[10];

	printf(" enter postfix expression \n");
	gets(post);
	
printf(" result = %d",EvaluatePostfix(post));
return 0;
}
