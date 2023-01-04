#include <iostream>
using namespace std;

struct node
{
	int seat;
	int status;
	string id;
	struct node *next;
	struct node *prev;
}*head, *tail, *temp, *p;

class cinemax
{
	public:
		cinemax()
		{
			head = tail = NULL;
		}
		void create();
		void display();
		void book();
		void cancel();
};

void cinemax::create()
{
	temp = new node;
	temp->seat = 1;
	temp->status=0;
	temp->id="null";
	temp->next=NULL;
	temp->prev=NULL;
	head = tail = temp;
	for(int i=2; i<=70; i++)
	{
		p = new node;
		p->seat = i;
		p->status = 0;
		p->id = "null";
		tail->next = p;
		p->prev = tail;
		tail = p;
		tail->next = head;
		head->prev = tail;
	}
}

void cinemax::display()
{
	temp = head;
	cout<<"\n================================================================================================";
	cout<<"\n*****************************************| SCREEN THIS WAY |************************************";
	cout<<"\n================================================================================================\n";
	while(temp->next != head)
	{
		if(temp->seat/10==0)
			cout<<"S0"<<temp->seat<<" : ";
		else
			cout<<"S"<<temp->seat<<" : ";
		
		if(temp->status==0)
			cout<<"|___| ";
		else
			cout<<"|_B_| ";
		
		if(temp->seat%7==0)
			cout<<endl;
		temp = temp->next;
	}
	if(temp->seat/10==0)
		cout<<"S0"<<temp->seat<<" : ";
	else
		cout<<"S"<<temp->seat<<" : ";
	
	if(temp->status==0)
		cout<<"|___| ";
	else
		cout<<"|_B_| ";
}

void cinemax::book()
{
	int x;
	string y;
	label:
	cout<<"\nEnter Seat No : ";
	cin>>x;
	if(x<1 || x>70)
	{
		cout<<"\nInvalid seat No..Please Enter in between (1-70) : ";
		goto label;
	}
	else
	{
		temp = head;
		while(temp->seat != x)
		{
			temp = temp->next;
		}
		if(temp->status==1)
			cout<<"\nSeat Already Booked...!";
		else
		{
			cout<<"\nEnter ID no : ";
			cin>>y;
			
			temp->status = 1;
			temp->id = y;
		}
	}
}

void cinemax::cancel()
{
	int x;
	string y;
	label1:
	cout<<"\nEnter Seat No : ";
	cin>>x;
	if(x<1 || x>70)
	{
		cout<<"\nInvalid Seat No...Enter valid Seat No in between (1-70) : ";
		goto label1;	
	}	
	else
	{
		temp = head;
		while(temp->seat!=x)
		{
			temp = temp->next;
		}
		if(temp->status==0)
			cout<<"\nSeat Not Booked Yet...!";
		else
		{
			cout<<"\nEnter ID No : ";
			cin>>y;
			if(temp->id==y)
			{
				temp->status = 0;
				temp->id="null";
			}
			else
				cout<<"\nInvalid ID...Seat Not Cancelled...!";
		}
	}
}

int main()
{
	cinemax c;
	c.create();
	int ch;
	bool flag = true;
	while(flag)
	{
		cout<<"\n\n\n\n================================================================================================";
		cout<<"\n***************************************| CINEMAX MOVIE THEATER | *******************************";
		cout<<"\n================================================================================================";
		cout<<"\n\t1. Current Seat Status";
		cout<<"\n\t2. Book Seat";
		cout<<"\n\t3. Cancel Seat";
		cout<<"\n\t4. Exit";
		cout<<"\n================================================================================================";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		cout<<"\n================================================================================================";
		switch(ch)
		{
			case 1:
				c.display();
				break;
			case 2:
				c.book();
				break;
			case 3:
				c.cancel();
				break;
			case 4:
				flag = false;
				cout<<"\n**********************************| THANK YOU |*************************************************";
				cout<<"\n================================================================================================";
				break;
			default:
				cout<<"\nInvalid Choice...Enter Valid Choice...!";
		}
		cout<<"\n================================================================================================";
	}
	return 0;
}
