#include<iostream>
#include<iomanip>
using namespace std;

enum city { Beijing, Shanghai, Tianjin = 6, Chongqing };

void P3_1()
{
	int n;
	cout << "Input a city number (" << Beijing - 1 << " to exit):" << endl;
	cin >> n;
	while (n >= Beijing)
	{
		switch (n)
		{
		case Beijing:
			cout << "Beijing" << endl;
			break;
		case Shanghai:
			cout << "Shanghai" << endl;
			break;
		case Tianjin:
			cout << "Tianjin" << endl;
			break;
		case Chongqing:
			cout << "Chongqing" << endl;
			break;
		default:
			cout << "Invalid city number!" << endl;
			break;
		}
		cin >> n;
	}
}

void P3_2()
{
	const int MaxN = 5;
	int n, a[MaxN], i, j;
	for (n = 0; n < MaxN; n++)
	{
		cin >> a[n];
		if (a[n] < 0)
			break;
	}

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i] < a[j])
			{
				int t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void P3_3()
{
	const int MaxN = 100, CourseN = 5;
	int n, score[MaxN][CourseN + 1] = { 0 };
	float aver[CourseN] = { 0 };
	for (n = 0; n < MaxN; n++)
	{
		for (int j = 0; j < CourseN; j++)
		{
			cin >> score[n][j];
			if (score[n][0] < 0)
				break;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < CourseN; j++)
			score[i][CourseN] = score[i][CourseN] + score[i][j];

	for (int j = 0; j < CourseN + 1; j++)
	{
		for (int i = 0; i < n; i++)
		{
			aver[j] = aver[j] + score[i][j];
		}
		aver[j] = aver[j] / n;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < CourseN + 1; j++)
		{
			cout << aver[i] << "\t";
		}
		cout << endl;
	}
		
	cout << endl;
}