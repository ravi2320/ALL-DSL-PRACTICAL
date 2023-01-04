#include <iostream>
using namespace std;
const int Max = 5;

class Queue
{
	int front;
	int rear;
	int queue[5];
	public:
		Queue()
		{
			front = rear = -1;
		}
		bool isFull();
		bool isEmpty();
		void enQueue(int val);
		void deQueue();
		void display();
};

bool Queue::isFull()
{
	if(rear==Max-1)
		return 1;
	else
		return 0;
}

bool Queue::isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

void Queue::enQueue(int val)
{
	if(isFull())
		cout<<"\nQueue is Full...!";
	else
	{
		if(isEmpty())
		{
			front = rear = 0;
			queue[rear] = val;
		}
		else
		{
			rear++;
			queue[rear] = val;
		}
		cout<<"\nJob added Successfully...!";
	}
}

void Queue::deQueue()
{
	if(isEmpty())
		cout<<"\nQueue is Empty...!";
	else
	{
		if(front == rear)
		{
			queue[front] = 0;
			front = -1;
			rear = -1;
		}
		else
		{
			cout<<"\nJob "<<queue[front]<<" Deleted Successfully...!";
			queue[front] = 0;
			front++;		
		}
	}
}

void Queue::display()
{
	if(isEmpty())
		cout<<"\nQueue is Empty...!";
	else
	{
		cout<<"\nAll Job's : ";
		for(int i=front; i<=rear; i++)
		{
			cout<<queue[i]<<" ";
		}
	}
}

int main()
{
	Queue q;
	bool flag = true;
	int ch, id;
	while(flag)
	{
		cout<<"\n===========================================================";
		cout<<"\n*********************| JOB MENU |************************";
		cout<<"\n===========================================================";
		cout<<"\n\t1. ADD JOB";
		cout<<"\n\t2. REMOVE JOB";
		cout<<"\n\t3. DISPLAY JOBS";
		cout<<"\n\t4. EXIT";
		cout<<"\n===========================================================";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		cout<<"\n===========================================================";
		switch(ch)
		{
			case 1:
				cout<<"\nEnter Job ID : ";
				cin>>id;
				q.enQueue(id);
				break;
			case 2:
				q.deQueue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				flag = false;
				cout<<"\n************************| THANK YOU |**********************";
				cout<<"\n===========================================================";
				break;
			default:
				cout<<"\nInvalid choice...Plese Enter Valid choice...!";
		}
		cout<<"\n===========================================================";
	}
	return 0;
}
