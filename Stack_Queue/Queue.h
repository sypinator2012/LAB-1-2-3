#include "stdafx.h"
#include "Item.h"

using namespace std;

struct Queue
{
private:
	struct Link
	{
		Link(Item i,Link* n,Link* p)
		{
			item = i;
			Next = n;
			Prev = p;
		}
		Item item;
		Link *Next,*Prev;
	} *Top,*Bottom;
public:
	Queue()
	{
		Top = Bottom = NULL;
	}
	void Push(Item i)
	{
		Top = new Link(i,Top,NULL);
		if(Top->Next!=NULL)
			Top->Next->Prev = Top;
		if(Bottom==NULL)
			Bottom=Top;
	}
	Item Pop()
	{
		if(Bottom==NULL)
			return 0;
		Item t = Bottom->item;
		Link* temp = Bottom;
		if(Bottom==Top)
			Bottom=Top=NULL;
		else
		{
		Bottom = Bottom->Prev;
		Bottom->Next=NULL;
		}
		delete temp;
		return t;
	}
	bool Empty()
	{
		return (Top==NULL);
	}
	void Show()
	{
		cout<<"          ---   QUEUE   ---"<<endl;
		cout<<"TOP ---> ";
		if(Top==NULL)
			cout<<"|__EMPTY LIST__"<<endl;
		else
		for(Link* t=Top;t!=NULL;t=t->Next)
		{
			if(t==Bottom)
				cout<<"END ---> ";
			if((t!=Top)&&(t!=Bottom))
				cout<<"         ";
			cout<<"|"<<t->item<<endl;
			cout<<"         ___________________"<<endl;
		}
		cout<<"          --- QUEUE END ---"<<endl<<endl;
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