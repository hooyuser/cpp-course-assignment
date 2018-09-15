#include<iostream>
#include"header.h"
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

void pointerConvert()  //指针的强制转换演示
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

void traverseInt(int& n)    //位运算翻转整型变量
{
	n = ((n >> 24) & 0xFF) | ((n >> 8) & 0xFF00) | ((n << 8) & 0xFF0000) | ((n << 24) & 0xFF000000);//从低地址到高地址依次提取字节
}

void testToBitArray()       //使用模板函数 ToBitArray<T> 将变量转化为 char 数组
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

void testTraverseByteWise()  //用函数模板traverseByte对变量逐字节倒置
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


struct Student
{
	char ID[32];
	char Name[32];
	float Score[5];
};
typedef struct Student Stu;





void testStudentList()            //链表模板类测试
{
	SList<Stu> StuList = SList<Stu>();
	Stu myStu = { "10086","Mobile",{10,20,30,40,50} };
	StuList.insertAsLast(myStu);
	cout << StuList.first()->data.ID << endl;
	myStu = { "110","Police",{ 20,20,80,50,30 } };
	StuList.insertAsLast(myStu);
	StuList.reverse();
	StuList.removeSucc(StuList.first());
	cout << StuList.first()->data.ID << endl;
};
