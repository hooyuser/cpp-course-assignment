#include<iostream>
#include<iomanip>
#include"head.h"

using namespace std;

//BubbleSort
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

}

void displayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void sortTest()
{
	const int arrayLength = 10;
	int A[arrayLength] = { 0,1,5,3,9,4,8,6,7,2 };
	bubbleSort(A, arrayLength);
	displayArray(A, arrayLength);
}


//Calendar

const int month[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},{ 31,29,31,30,31,30,31,31,30,31,30,31 } };

const bool isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}

	return false;
}

void printMonthCalendar(int nWhatDay, int nDaysOfMonth) //nWhatDay表示该月第一天是星期几，nDaysOfMonth表示该月天数
{
	cout << "日 一 二 三 四 五 六" << endl;
	if (nWhatDay != 7)
	{
		for (int i = 0; i < nWhatDay; i++)
		{
			cout << "   ";
		}
	}

	for (int i = 1; i <= nDaysOfMonth; i++)
	{
		cout << setw(2) << i << " ";
		if (i % 7 == 7 - nWhatDay)
		{
			cout << endl;
		}
	}
	cout << endl;
}


void printAnnualCalendar(int year, int nWhatDay, int months = 12) //year为年份，nWhatDay表示该年第一天是星期几,months表示打印前几个月
{
	int firstDay = nWhatDay;
	for (int i = 0; i < months; i++)
	{
		cout << year << "年" << i + 1 << "月" << endl << endl;
		printMonthCalendar(firstDay, month[isLeapYear(year)][i]);
		firstDay = getNextMonthFisrtDayIsWhatDay(firstDay, month[isLeapYear(year)][i]);
		cout << endl << endl;
	}
}

const int getNextMonthFisrtDayIsWhatDay(int nWhatDay, int nDaysOfMonth) //nWhatDay表示该月第一天是星期几，nDaysOfMonth表示该月天数
{
	return ((nDaysOfMonth + nWhatDay) % 7) ? (nDaysOfMonth + nWhatDay) % 7 : 7;
}

void calendarTest()
{
	printMonthCalendar(7, 31);
	cout << getNextMonthFisrtDayIsWhatDay(3, 31);
	printAnnualCalendar(2018, 1, 6);
}

