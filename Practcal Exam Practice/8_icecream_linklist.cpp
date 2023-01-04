#include <iostream>
using namespace std;

struct node 
{
	int data;
	struct node *addr;
}*root, *rootv, *rootb, *roote, *r, *p, *temp;

class Icecream
{
	int flag, i;
	public:
		struct node* Accept(struct node *rp, int n)
		{
			r = rp;
			for(i=0; i<n; i++)
			{
				temp = new node;
				cout<<"\nEnter student "<<i+1<<" : ";
				cin>>temp->data;
				temp->addr = NULL;
				if(r==NULL)
					r = temp;
				else
				{
					p = r;
					while(p->addr!=NULL)
						p = p->addr;
					p->addr = temp;
				}
			}
			return r;
		}
		
		void display(struct node *rp)
		{
			if(rp==NULL)
				cout<<"\nList is Empty...!";
			else
			{
				p = rp;
				while(p!=NULL)
				{
					cout<<p->data<<" ";
					p=p->addr;
				}
			}
			cout<<endl;
		}
		
		void either()
		{
			struct node *temp1, *temp2, *temp3;
			for(temp=root; temp!=NULL; temp=temp->addr)
			{
				flag = 0;
				for(temp1=rootv; temp1!=NULL; temp1=temp1->addr)
				{
					for(temp2=rootb; temp2!=NULL; temp2=temp2->addr)
					{
						if(temp->data==temp1->data || temp->data==temp2->data)
						{
							flag = 1;
							break;
						}
					}	
				}	
				if(flag==1)
				{
					temp3 = new node;
					temp3->data = temp->data;
					temp3->addr = NULL;
					if(roote==NULL)
						roote=temp3;
					else
					{
						p = roote;
						while(p->addr!=NULL)
							p=p->addr;
						p->addr = temp3;
					}
				}
			}
		}
		
		void Only(struct node *r1, struct node *r2)
		{
			for(temp=r1; temp!=NULL; temp=temp->addr)
			{
				flag = 0;
				for(p=r2; p!=NULL; p=p->addr)
				{
					if(temp->data == p->data)
					{
						flag = 1;
						break;
					}
				}
				if(flag==0)
					cout<<temp->data<<" ";
			}
		}
		
		void Both()
		{
			for(temp=rootv; temp!=NULL; temp=temp->addr)
			{
				flag = 0;
				for(p=rootb; p!=NULL; p=p->addr)
				{
					if(temp->data == p->data)
					{
						flag = 1;
						break;
					}
				}
				if(flag==1)
					cout<<temp->data<<" ";
			}
			cout<<endl;
		}
		
};

int main()
{
	int ch, n;
	bool flag = true;
	Icecream i;
	while(flag)
	{
		cout<<"\n\n\n\n===============================================================================";
		cout<<"\n****************************| ICECREAM MENU |**********************************";
		cout<<"\n===============================================================================";
		cout<<"\n\t1. Accept All Student";
		cout<<"\n\t2. Accept student who like Vanilla";
		cout<<"\n\t3. Accept student who like Butterscoach";
		cout<<"\n\t4. Student who like Vanilla";
		cout<<"\n\t5. Student who like Butterscoach";
		cout<<"\n\t6. Student who like both butterscoach and vanilla";
		cout<<"\n\t7. Student who like only vanilla";
		cout<<"\n\t8. Student who like only butterscaoch";
		cout<<"\n\t9. student who like either vanilla or butterscoach";
		cout<<"\n\t10. student who niether like vanilla nor butterscaoch";
		cout<<"\n\t11. Exit";
		cout<<"\n===============================================================================";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		cout<<"\n===============================================================================";
		switch(ch)
		{
			case 1:
				cout<<"\nEnter Total No of student : ";
				cin>>n;
				root = i.Accept(root, n);
				i.display(root);
				break;
			case 2:
				cout<<"\nEnter Total Student who like vanilla : ";
				cin>>n;
				rootv = i.Accept(rootv, n);
				break;
			case 3:
				cout<<"\nEnter Total Student who like Butterscoach : ";
				cin>>n;
				rootb = i.Accept(rootb, n);
				break;
			case 4:
				cout<<"\nStudent who like Vanilla : ";
				i.display(rootv);
				break;
			case 5:
				cout<<"\nStudent who like Butterscoach : ";
				i.display(rootb);
				break;
			case 6:
				cout<<"\nStudent who like Only Vanilla : ";
				i.Only(rootv, rootb);
				break;
			case 7:
				cout<<"\nStudent who like Only Buterscoach : ";
				i.Only(rootb, rootv);
				break;
			case 8:
				cout<<"\nStudent who like Both Buterscoach and Vanilla : ";
				i.Both();
				break;
			case 9:
				cout<<"\nStudent who like either Vanilla or Butterscoach : ";
				i.either();
				i.display(roote);
				break;
			case 10:
				cout<<"\nStudent who like neither Vanilla nor Butterscoach : ";
				i.Only(root, roote);
				break;
			case 11:
				flag = 0;
				cout<<"\n********************************| THANK YOU |*************************************************";
				break;
			default:
				cout<<"\nInvalid choice...Enter Valid choice...!";
		}
		cout<<"\n===============================================================================";
	}
	return 0;
}
