#include <iostream>
using namespace std;
const int Max = 5;

class PizzaParlour
{
	int front;
	int rear;
	int order[Max];
	public:
		PizzaParlour()
		{
			front = rear = -1;
		}
		bool enQueue(int val);
		void deQueue();
		void display();
};

bool PizzaParlour::enQueue(int val)
{
	int pos = (rear+1)%Max;
	if(front == pos)
	{
		cout<<"\nCafe is Full...Wait for some time...!";
		return 0;	
	}
	else
	{
		if(rear == -1)
		{
			front = rear = 0;
			order[rear] = val;
			return 1;
		}
		else
		{
			rear = pos;
			order[rear] = val;
			return 1;
		}
	}
}

void PizzaParlour::deQueue()
{
	if(rear==-1)
		cout<<"\nCafe is empty...!";
	else
	{
		cout<<"\nOrder No : "<<order[front]<<" is served..!";
		if(front==rear)
			front = rear = -1;
		else
			front = (front+1)%Max;
	}
}

void PizzaParlour::display()
{
	if(rear==-1)
		cout<<"\nCafe is empty..!";
	else
	{
		cout<<"\nPending Orders are : ";
		for(int i=front; i!=rear; i=(i+1)%Max)
		{
			cout<<order[i]<<" ";
		}
		cout<<order[rear];
	}
}

int main()
{
	PizzaParlour p;
	int ch, id = 0;
	bool flag = true;
	while(flag)
	{
		cout<<"\n===========================================================";
		cout<<"\n***********************| PIZZA PARLOUR |*******************";
		cout<<"\n===========================================================";
		cout<<"\n\t1. Accept Order";
		cout<<"\n\t2. Served Order";
		cout<<"\n\t3. Display Order";
		cout<<"\n\t4. Exit";
		cout<<"\n===========================================================";
		cout<<"\nEnter Your choice : ";
		cin>>ch;
		cout<<"\n===========================================================";
		switch(ch)
		{
			case 1:
				id++;
				if(p.enQueue(id))
					cout<<"\nYour Order Accepted, Order ID : "<<id;
				else
					id--;
				break;
			case 2:
				p.deQueue();
				break;
			case 3:
				p.display();
				break;
			case 4:
				flag = false;
				cout<<"\n************************| THANK YOU |*************************";
				cout<<"\n===========================================================";
				break;
			default:
				cout<<"\nInvalid choice...Enter Valid Choice...!";
		}
		cout<<"\n===========================================================";
	}
	return 0;
}
