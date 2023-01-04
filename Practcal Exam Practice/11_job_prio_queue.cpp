#include <iostream>
using namespace std;
const int Max = 5;
class Job
{
	int prio;
	int id;
	friend class Queue;
	public:
		void getData()
		{
			cout<<"\nEnter Job ID : ";
			cin>>id;
			cout<<"\nEnter Job Priority : ";
			cin>>prio;
		}
		void putData()
		{
			cout<<"\n\t"<<id<<"\t"<<prio;
		}
};

class Queue
{
	int front;
	int rear;
	Job queue[Max];
	public:
		Queue()
		{
			front = rear = -1;
		}
		void enQueue();
		void deQueue();
		void display();
		bool isFull();
		bool isEmpty();
};

bool Queue::isEmpty()
{
	if(rear==-1)
		return 1;
	else
		return 0;
}

bool Queue::isFull()
{
	if(rear==Max-1)
		return 1;
	else
		return 0;
}

void Queue::enQueue()
{
	Job j;
	if(isFull())
		cout<<"\nQueue is Full...!";
	else
	{
		j.getData();
		if(isEmpty())
		{
			front = rear = 0;
			queue[rear] = j;
		}
		else
		{
			int i = rear;
			while(rear >= front && queue[i].prio > j.prio)
			{
				queue[i+1] = queue[i];
				i--;
			}
			queue[i+1] = j;
			rear++;
		}
		cout<<"\nJob added successfully...!";
	}
}

void Queue::deQueue()
{
	if(isEmpty())
		cout<<"\nThere is No Job in Queue...!";
	else
	{
		if(front==rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
		cout<<"\nJob deleted successfully...!";
	}
}

void Queue::display()
{
	if(isEmpty())
		cout<<"\nThere is no job in queue...!";
	else
	{
		cout<<"\n\tJob ID\tJob Priority";
		for(int i=front; i<=rear; i++)
		{
			queue[i].putData();
		}
	}
}

int main()
{
	Queue q;
	int ch;
	bool flag = true;
	while(flag)
	{
		cout<<"\n==========================================================";
		cout<<"\n**************************| JOB MENU |********************";
		cout<<"\n==========================================================";
		cout<<"\n\t1. Accept Job";
		cout<<"\n\t2. Delete Job";
		cout<<"\n\t3. Display Job";
		cout<<"\n\t4. Exit";
		cout<<"\n===========================================================";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		cout<<"\n==========================================================";
		switch(ch)
		{
			case 1:
				q.enQueue();
				break;
			case 2:
				q.deQueue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				flag = false;
				cout<<"\n*********************| THANK YOU |******************";
				cout<<"\n==========================================================";
				break;
			default:
				cout<<"\nInvalid choice...Enter Valid choice...!";
		}
		cout<<"\n==========================================================";
	}
	return 0;
}
