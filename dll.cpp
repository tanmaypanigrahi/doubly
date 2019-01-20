#include<iostream>
using namespace std;
class node
{
	public:
	//data
	int data;
	//pointer to next node
	node * next;
	//pointer to previous
	node * prev;
	//constructor to make next pointer to null
	node()
	{
		next=NULL;
		prev=NULL;
	}
	
};
class dll
{
	public:
	node * head;
	dll()
	{
		head=NULL;
	}
	void insert(int value)
	{
		node * temp=new node;
		temp->data=value;
		//first node
		if(head==NULL)
		{
		head=temp;	
		}
		//other node
		else
		{
			node * current=head;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
			temp->prev=current;
			current=temp;
		}
		
	}
	void insertat(int pos,int val)
	{
		node * current=new node;
		node *x=new node;
		node * temp=new node;
		int i=0;   
		current=head;
		x=head;
		int a=0;
		while(current->next!=NULL)
		{
			a++;
			current=current->next;
		}
		a++;
		if(pos<=a && pos>0)
		{
			while(i<pos-1)
			{
				x=x->next;
				i++;
			}
			temp->data=val;
			temp->next=x->next;
			(x->next)->prev=temp;
			temp->prev=x;
			x->next=temp;
	   }
		else
		{
	 	cout<<"linked list does not contain that many elements"<<endl;
	 	}
	}
	void delet()
	{
	node * current=new node;
	node * temp=new node;
	current=head;
	while(current->next->next!=NULL)
	{
		current=current->next;
	}
	temp=current->next;
	current->next=NULL;
	temp->prev=NULL;
	delete temp;
	}
	void deleteat(int pos)
	{
		node * temp=new node;
		node * current=new node;
		current=head;
		if(pos==1)
		{
			temp=head;
			head=temp->next;
			head->prev=NULL;
			temp->next=NULL;
			delete temp;
		}
		else
		{
			int i=1;
			while(i<pos-1)
			{
				i++;
				current=current->next;
			}
			temp=current->next;
			current->next=temp->next;
			temp->next->prev=current;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
	}
	void display()
	{
		int i=1;
		node * current=head;
		while(current!=NULL)
		{
			cout<<current->data<<"->";
			current=current->next;
			i++;
		}
		cout<<"NULL";
		cout<<endl;
		cout<<"number of elements ="<<i-1<<endl;
	}
};
int main()
{
	dll d1;
	d1.insert(1);
	d1.insert(2);
	d1.insert(3);
	d1.insert(4);
	d1.display();
	d1.delet();
	d1.display();
	d1.insertat(2,3);
	d1.display();
	d1.deleteat(2);
	d1.display();
}
