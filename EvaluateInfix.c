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
int isempty(stack *s)
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
int stacktop(stack *s)
{
	return s->a[s->top];
}
int isoperand(char x)
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9'))
	return 1;
	else
	return 0;
}
int icp(int x)
{
	switch(x)
	{
		case '(':return 3;
		case '+':
		case'-':return 1;
		case '*':
		case '%':
	    case '/':return 2;
	    
	}
	return -1;
}
int isp(int x)
{
	switch(x)
	{
		case '(':return 0;
		case '+':
		case'-':return 1;
		case '*':
		case '%':
	    case '/':return 2;
	    
	}
	return -1;
}
void convert(char infix[],char post[])
{
	stack s;
	s.top=-1;
	int i,k=0;
	int x,ele;
	
	for(i=0;i<strlen(infix);i++)
	{
		x=infix[i];
		
		if(x=='(')
		push(&s,x);
		
		else if(x==')')
		{
			while(1)
			{
			 ele=pop(&s);
				if(ele=='(')
				break;
				post[k++]=ele;
			}
			}
		
		else if(isoperand(x))
		post[k++]=x;
		
		else if(isempty(&s))
		push(&s,x);
		else if(icp(x)>isp(stacktop(&s)))
		push(&s,x);
		else
		{
			while((isempty(&s)==0)&&(icp(x)<=isp(stacktop(&s))))
			{
				ele=pop(&s);
			post[k++]=ele;
			}
			push(&s,x);
		}
		
	}//for
	while(isempty(&s)==0)
	{
		ele=pop(&s);
		post[k++]=ele;
	}
	post[k]='\0';
		
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
	{
		op1=pop(&s);
		op2=pop(&s);
		switch(x)
		{
			case '+':v=op2+op1;break;
			case '-':v=op2-op1;break;
			case '*':v=op2*op1;break;
			case '/':v=op2/op1;break;
			case '%': v=op2%op1;break;
		}
		push(&s,v);
	}
	
}
return pop(&s);
}
	int main()
	{
		char infix[50];
		char post[50];
		printf("\n enter infix expression\n");
		gets(infix);
		convert(infix,post);
		
		printf("result n = %d\n",EvaluateInfix(post));
		return 0;
	}
	


