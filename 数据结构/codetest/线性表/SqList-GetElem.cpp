#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

typedef struct{
	int *data;
	int MaxSize;
	int length;
}SqList;

void InitList(SqList &L)
{
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

// Insert
bool ListInsert(SqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1)
	 	return false;
	if (L.length >= InitSize)
		return false; 
	for (int j = L.length; j >= i; j -- )
		L.data[j-1] = L.data[j];
	L.data[i-1] = e;
	L.length ++ ;
	return true;
}

// find by locate
int GetElem(SqList L, int i)
{
	return L.data[i-1];
}

// find by value
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] == e)
			return i+1;
	return 0;
}

void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i ++ )
		printf("%d ", L.data[i]);
	printf("\n"); 
	return;
}

int main(int argc, char** argv) {
	SqList L;
	InitList(L);
	
	// insert some value
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 66);
	
	PrintList(L);
	
	//  按位查找结果 
	printf("%d\n", GetElem(L, 2));
	
	//  按值查找结果 
	printf("%d", LocateElem(L, 66));
	return 0;
}
