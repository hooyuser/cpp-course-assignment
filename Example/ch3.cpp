#include<iostream>
#include<iomanip>
using namespace std;


//P3_1
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


//P3_2
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


//P3_3
void P3_3()
{
	const int MaxN = 100, CourseN = 5;
	int n, score[MaxN][CourseN + 1] = { 0 };
	float aver[CourseN + 1] = { 0 };

	for (n = 0; n < MaxN; n++)                      //输入学生成绩
	{
		for (int j = 0; j < CourseN; j++)
		{
			cin >> score[n][j];
		}
		if (score[n][0] < 0)
			break;
	}

	for (int i = 0; i < n; i++)                    //计算总分，存入 score[i][CourseN]
		for (int j = 0; j < CourseN; j++)
			score[i][CourseN] = score[i][CourseN] + score[i][j];

	for (int j = 0; j < CourseN + 1; j++)          //计算平均分
	{
		for (int i = 0; i < n; i++)
		{
			aver[j] = aver[j] + score[i][j];
		}
		aver[j] = aver[j] / n;
	}

	for (int i = 0; i < n; i++)                    //输出成绩与总分
	{
		for (int j = 0; j < CourseN + 1; j++)
		{
			cout << score[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "-----------------------------------------------------------" << endl;

	for (int i = 0; i < CourseN + 1; i++)          //输出平均分
	{
		cout << aver[i] << "\t";
	}
	cout << endl;
}


//P3_4
const int col = 5;
enum dir { Asc, Des };

void sort(int a[][col], int n, int Cn, dir D)
{
	int t[col];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][Cn]<a[j][Cn] && D == Des || a[i][Cn]>a[j][Cn] && D == Asc)
			{
				memcpy(t, a[i], sizeof(t));
				memcpy(a[i], a[j], sizeof(t));
				memcpy(a[j], t, sizeof(t));
			}
		}
	}
}

void P3_4()
{
	const int CourseN = 5;
	int n, score[][CourseN] = { {20140101,1,82,86,0},{20140203,2,80,80,0} ,{20140204,2,86,90,0},{20140205,2,90,83,0 },{ 20140102,1,75,86,0 } };
	n = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < CourseN - 1; j++)
		{
			score[i][CourseN - 1] = score[i][CourseN - 1] + score[i][j];
		}
	}
	sort(score, n, 4, Des);
	sort(score, n, 1, Asc);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < CourseN; j++)
		{
			cout << score[i][j] << "\t";
		}
		cout << endl;
	}
}


//P3_5
const int NameLen = 20;  //名字长度不超过20个字符

void order(char name[][NameLen], int n)  //字符串排序
{
	char temp[NameLen];
	for (int i = 0; i < n - 1; i++)      //选择排序
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy_s(temp, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp);
			}
		}
	}
}

int find(char name[][NameLen], int n, char searchname[NameLen])  //返回 searchname[] 的位置
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name[i], searchname) == 0)
			return i + 1;
		else if (strcmp(name[i], searchname) > 0)
			return 0;
	}
	return 0;
}

void P3_5()
{
	char NameTab[][NameLen] = { "GongJing","LiuNa","HuangPin","ZhouZijun","LianXiaolei","ChenHailing","CuiPeng","LiuPing" };
	char searchname[NameLen];
	int n = sizeof(NameTab) / NameLen;
	order(NameTab, n);
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\t' << NameTab[i] << endl;
	}
	cout << "Input the searching name:";
	cin >> searchname;
	if (n = find(NameTab, n, searchname))
	{
		cout << "Position:" << n << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}


//P3_6
void P3_6()
{
	int m, n;  //m 行 n 列
	int** dm;
	cout << "input matrix size m,n:";
	cin >> m >> n;
	dm = new int*[m];   //dm 指向一个动态数组的首元素，该数组有 m 个 int* 型变量
	for (int i = 0; i < m; i++)
	{
		if ((dm[i] = new int[n]) == NULL)  //每个 dm[i] 都指向一个动态数组的首元素，这个数组有 n 个 int 型变量
			exit(0);
	}
	for (int i = 0; i < m; i++)  //输入 m*n 个矩阵元素
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dm[i][j];
		}
	}
	for (int i = 0; i < m; i++)  //输出 m*n 个矩阵元素
	{
		for (int j = 0; j < n; j++)
		{
			cout << dm[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)  //释放 dm[i] 所指的空间
	{
		delete[] dm[i];
	}
	delete[] dm;                 //释放 dm 所指的空间
}


//P3_7
void P3_7()
{
	float(*p)[3][4];  //定义指针 p, p 应该指向一个 3 行 4 列的二维 float 数组
	int i, j, k;
	p = new float[2][3][4];
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				*(*(*(p + i) + j) + k) = i * 100 + j * 10 + k;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				cout << p[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}


//P3_13
struct student
{
	char name[20];
	float score;
};

int input(student s[], int n)   //返回输入人数
{
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> s[i].name >> s[i].score;
		if (s[i].score < 0) break;
	}
	return i;
}

void output(student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << s[i].name << "\t" << s[i].score << endl;
	}
}

void sort(student a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].score < a[j].score)
			{
				student t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void P3_13()
{
	const int MaxNum = 100;      //最大人数
	int num;                     //实际人数 
	student s[MaxNum];
	num = input(s, MaxNum);
	sort(s, num);
	output(s, num);
}


//P3_14
namespace P3_14
{
	struct student
	{
		char name[20];
		float score;
		struct student* next;
	};

	typedef student NODE;

	NODE* Search(NODE* head, int key)
	{
		NODE* p;
		p = head;
		while (p->next != NULL)
		{
			if (p->next->score < key)
			{
				return p;
			}
			p = p->next;
		}
		return p;
	}

	void InsertNode(NODE* p, NODE* newp)  //p 后插入节点 newp
	{
		newp->next = p->next;
		p->next = newp;
	}

	void DelNode(NODE* p)  //p 后插入节点 newp
	{
		NODE* q;
		if (p->next != NULL)
		{
			q = p->next; 
			p->next = q->next;
			delete q;
		}
	}

	void DelList(NODE* head)
	{
		NODE* p;
		p = head;
		while (head->next != NULL)
		{
			head = head->next;
			delete p;
			p = head;
		}
		delete head;
	}

	void DispList(NODE* head)
	{
		NODE* p;
		p = head;
		while (p->next != NULL)
		{
			cout << p->next->name << "\t" << p->next->score << endl;
			p = p->next;
		}
	}
}


