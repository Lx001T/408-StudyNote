#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

// ��ʼ�� 
bool InitDLinkList(DLinkList &L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

// �п� 
bool Empty(DLinkList L)
{
	return (L->next = NULL);
}

// ����:���ڵ�*s���뵽*p֮�� 
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

// ɾ��p��̽ڵ�
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

// ���� 
while(p != NULL)
{
	p = p->next; // ���� 
	p = p->prior;	// ǰ�� 
} 

// ����ͷ�ڵ�
while (p->prior != NULL)
{
	p = p->prior;	
} 

int main(int argc, char** argv) {
	return 0;
}
