// SimpleOrderedTree.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "SimpleOrderedTree.h"
#include <time.h>
#include <Windows.h>
#include <locale.h>

using namespace std;

const int delta = 5;

void ShowTree(link root,int d)
{
	
	if(root==NULL)
	{
		/*
		for(int i=0;i<(d-delta);i++)
			wcout<<L' ';
		for(int i=0;i<(delta);i++)
			wcout<<L'-';
		wcout<<L"NULL"<<endl;
		*/
		return;
	}
	wcout<<endl;
	ShowTree(root->right,d+delta);
	for(int i=0;i<(d-delta);i++)
		wcout<<L' ';
	for(int i=0;i<(delta);i++)
		wcout<<L'-';
	wcout<<root->item.Name<<L'('<<root->item.Group<<L')'<<endl;
	ShowTree(root->left,d+delta);
	wcout<<endl;
}

void func(link l)
{
	wcout<<l->item.Name<<L'('<<l->item.Group<<L")---";
}

int _tmain(int argc, _TCHAR* argv[])
{
	Item i;
	char c = '0';
	link root = NULL;

	setlocale(LC_ALL,"Russian");
	locale::global(locale("")); 
	wcout.imbue(locale(".1251")); 
	wcin.imbue(locale(".866")); 

	addToTree(root,L"��������",2894);
	addToTree(root,L"��������",2893);
	addToTree(root,L"��������",2893);
	addToTree(root,L"������",2893);
	addToTree(root,L"�������",2893);
	addToTree(root,L"������",2893);
	addToTree(root,L"������",2893);
	addToTree(root,L"�������",2893);
	while((int)c!=27)
	{
	ShowTree(root,delta);
	wcout<<L"1 - �������� ��������"<<endl;
	wcout<<L"2 - ������� ��������"<<endl;
	wcout<<L"3 - ����� ������(���)"<<endl;
	wcout<<L"4- ����� ������(���)"<<endl;
	wcout<<L"5 - ����� ������(���)"<<endl;
	wcout<<L"ESC - ����� �� ���������"<<endl;
	c = _getch();
	if((int)c!=27)
	{
	switch(c)
	{
	case '1':
		cout<<c;
		wcout<<L"���������� ������ ��������... "<<endl;
		wcout<<L"������� �������:  ";
		wcin>>i.Name;
		wcout<<L"������� ����� ������:  ";
		wcin>>i.Group;
		addToTree(root,i);
		break;
	case '2':
		wcout<<L"�������� ��������... "<<endl;
		wcout<<L"������� �������: ";
		wcin>>i.Name;
		deleteFromTree(root,i);
		break;
	case '3':
		wcout<<L"����� ������(���)... "<<endl;
		walkLKR(root,func);
		break;
	case '4':
		wcout<<L"����� ������(���)... "<<endl;
		walkLRK(root,func);
		break;
	case '5':
		wcout<<L"����� ������(���)... "<<endl;
		walkKLR(root,func);
		break;
	default:;
	}
	if((c!='1')&&(c!='2'))
	{
		cout<<endl<<"..."<<endl;
		_getch();
	}
	system("cls");
	}
	}
	deleteTree(root);
	return 0;
}

