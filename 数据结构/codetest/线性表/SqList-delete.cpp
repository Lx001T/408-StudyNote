#include <stdio.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L)
{
	for (int i = 0; i < L.length; i ++)
		L.data[i] = 0;
	L.length = 0;
}

bool ListInsert(SqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j -- )
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length ++;
	return true;	
}

bool ListDelete(SqList &L, int i, int &e)
{
	if (i < 1 || i > L.length)
		return false;
	e = L.data[i-1];
	for (int j = i; j < L.length; j ++)
		L.data[j-1] = L.data[j];
	L.length --;
	return true;
}

void ListPrint(SqList L)
{
	for (int i = 0; i < L.length; i ++ )
		printf("%d ",L.data[i]);
	printf("\n");
}

int main(int argc, char** argv) {
	SqList L;
	InitList(L);
	
	// Insert some test data
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 4);
	
	ListPrint(L);
	
	// delete
	int e = -1;
	ListDelete(L, 3, e);

	ListPrint(L);
	return 0;
}
