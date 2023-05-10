#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList ListFrontFound(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int x;
	scanf("%d", &x);
	while (x != 999)
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);	
	} 
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

int main(int argc, char** argv) {
	LinkList L;
	ListFrontFound(L);
	PrintList(L); 
	
	return 0;
}
