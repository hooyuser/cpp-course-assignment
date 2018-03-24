#include<iostream>
#include<iomanip>
using namespace std;

void P2_1()
{
	cout << 'A' << '\t' << ';' << '\n';
	cout << '\102' << '\011' << '\073' << '\012';
	cout << '\103' << '\11' << '\73' << '\12';
	cout << '\x44' << '\x09' << '\x3b' << '\x0a';
	cout << '\x45' << '\x9' << '\x3b' << '\xa';
	cout << "\x46\x09\x3b\x0a";
	cout << "\x45\x9\x3b\xa";
	cout << "\xcd\xcd\xcd\xcd\xcd" << endl;
}

//演示算术运算表达式
void P2_2()
{
	int a;
	a = 2 * 3 + -3 % 5 - 4 / 3;
	float b;
	b = 5 + 3.2e3 - 5.6 / 0.03;
	cout << a << "\t" << b << endl;
	int m = 3, n = 4;
	a = m++ - (--n);
	cout << a << "\t" << m << "\t" << n << endl;
}

//演示逻辑运算表达式
void P2_3()
{
	int x, y, z;
	x = y = z = 1;
	--x && ++y && ++z;
	cout << x << '\t' << y << '\t' << z << endl;
	++x && ++y && ++z;
	cout << x << '\t' << y << '\t' << z << endl;
	++x && y-- || ++z;
	cout << x << '\t' << y << '\t' << z << endl;
}

//演示条件运算表达式
void P2_4()
{
	int i = 10, j = 20, k;
	k = (i < j) ? i : j;
	cout << i << '\t' << j << '\t' << k << endl;
	k = i - j ? i + j : i - 3 ? j : i;
	cout << i << '\t' << j << '\t' << k << endl;
}

void P2_5()
{
	int n;
	cout << "Enter the score:";
	cin >> n;
	if (n >= 60)
		if (n >= 90)
			cout << "The degree is A" << endl;
		else if (n >= 80)
			cout << "The degree is B" << endl;
		else
			cout << "The degree is C" << endl;
	else
		cout << "The degree is D" << endl;
}

//将百分制成绩按等级输出
void P2_6()
{
	int n;
	cout << "Enter a score:";
	cin >> n;
	switch (n / 10)
	{
	case 9:case 10:
		cout << "The degree is A" << endl;
		break;
	case 8:
		cout << "The degree is B" << endl;
		break;
	case 7:case 6:
		cout << "The degree is C" << endl;
		break;
	default:
		cout << "The degree is D" << endl;
	}
}

//求 1+3+5+···+99
void P2_7()
{
	int i, sum = 0;
	for (i = 1; i < 100; ++i, ++i)
		sum = sum + i;
	cout << "sum= " << sum << endl;
}

//求解百钱买鸡问题
void P2_8()
{
	const int cock = 20, hen = 33, chick = 100;
	int i, j, k;
	for (i = 0; i <= cock; i++)
		for (j = 0; j <= hen; j++)
			for (k = 0; k <= chick; k++)
				if ((i + j + k) == 100 && (5 * i + 3 * j + k / 3) == 100 && k % 3 == 0)
					cout << "鸡翁、鸡婆、鸡雏各有：\t" << i << '\t' << j << '\t' << k << endl;
}

//用 while 循环求 1+3+5+···+99
void P2_9()
{
	int i = 1, sum = 0;
	while (i < 100)
	{
		sum = sum + i;
		++i, ++i;
	}
	cout << "sum= " << sum << endl;
}

void P2_10()
{
	int i = 1, sum = 0;
	do
	{
		sum = sum + i;
		++i, ++i;
	} while (i < 100);
	cout << "sum= " << sum << endl;
}

void P2_11()
{
	int i, n;
	while (1)
	{
		cin >> n;
		if (n <= 1)
			break;
		for (i = 2; i < n; i++)
			if (n%i == 0) break;
		i >= n ? cout << n << "是素数\n" : cout << n << "不是素数\n";
	}
}

void P2_12()
{
	int i, n;
	while (1)
	{
		cin >> n;
		if (n <= 1)
			break;
		for (i = 2; i < n; i++)
			if (n%i == 0) goto goon;
	goon:	i >= n ? cout << n << "是素数\n" : cout << n << "不是素数\n";
	}
}

int max(int x, int y)
{
	int z;
	z = (x > y) ? x : y;
	return z;
}

void P2_13()
{
	int a, b;
	cin >> a >> b;
	cout << max(a, b) << endl;
}

void swap(int a, int b)
{
	int t;
	t = a; a = b; b = t;
}

void P2_14()
{
	int x = 2, y = 5;
	cout << "x= " << x << " y= " << y << endl;
	swap(x, y);
	cout << "after swap: ";
	cout << "x= " << x << " y= " << y << endl;
}

void P2_15()
{
	int x = 2, y = 5;
	cout << "x= " << x << " y= " << y << endl;
	swap(x, y);
	cout << "after swap: ";
	cout << "x= " << x << " y= " << y << endl;
}
