#include <stdio.h>

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList; 

bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}

bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else 
		return false;
}

int main(int argc, char** argv) {
	LinkList L;
	InitList(L);
	return 0;
}

bool ListDelete(LinkList L, int i, ElemType &e)
{
	if (i < 1) return false;
	LNode *p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j ++ ;
	}
	if (p == NULL) return false;
	if (p->next = NULL) return false;
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true; 
}
