#include <cstdlib>
//#include <iostream>
#include"SimpleOrderedTree.h"
void addToTree(link& root,Item& i)
{
	if(root==NULL)
	{
		root = new node(i,NULL,NULL);
		return;
	}
	if(root->item.Name == i.Name)
		return;
	if(root->item.Name > i.Name)
		addToTree(root->left,i);
	else
		addToTree(root->right,i);
}

void addToTree(link& root,std::wstring i,int g)
{
	Item temp;
	if((i[0]>=L'à')&&(i[0]<='ÿ'))
		i[0]+=(int)(L'À'-L'à');
	temp.Name = i;
	temp.Group = g;
	if(root==NULL)
	{
		root = new node(temp,NULL,NULL);
		return;
	}
	if(root->item.Name == temp.Name)
		return;
	if(root->item.Name > i)
		addToTree(root->left,i,g);
	else
		addToTree(root->right,i,g);
}

link del(link& l)
{
	if(l->right!=NULL) 
		del(l->right);
	else
	{
		link t = l;
		l = l->left;
		return t;
	}
}

link deleteFromTree(link& root,Item i)
{
	link q = NULL;
	if(root == NULL)
		return NULL;
	if(root->item.Name > i.Name)
		deleteFromTree(root->left,i);
	else if (root->item.Name < i.Name)
		deleteFromTree(root->right,i);
	else
	{
		q = root;
		if(root->left == NULL)
		{
			root = q->right;
			return q;
		}
		else if(root->right == NULL)
		{
			root = q->left;
			return q;
		}
		else
		{
			q = del(root->left);
			Item i = root->item;
			root->item = q->item;
			q->item = i;
			return q;
		}
	}
}

void deleteTree(link& root)
{
	link q;
	while(root!=NULL)
	{
		q= deleteFromTree(root,root->item);
		if(q!=NULL)
			delete q;
	}
}

void walkLKR(link root,void (*f)(link))
{
	if(root == NULL)
		return;
	walkLKR(root->left,f);
	f(root);
	walkLKR(root->right,f);
}

void walkLRK(link root,void (*f)(link))
{
	if(root == NULL)
		return;
	walkLRK(root->left,f);
	walkLRK(root->right,f);
	f(root);
}

void walkKLR(link root,void (*f)(link))
{
	if(root == NULL)
		return;
	f(root);
	walkKLR(root->left,f);
	walkKLR(root->right,f);
}