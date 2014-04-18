#include <string>

typedef struct
{
	std::wstring Name;
	int Group;
} Item;

typedef struct node
{
	Item item;
	node *left,*right;
	node(Item x,node *l,node *r)
	{
		item=x;
		left = l;
		right = r;
	}
} *link;

void addToTree(link& root,Item& i);
void addToTree(link& root,std::wstring i,int g);
link deleteFromTree(link& root,Item i);
void deleteTree(link& root);
void walkLKR(link root,void (*f)(link));
void walkLRK(link root,void (*f)(link));
void walkKLR(link root,void (*f)(link));