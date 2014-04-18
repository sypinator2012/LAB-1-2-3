#include "stdafx.h"

using namespace std;

typedef int Item;

typedef struct node
{
	Item item;
	node *Next;
	node(int i,node* n)
	{ item = i;Next = n;}
} *link, *Node;

struct List
{
private:
	link end;

public:
	link head;
	List()
	{
		head = end=NULL;
	}
	void Init()
	{
		end = new node(0,NULL);
		head = new node(0,end);
	}
	void Unload()
	{
		for(link t = head;t!=NULL;t=head)
		{
			head=head->Next;
			delete t;
		}
	}
	void AddBefore(const Item& cur,const Item& i)
	{
		link t,temp;
		end->item = cur;
		for(t=head;t->Next->item!=cur;t=t->Next);
		temp = new node(i,t->Next);
		t->Next = temp;
	}
	void AddAfter(const Item& cur,const Item& i)
	{
		link t,temp;
		end->item = cur;
		for(t=head;t->Next->item!=cur;t=t->Next);
		if(t->Next != end)
			t=t->Next;
		temp = new node(i,t->Next);
		t->Next = temp;
	}
	void DeleteItem(const Item& i)
	{
		link t,temp;
		end->item = i;
		for(t=head;t->Next->item!=i;t=t->Next);
		if(t->Next==end)
			return;
		temp = t->Next;
		t->Next = t->Next->Next;
		delete temp;
	}
	void Show()
	{
		cout<<"HEAD-->";
		for(link t = head->Next;t!=end;t=t->Next)
			cout<<t->item<<"-->";
		cout<<"END"<<endl;
	}
};




