#include <iostream>
#include <string.h>
using namespace std;
const int Max = 20;
class Infix
{
	char stack[Max], target[Max];
	char *s, *t;
	int top;
	public:
		Infix();
		int priority(char c);
		void convert();
		void push(char c);
		char pop();
		void setExpr(char *str);
		void show();
};

Infix::Infix()
{
	top = -1;
	strcpy(stack, "");
	strcpy(target, "");
	t = target;
	s = " ";
};

void Infix::setExpr(char *str)
{
	s = str;
}

void Infix::push(char c)
{
	if(top==Max-1)
		cout<<"\nStack is Full...!";
	else
	{
		top++;
		stack[top] = c;
	}
}

char Infix::pop()
{
	char c;
	if(top==-1)
	{
		cout<<"\nStack is Empty...!";
		return 0;	
	}
	else
	{
		c = stack[top];
		top--;
		return c;
	}
}

int Infix::priority(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return 0;
}

void Infix::convert() 
{
	while(*s)
	{
		if(*s==' ' || *s=='\t')
		{
			continue;
			s++;
		}
		if(isalpha(*s) || isdigit(*s))
		{
			while(isalpha(*s) || isdigit(*s))
			{
				*t = *s;
				t++;
				s++;
			}
		}
		if(*s=='(')
		{
			push(*s);
			s++;
		}
		char opr;
		if(*s=='+' || *s=='-' || *s=='*' || *s=='/')
		{
			if(top!=-1)
			{
				opr = pop();
				while(priority(opr) >= priority(*s))
				{
					*t = opr;
					t++;
					opr = pop();	
				}	
				push(opr);
				push(*s);
			}	
			else
				push(*s);
			s++;
		}
		if(*s==')')
		{
			opr = pop();
			while(opr != ')')
			{
				*t = opr;
				t++;
				opr = pop();
			}
			s++;
		}
	}
	while(top!=-1)
	{
		*t = pop();
		t++;
	}
	*t = '\0';
}

void Infix::show()
{
	cout<<target;
}

int main()
{
	Infix i;
	char expr[Max];
	cout<<"\nEnter Infix Expression : ";
	cin.getline(expr, Max);
	
	i.setExpr(expr);
	i.convert();
	
	cout<<"\nPostfix Expression : ";
	i.show();
	return 0;
}
