#include <stdio.h>
#define InitSize 10

typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList; 

void InitList(SeqList &L)
{
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len)
{
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize+len) * sizeof(int));
	for (int i = 0; i < L.length; i ++ )
		L.data[i] = p[i];
	L.MaxSize += len;
	free(p);	
} 

int main(int argc, char** argv) {
	SeqList L;
	InitList(L);
	
	IncreaseSize(L, 5);
	return 0;
}
