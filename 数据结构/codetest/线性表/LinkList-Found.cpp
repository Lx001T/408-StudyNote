#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList ListRailInsert(LinkList &L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}	
	r->next = NULL;
	return L;
} 

bool PrintList(LinkList L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return true; 
}

int main()
{
	LinkList L;
	ListRailInsert(L);
	PrintList(L);
}
