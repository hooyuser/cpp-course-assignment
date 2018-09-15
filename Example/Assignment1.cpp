#include<iostream>
#include<iomanip>
#include"header.h"

using namespace std;

//Sort three numbers

void sortThreeNum()
{
	int a, b, c;
	while (true)
	{
		cout << "Input three numbers: ";
		cin >> a >> b >> c;
		if (a < b)
			swap(a, b);
		if (b < c)
			swap(b, c);
		if (a < b)
			swap(a, b);
		cout << "Sorted numbers: " << a << " " << b << " " << c << endl;
	}

}

void harmonicSeries()  //Calculate 1+1/2+...+1/n
{
	int n;
	while (true)
	{
		cout << "Input an integer n: ";
		cin >> n;
		double sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += 1.0 / i;
		}
		cout << "1+1/2+...+1/n=" << sum << endl;
	}
}

void dispalyStars_1()
{
	int n;
	while (true)
	{
		cout << "Input an integer n: ";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - i; j++)
			{
				cout << " ";
			}
			for (int k = 1; k <= 2 * i - 1; k++)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void dispalyStars_2()
{
	int n;
	while (true)
	{
		cout << "Input an integer n: ";
		cin >> n;
		for (int i = n; i >= 1; i--)
		{
			for (int j = n - i; j >= 0; j--)
			{
				cout << " ";
			}
			for (int k = 2 * i - 1; k >= 1; k--)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void dispalyStars_3()
{
	int n;
	while (true)
	{
		cout << "Input an integer n: ";
		cin >> n;
		for (int i = n; i >= 1; i--)
		{
			for (int j = n - i; j >= 0; j--)
			{
				cout << " ";
			}
			for (int k = i ; k >= 1; k--)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void multiplication()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << left << setw(2) << j * i << " ";
		}
		cout << endl;
	}
}