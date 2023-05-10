#include <stdio.h>

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
	L = NULL;
	return true;
}

bool Empty(LinkList L)
{
	if (L == NULL)
		return true;
	else 
		return false;
}

int main(int argc, char** argv) {
	LinkList L;
	
	InitList(L);
	return 0;
}
