// Stack_Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stack.h"
#include"Queue.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Item i;
	Stack s;
	Queue q;
	char c ='0';
	s.Show();
	q.Show();
	while((int)c!=27)
	{
		cout<<"1 - Push in Stack"<<endl;
		cout<<"2 - Pop from Stack"<<endl;
		cout<<"3 - Push in Queue"<<endl;
		cout<<"4 - Pop from Queue"<<endl;
		cout<<"ESC - EXIT"<<endl;
		c=_getch();
		switch(c)
		{
		case '1':
			{
				cout<<"Input Item value:"<<endl;
				cin>>i;
				s.Push(i);
				break;
			}
		case '2':
			{
				if(!s.Empty())
					cout<<"Item value = "<<s.Pop()<<endl<<"Press any key to continue...";
				else
					cout<<"---EMPTY LIST---"<<endl<<"Press any key to continue...";
				_getch();
				break;
			}
		case '3':
			{
				cout<<"Input Item value:"<<endl;
				cin>>i;
				q.Push(i);
				break;
			}
		case '4':
			{
				if(!q.Empty())
					cout<<"Item value = "<<q.Pop()<<endl<<"Press any key to continue...";
				else
					cout<<"---EMPTY LIST---"<<endl<<"Press any key to continue...";
				_getch();
				break;
			}
		default:;
		}
	system("cls");
	s.Show();
	q.Show();
	}
	s.Delete();
	q.Delete();
	return 0;
}

