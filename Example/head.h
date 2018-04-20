#pragma once

//Chapter1
void P1_1();
void P1_2();
void P1_3();

//Chapter2
void P2_1();
void P2_2();
void P2_3();
void P2_4();
void P2_5();
void P2_6();
void P2_7();
void P2_8();
void P2_9();
void P2_10();
void P2_11();
void P2_12();
void P2_13();
void P2_14();
void P2_15();
void P2_16();
void P2_17();
void P2_18();
void P2_19();

//Chapter3
void P3_1();
void P3_2();
void P3_3();






//Assignment1
void sortThreeNum();
void harmonicSeries();
void dispalyStars_1();
void dispalyStars_2();
void dispalyStars_3();
void multiplication();


//Assignment2
void swap(int& a, int& b);
void swap(int* a, int* b);
void bubbleSort(int* a, int n);
void displayArray(int* a, int n);
void sortTest();

const bool isLeapYear(int year);
void printMonthCalendar(int nWhatDay, int nDaysOfMonth);
void printAnnualCalendar(int year, int nWhatDay, int months);
const int getNextMonthFisrtDayIsWhatDay(int nWhatDay, int nDaysOfMonth);
void calendarTest();


//Assignment3
inline bool isNumber(char ch);
int myStrLen(char* pStr);
void myStrReverse(char* pStr);
void myStrCat(char* pStr1, const char* pStr2);
int myStrCompare(const char* pStr1, const char* pStr2);
void myStrCpy(char* pStr1, const char* pStr2);
void myStrRemove(char *pStr, int index);
void eraseDigital(char *pStr);
void strTest();


//Assignment4
void traverseMat(int* p, int nRow, int nCol);
void manipulateMat();

//others
void swapPointers(int*& pa, int *& pb);
void swapPointers(int** pa, int ** pb);
void pointerConvert();
void traverseInt(int& n);
void testTraverseByteWise();
void testToBitArray();


//function templates
template<class T>  //变量字节倒置
T traverseByteWise(T a)
{
	char* const pHead = (char*)&a;
	for (int i = 0; i < sizeof(T) / 2; i++)
	{
		std::swap(*(pHead + i), *(pHead + sizeof(T) - i - 1));
	}
	return a;
}

template<class T>
void toBitArray(const T a, char* bitArray) //将 a 所占内存中的二进制数转换为 '0'，'1' 组成的 char 数组，从左至右地址由低到高
{
	char* const pHead = (char*)&a;
	for (int i = 0; i < sizeof(T); i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			bitArray[8 * i + 7 - j] = ((pHead[i] >> j) & 1) + '0';
		}
	}
	bitArray[8 * sizeof(T)] = 0;
}