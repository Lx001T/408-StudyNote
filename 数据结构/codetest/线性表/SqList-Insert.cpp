#include <stdio.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L)
{
	for (int i = 0; i < L.length; i ++ )
		L.data[i] = 0;
	L.length = 0;
}
/* base logic code 
void ListInsert(SqList &L, int i, int e)
{
	for (int j = L.length; j >= i; j --)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length ++ ;
}
*/

// strong code
bool ListInsert(SqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1) // wrong locate
		return false;
	if (L.length >= MaxSize) // judge overflow 
		return false;
	for (int j = L.length; j >= i; j -- )
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length ++ ;
	return true;	
}

int main(int argc, char** argv) {
	SqList L;
	InitList(L);

	ListInsert(L, 1, 2);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 999);
	
	
	for (int i = 0; i < L.length; i ++ )
		printf("%d ", L.data[i]);
	return 0;
}
