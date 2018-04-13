#include<iostream>
#include"head.h"
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

void pointerConvert()
{
	//下面用0x开头的十六进制表示内存中的二进制数，从左至右地址由低到高 
	int A[10] = { 1,2,3,4,5 };
	short int* pSA = (short int*)A;
	cout << "A[0] = " << A[0] << endl; //0x 01 00 00 00 -> 1
	cout << "A[1] = " << A[1] << endl; //0x 02 00 00 00 -> 2
	cout << "pSA[0] = " << pSA[0] << endl; //0x 01 00
	cout << "pSA[1] = " << pSA[1] << endl; //0x 00 00
	cout << "pSA[2] = " << pSA[2] << endl; //0x 02 00
	cout << "pSA[3] = " << pSA[3] << endl; //0x 00 00
	pSA[0] = -1; //0x FF FF
	pSA[1] = -1; //0x FF FF
	pSA[2] = -2; //0x FE FF
	pSA[3] = -1; //0x FF FF
	cout << "A[0] = " << A[0] << endl; //0x FF FF FF FF -> -1
	cout << "A[1] = " << A[1] << endl; //0x FE FF FF FF -> -2
}