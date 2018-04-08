#include<iostream>

using namespace std;

void swapPointers(int*& pa, int *& pb)
{
	int* pc = pa;
	pa = pb;
	pb = pc;
}

void swapPointers(int** pa, int ** pb)
{
	int* pc = *pa;
	*pa = *pb;
	*pb = pc;
}

