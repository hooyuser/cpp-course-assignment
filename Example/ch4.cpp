#include<iostream>

using namespace std;

//P4_1
extern void p1dispG();
extern void p2dispG();
extern void p2dispg();

int G = 0, g = 0;

void P4_1()
{
	p1dispG();
	p2dispG();
	p2dispg();
	cout << "in p G = " << G << endl;
	cout << "in p g = " << g << endl;
}


//P4_2
namespace P4_2 {
	void fun()
	{
		static int n = 0;
		int m = 0;
		n++;
		m++;
		cout << "m = " << m << ", n = " << n << endl;
	}

	void P4_2()
	{
		for (int i = 0; i < 4; i++)
		{
			fun();
		}
	}
}


//P4_3
int k = 300;
const int i = 100;
#define n 5
const int j = 200;

void fun(int i = 1, int j = 2)
{
	const int k = 3;
	static int l = 0;
	int m;
	const char* p = "abcde";
	char * q = new char[n + 1];
	for (m = 0; m < n; m++)
		q[m] = 'A' + m;
	q[m] = '\0';
	cout << "函数参数的地址：" << endl;
	cout << "\t" << "& i =" << &i << "\t" << "&j =" << &j << endl;
	cout << "局部变量的地址：" << endl;
	cout << "\t" << "& k =" << &k << "\t" << "&m = " << &m << "\ t" << "&p=" << &p << "\t " << "&q = " << &q << endl;
	cout << "静态局部变量的地址：" << endl;
	cout << "\t" << "&l = " << &l << endl;
	cout << "字符串常量的地址：" << endl;
	cout << "\t" << "p串的地址 =" << (void *)p << endl;
	cout << "堆的地址；" << endl;
	cout << "\t(void * ) q = " << (void *)q << endl;
	cout << "\tq 串 =" << q << endl;
	delete[] q;
	cout << "\tdelete 后, (void * )q=" << (void *)q << endl;
	cout << "\tdelete后，q指向的单元的内容 = " << q << endl;

}

void P4_3()
{

L1: fun();

L2: cout << "全局变量的地址：" << endl;
	cout << "\t &i = " << &i << "\t" << "&j =" << &j << "\t" << "&k = " << &k << endl;
	cout << "函数的人口地址：" << endl;
	cout << "\t &fun = " << (void*)fun << "\t" << "&P4_3 =" << (void*)P4_3 << endl;
}


//P4_4
namespace P4_4
{
	int i = 100, j = 200;
	void fun(int i = 2)
	{
		//int i = 3; //C2082: 形参“i”的重定义

		cout << "L3: i = " << i << endl;
		{
			for (int i = 4; i < 5; cout << "L6:i = " << i << endl, i++)
			{
				cout << "L4: i = " << i << endl;
				//int i = 5;//在 for-loop 实例化中声明的 "i" 不能在此范围内重新声明
				i++;
				cout << "L5: i = " << i << endl;
			}
		}
	}

	void P4_4()
	{
		fun();
	}
}

//P4_5
namespace P4_5
{
#include "mymath.h"
	void P4_5()
	{
		cout << max(5, 6);
	}

}


//P4_6
#include "TsingHua.h"
void P4_6()
{
	TsingHua::ShowName();
}

//P4_7
namespace P4_7
{
	using std::cout;
	using std::endl;
	void P4_7()
	{
		using TsingHua::ShowName;
		ShowName();
	}
}