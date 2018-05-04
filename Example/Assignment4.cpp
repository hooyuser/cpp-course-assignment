#include<iostream>
#include<fstream>
#include"head.h"

using namespace std;

void traverseMat(int* p, int nRow, int nCol)
{
	int* pt = new int[nRow * nCol];
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			pt[nRow * j + i] = p[nCol * i + j];
		}
	}
	for (int i = 0; i < nRow * nCol; i++)
	{
		p[i] = pt[i];
	}
	delete[] pt;
}

void manipulateMat()
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\sourse_file.txt");
	int  nRow, nCol;
	in >> nRow >> nCol;
	int* pMat = new int[nRow * nCol];
	for (int i = 0; i < nRow * nCol; i++)
	{
		in >> pMat[i];
	}
	in.close();

	ofstream out;
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\outMatrix.txt");
	traverseMat(pMat, nRow, nCol);
	for (int i = 0; i < nRow * nCol; i++)
	{
		out << pMat[i] << " ";
		if ((i + 1) % nRow == 0)
		{
			out << "\n";
		}
	}
	out.close();

	delete[] pMat;
}


/*
void swapNode(CStu* pPreA, CStu* pA, CStu* pB)
{
	pPreA->next = pB;
	pA->next = pB->next;
	pB->next = pA;
}

void readTxtFile(const char* fileName)
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\学生成绩链表测试1.txt");
	if (!in.is_open()) return;
	int nStuCount = 0;
	char cTemp[128];
	in >> nStuCount;

	CStu* pHeader = new CStu();
	CStu* pT = pHeader;
	for (int i = 0; i < nStuCount; i++)
	{
		CStu* pStu = new CStu();

		in >> pStu->sName >> pStu->sNum >> cTemp >> cTemp;
		for (int j = 0; j < 5; j++)
		{
			in >> pStu->fScore[j];
		}
		pT->next = pStu;
		pT = pT->next;
		pT->next = 0;
	}
	in.close();

	CStu* pStart = pHeader;
	while (pStart->next->next != 0)
	{
		CStu* pPreA= pStart;
		CStu* pA = pStart->next;
		CStu* pB = pStart->next->next;
		while (pB != 0)
		{
			if (pA->fScore[4] < pB->fScore[4])
			{
				pPreA->next = pB;
				pA->next = pB->next;
				pB->next = pA;
			}
			pPreA = pPreA->next;
			pA = pA->next;
			pB = pB->next;
		}
		pStart = pStart->next;
	}

	ofstream out;
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\输出成绩.txt");
	pT = pHeader->next;
	while (pT)
	{
		out << pT->sName << "  " << pT->sNum << "  ";
		for (int j = 0; j < 5; j++)
		{
			out << pT->fScore[j] << " ";
		}
		out << endl;
		pT = pT->next;
	}
	out.close();


}
*/