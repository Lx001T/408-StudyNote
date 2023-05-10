#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化 
bool InitDLinkList(DLinkList &L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

// 判空 
bool Empty(DLinkList L)
{
	return (L->next = NULL);
}

// 插入:将节点*s插入到*p之后 
bool InsertNextDNode(DNode *p, DNode *s) 
{
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	p->next = s;
	s->prior = p; 
	return true;
}

// 删除p后继节点
bool DeleteNextDNode(DNode *p)
{
	if (p == NULL) return false;
	DNode *q = p->next;
	if (q == NULL) return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(p);
	return true;	
} 

// 遍历 
while(p != NULL)
{
	p = p->next; // 后向 
	p = p->prior;	// 前向 
} 

// 跳过头节点
while (p->prior != NULL)
{
	p = p->prior;	
} 

int main(int argc, char** argv) {
	return 0;
}
