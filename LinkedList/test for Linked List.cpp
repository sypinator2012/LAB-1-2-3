// test for Linked List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char c ='0';
	Item cur,i;
	List list;
	list.Init();
	list.Show();
	while((int)c!=27)
	{
		cout<<"1 - Add Before Item"<<endl;
		cout<<"2 - Add After Item"<<endl;
		cout<<"3 - Delete Item"<<endl;
		cout<<"ESC - EXIT"<<endl;
		c=_getch();
		switch(c)
		{
		case '1':
			cout<<"Input Item in the LIST:"<<endl;
			cin>>cur;
			cout<<"Input Item for ADD:"<<endl;
			cin>>i;
			list.AddBefore(cur,i);
			break;
		case '2':
			cout<<"Input Item in the LIST:"<<endl;
			cin>>cur;
			cout<<"Input Item for ADD:"<<endl;
			cin>>i;
			list.AddAfter(cur,i);
			break;
		case '3':
			cout<<"Input Item in the LIST:"<<endl;
			cin>>i;
			list.DeleteItem(i);
			break;
		default:;
		}
		system("cls");
		list.Show();
	}
	return 0;
}