#include <iostream>
using namespace std;

int size = 100;
char stack[100];

int push(char c, int top)
{
	if(top!=size-1)
	{
		top++;
		stack[top]=c;
	}
	return top;
}

int pop(int top)
{
	if(top!=-1)
	{
		top--;
		return top;
	}
}

int main()
{
	int flag;
	int top = -1;
	char arr[size], x;
	int n;
	cout<<"\nEnter the size of array : ";
	cin>>n;
	cout<<"\nEnter the string : ";
	cin>>arr;
	for(int i=0; i<n; i++)
	{
		x = arr[i];
		if(x=='(' || x=='[' || x== '{')
		{
			top = push(x, top);
		}
		else if(x==')')
		{
			if(stack[top] == '(')
			{
				top = pop(top);
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		else if(x == ']')
		{
			if(stack[top] == '[')
			{
				top = pop(top);
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		else if(x=='}')
		{
			if(stack[top] == '{')
			{
				top = pop(top);
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	if(flag && top==-1)
		cout<<"\nGiven Expression is Well Parentisized..!";
	else
		cout<<"\nGiven Expression is not Well Parentisized..!";
	return 0;
}
