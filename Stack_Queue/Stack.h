#include "stdafx.h"
#include "Item.h"

using namespace std;

struct Stack
{
private:
	struct Link
	{
		Link(Item i,Link* n)
		{
			item = i;
			Next = n;
		}
		Item item;
		Link* Next;
	} *Top;
public:
	Stack()
	{
		Top = NULL;
	}
	void Push(Item i)
	{
		Top = new Link(i,Top);
	}
	Item Pop()
	{
		if(Top==NULL)
			return 0;
		Item t = Top->item;
		Link* temp = Top;
		Top = Top->Next;
		delete temp;
		return t;
	}
	bool Empty()
	{
		return (Top==NULL);
	}
	void Show()
	{
		cout<<"          ---   STACK   ---"<<endl;
		cout<<"TOP ---> ";
		if(Top==NULL)
			cout<<"|__EMPTY LIST__"<<endl;
		else
		for(Link* t=Top;t!=NULL;t=t->Next)
		{
			if(t!=Top)
				cout<<"         ";
			cout<<"|"<<t->item<<endl;
			cout<<"         ____________"<<endl;
		}
		cout<<"          --- STACK END ---"<<endl<<endl;
	}
	void Delete()
	{
		for(Link* t=Top;t!=NULL;t=Top)
		{
			Top=Top->Next;
			delete t;
		}
	}
};