#include<iostream>
#include<iomanip>
using namespace std;

void P1_1()
{
	cout << "Hello C++!" << endl;
}

void P1_2()
{
	float num1, num2, num3; //定义三个数
	cout << "Please input three numbers:";
	cin >> num1 >> num2 >> num3;
	cout << "The average of " << num1 << ", " << num2 << " and " << num3;
	cout << " is: " << (num1 + num2 + num3) / 3 << endl;
}

void P1_3()
{
	float num1, num2, num3;
	cout << "Please input three numbers:";
	cin >> num1 >> num2 >> num3;
	cout << setw(8) << setprecision(12);
	cout << "The average of " << num1 << ", " << num2 << " and " << num3;
	cout << " is: " << (num1 + num2 + num3) / 3 << endl;
}