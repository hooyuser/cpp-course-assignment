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

