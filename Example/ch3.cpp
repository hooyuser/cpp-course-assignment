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


//P3_8
void swap_i(int * num1, int * num2)
{
	int t;
	t = *num1;
	*num1 = *num2;
	*num2 = t;
}

void swap(void* num1, void* num2, int size)
{
	char* first = (char*)num1, *second = (char*)num2;
	for (int k = 0; k < size; k++)
	{
		char temp;
		temp = first[k];
		first[k] = second[k];
		second[k] = temp;
	}
}

void P3_8()
{
	int a = 3, b = 6;
	double x = 2.3, y = 4.5;
	char c1[8] = "John", c2[8] = "Antony";
	cout << "before swap:a = " << a << " b = " << b << endl;
	swap_i(&a, &b);
	cout << "after swap:a = " << a << " b = " << b << endl;
	cout << "before swap:x = " << x << " y = " << y << endl;
	swap(&x, &y, sizeof(x));
	cout << "after swap:x = " << x << " y = " << y << endl;
	cout << "before swap:c1 = " << c1 << " c2 = " << c2 << endl;
	swap(c1, c2, sizeof(c1));
	cout << "after  swap:c1 = " << c1 << " c2 = " << c2 << endl;
}

//P3_9

char* ladd(char* s1, char* s2)
{
	int n1, n2, n;
	char* res, c = 0;
	n1 = strlen(s1);
	n2 = strlen(s2);
	n = n1 > n2 ? n1 : n2;
	res = new char[n + 2];
	for (int i = n + 1; i >= 0; i--)
		res[i] = i > n - n1 ? s1[i - n - 1 + n1] : '0';
	for (int i = n; i >= 0; i--)
	{
		char tchar;
		tchar = i > n - n2 ? res[i] - '0' + s2[i - n + n2 + n1] - '0' + c : res[i] - '0' + c;
		c = tchar > 9 ? 1 : 0;
		res[i] = c > 0 ? tchar - 10 + '0' : tchar + '0';
	}
	return res;
}

void P3_9()
{
	char num1[100], num2[100], *num;
	cin >> num1 >> num2;
	num = ladd(num1, num2);
	cout << num1 << " + " << num2 << " = " << num << endl;
	delete[] num;
}

//P3_10
namespace P3_10
{
	int add(int a, int b)
	{
		return a + b;
	}

	int sub(int a, int b)
	{
		return a - b;
	}
	int mu1(int a, int b)
	{
		return a * b;
	}

	int divi(int a, int b)
	{
		if (b == 0) return 0x7fffffff;
		else return a / b;
	}


	int(*menu[]) (int a, int b) = { add, sub, mu1, divi };   //函数指针数组

	void P3_10()
	{
		int num1, num2, choice;
		cout << "Select operator:" << endl;
		cout << "    1:add" << endl;
		cout << "    2:sub" << endl;
		cout << "    3:multiply" << endl;
		cout << "    4:divide" << endl;
		cin >> choice;
		cout << "Input number (a,b) :";
		cin >> num1 >> num2;
		cout << "Result :" << menu[choice - 1](num1, num2) << endl;
	}
}


//P3_11
namespace P3_11
{
	void swap(int &refx, int &refy)
	{
		int temp;
		temp = refx;
		refx = refy;
		refy = temp;
	}

	void P3_11()
	{
		int x = 3, y = 5;
		cout << "before swap x = " << x << " y= " << y << endl;
		swap(x, y);
		cout << "after swap : x=" << x << "y=" << y << endl;
	}
}

//P3_12
int max1(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > a[t]) t = i;
	return a[t] + 0;
}


int& max2(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > a[t]) t = i;
	return a[t];
}


int& sum(int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}

void P3_12()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int m1 = max1(a, 10);
	int m2 = max2(a, 10);
	int & m3 = max2(a, 10);
	int & m4 = sum(a, 10);
	cout << "m1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m3 = " << m3 << endl;
	cout << "m4 = " << m4 << endl;
	m3 += 10;
	max2(a, 10) -= 100;
	cout << sum(a, 10) << endl;
}

//P3_13
namespace P3_13
{
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

	NODE* Search(NODE* head, int key)    //返回从左至右第一个 score 小于 key 的节点的前驱，若无，返回尾节点
	{
		NODE* p;
		p = head;
		while (p->next != NULL)          //当 p 不是尾节点时
		{
			if (p->next->score < key)      //如果 p 的后继的 score 小于 key
			{
				return p;
			}
			p = p->next;
		}
		return p;
	}

	void InsertNode(NODE* p, NODE* newp)  //p 后插入节点 newp
	{
		newp->next = p->next;             //设置 newp 的后继
		p->next = newp;                   //重置 p 的后继 
	}

	void DelNode(NODE* p)           //删除 p 节点的后继
	{
		NODE* q;
		if (p->next != NULL)
		{
			q = p->next;            //将指向 p 后继的一个指针暂存为 q
			p->next = q->next;      //重置 p 的后继
			delete q;               //通过 q 删除 p
		}
	}

	void DelList(NODE* head)          //销毁以 head 为首节点的链表
	{
		NODE* p;
		p = head;                     //将待删除节点 p 初始化为 head
		while (head->next != NULL)    //当 head 不是尾节点时：
		{
			head = head->next;			//head 后移
			delete p;                   //删除 p 节点
			p = head;                   //再次将待删除节点 p 设置为 head
		}
		delete head;                  //此时 head 为尾节点，删除 head
	}

	void DispList(NODE* head)         //显示链表各元素
	{
		NODE* p;
		p = head;
		while (p->next != NULL)
		{
			cout << p->next->name << "\t" << p->next->score << endl;
			p = p->next;
		}
	}

	void P3_14()
	{
		NODE * newp, *head, *p;
		char name[20];
		float score, low = 60;
		if ((newp = new NODE) == NULL)
		{
			cout << "new NODE fail!" << endl;
			exit(0);
		}
		head = newp;
		head->next = NULL;
		cout << "Input name and score(-1 to exit):" << endl;
		cin >> name >> score;                 //输入姓名和分数
		while (score > 0)
		{
			if ((newp = new NODE) == NULL)
			{
				cout << "new NODE fail!" << endl;
				exit(0);
			}
			strcpy_s(newp->name, name);
			newp->score = score;
			newp->next = NULL;
			p = Search(head, score);          //返回从左至右第一个分数小于当前 score 的节点的前驱，若无，返回尾节点
			InsertNode(p, newp);              //在 p 处插入新节点 newp
			cin >> name >> score;
		}
		cout << "Before delete:" << endl;
		DispList(head);
		for (p = Search(head, low); p->next != NULL; p = Search(head, low))  //链表已按 score 降序排列，删除小于60分的节点
			DelNode(p);
		cout << "After delete:" << endl;
		DispList(head);
		DelList(head);
	}
}

//P3_15
void P3_15()
{
	union UData
	{
		char Ch;
		short Sint;
		long Lint;
		unsigned Uint;
		float f;
		double d;
		char str[10];
	};
	UData u;
	strcpy_s(u.str, "123456789");
	cout << "char :" << '\t' << u.Ch << endl;
	cout << "short :" << '\t' << hex << u.Sint << endl;
	cout << "long :" << '\t' << u.Lint << endl;
	cout << "unsigned :" << '\t' << u.Uint << endl;
	cout << "float :" << '\t' << u.f << endl;
	cout << "double :" << '\t' << u.d << endl;
	cout << "string :" << '\t' << u.str << endl;
}
