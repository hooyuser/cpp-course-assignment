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

void pointerConvert()  //ָ���ǿ��ת����ʾ
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

void traverseInt(int& n)
{
	n = ((n >> 24) & 0xFF) | ((n >> 8) & 0xFF00) | ((n << 8) & 0xFF0000) | ((n << 24) & 0xFF000000);//�ӵ͵�ַ���ߵ�ַ������ȡ�ֽ�
}

void testToBitArray()
{
	char chBit[100] = { 0 };

	char ch = 3;
	toBitArray<char>(ch, chBit);
	cout << chBit << endl;

	int n = 17;
	toBitArray<int>(n, chBit);
	cout << chBit << endl;

	double pi = 3.14159265;
	toBitArray<double>(pi, chBit);
	cout << chBit << endl;
}

void testTraverseByteWise()  //�ú���ģ��traverseByte�Ա������ֽڵ���
{
	char chBit[100] = { 0 };
	int n = 1;
	cout << "n = " << n << endl;
	toBitArray<int>(n, chBit);
	cout << chBit << endl << endl;

	cout << "Traverse n" << endl;
	cout << "n = " << (n = traverseByteWise<int>(n)) << endl;
	toBitArray<int>(n, chBit);
	cout << chBit << endl << endl;

	cout << "Traverse n" << endl;
	cout << "n = " << (n = traverseByteWise<int>(n)) << endl;
	toBitArray<int>(n, chBit);
	cout << chBit << endl << endl;

	cout << "Traverse n" << endl;
	traverseInt(n);
	cout << "n = " << n << endl;
	toBitArray<int>(n, chBit);
	cout << chBit << endl << endl;

	double pi = 3.14159265;
	cout << "pi = " << pi << endl;
	toBitArray<double>(pi, chBit);
	cout << chBit << endl << endl;

	cout << "Traverse pi" << endl;
	cout << "pi = " << (pi = traverseByteWise<double>(pi)) << endl;
	toBitArray<double>(pi, chBit);
	cout << chBit << endl << endl;

	cout << "Traverse pi" << endl;
	cout << "pi = " << (pi = traverseByteWise<double>(pi)) << endl;
	toBitArray<double>(pi, chBit);
	cout << chBit << endl << endl;
}

void writeTxtFile(char* TxtFile)
{

}