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
	//������0x��ͷ��ʮ�����Ʊ�ʾ�ڴ��еĶ����������������ҵ�ַ�ɵ͵��� 
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

void testTraverseByte()
{
	int n = 2341;
	double pi = 3.14159265;
	cout << "n = " << n << endl;
	cout << (n = traverseByte<int>(n)) << endl;
	cout << traverseByte<int>(n) << endl;
	cout << "pi = " << pi << endl;
	cout << (pi = traverseByte<double>(pi)) << endl;
	cout << traverseByte<double>(pi) << endl;
}

void testToBitArray()
{
	char n = 3;
	char ch1[100] = { 0 };
	toBitArray<char>(n, ch1);
	cout << ch1 << endl;

	double pi = 3.14159265;
	char ch2[100] = { 0 };
	toBitArray<double>(pi, ch2);
	cout << ch2 << endl;
}