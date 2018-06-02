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
void P3_4();
void P3_5();
void P3_6();
void P3_7();
void P3_8();
void P3_9();
namespace P3_10 { void P3_10(); }
namespace P3_11 { void P3_11(); }
void P3_12();
namespace P3_13 { void P3_13(); }
namespace P3_14 { void P3_14(); }
void P3_15();

//Chapter5
namespace P5_1_A { void P5_1_A(); }
namespace P5_1_B { void P5_1_B(); }
namespace P5_2 { void P5_2(); }
namespace P5_3 { void P5_3(); }
namespace P5_4 { void P5_4(); }
namespace P5_5 { void P5_5(); }
namespace P5_6 { void P5_6(); }
namespace P5_7 { void P5_7(); }
namespace P5_8 { void P5_8(); }
namespace P5_9 { void P5_9(); }
namespace P5_10 { void P5_10(); }
namespace P5_11 { void P5_11(); }
namespace P5_12 { void P5_12(); }

//Chapter6
namespace P6_1 { void P6_1(); }
namespace P6_2 { void P6_2(); }


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

//Assignment5
struct Stu_info
{
	char sNum[32] = { 0 };
	char sName[32] = { 0 };
	float fScore[5] = { 0 };
	Stu_info* next = 0;
};
typedef struct Stu_info stuNode;

void swapNode(stuNode* pPreA, stuNode* pA, stuNode* pB);
void readTxtFile(const char* fileName);

//others
void swapPointers(int*& pa, int *& pb);
void swapPointers(int** pa, int ** pb);
void pointerConvert();
void traverseInt(int& n);
void testTraverseByteWise();
void testToBitArray();
void testStudentList();

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


//Singly Linked List Class Template

typedef int Rank;  //秩
#define SListNodePosi(T) SListNode<T> *  //列表节点位置

/* 列表节点模板结构 */
template <typename T>
struct SListNode
{
	// 成员
	T data;                 //数值
	SListNodePosi(T) succ;  //后继

	// 构造函数					   
	SListNode() {}          //用于构造header
	SListNode(T e, SListNodePosi(T) s = nullptr) : data(e), succ(s) {}      //默认构造器

	// 操作接口									
	SListNodePosi(T) insertAsSucc(T const& e);  //紧随当前节点之后插入新节点
};




/* 列表模板类 */
template <typename T>
class SList
{
private:
	int _size;  //规模
	SListNodePosi(T) header;  //头哨兵

protected:
	void init();  //列表创建时的初始化

	int clear();  //清除所有节点

	void copyNodes(SListNodePosi(T) p, int n);  //复制列表中自位置p起的n项

	/*
	void merge(SListNodePosi(T)& pp, int n, SList<T>& L, SListNodePosi(T) q, int m);  //归并

	void mergeSort(SListNodePosi(T)& p, int n);  //对从p开始连续的n个节点归并排序

	void selectionSort(SListNodePosi(T) p, int n);  //对从p开始连续的n个节点选择排序

	void insertionSort(SListNodePosi(T) p, int n);  //对从p开始连续的n个节点插入排序
	*/


public:
	// 构造函数
	SList() //默认构造函数
	{
		init();
	}

	SList(SList<T> const& L)  //整体复制列表L
	{
		copyNodes(L.first(), L.size());
	}

	SList(SList<T> const& L, Rank r, int n);  //复制列表L中自第r项起的n项

	SList(SListNodePosi(T) p, int n)  //复制列表中自位置p起的n项
	{
		copyNodes(p, n);
	}

	// 析构函数
	~SList();  //释放（包含头、尾哨兵在内的）所有节点

			  // 只读访问接口
	Rank size() const  //规模
	{
		return _size;
	}

	bool empty() const  //判空
	{
		return _size <= 0;
	}

	SListNodePosi(T) operator[] (Rank r) const;  //运算符[]重载，支持循秩访问（效率低）

	SListNodePosi(T) first() const  //首节点位置
	{
		return header->succ;
	}

	SListNodePosi(T) last() const  //末节点位置
	{
		if (size() == 0)
			return nullptr;
		else
		{
			SListNodePosi(T) p = first();  //从首节点出发
			while (p->succ)
				p = p->succ;  //顺数第r个节点即是
			return p;  //目标节点，返回位置
		}
	}



	// 可写访问接口
	SListNodePosi(T) insertAsFirst(T const& e);  //将e当作首节点插入

	SListNodePosi(T) insertAsLast(T const& e);  //将e当作末节点插入

	T removeSucc(SListNodePosi(T) p);  //删除合法位置p处的节点,返回被删除节点

	void reverse();  //前后倒置

	/*
	bool valid(SListNodePosi(T) p)  //判断位置p是否对外合法
	{
		return p && (trailer != p);  //将头、尾节点等同于nullptr
	}

	int disordered() const;  //判断列表是否已排序

	SListNodePosi(T) find(T const& e) const  //无序列表查找
	{
		return find(e, _size, trailer);
	}

	SListNodePosi(T) find(T const& e, int n, SListNodePosi(T) p) const;  //无序区间查找

	SListNodePosi(T) search(T const& e) const  //有序列表查找
	{
		return search(e, _size, trailer);
	}
	SListNodePosi(T) search(T const& e, int n, SListNodePosi(T) p) const;  //有序区间查找

	SListNodePosi(T) selectMax(SListNodePosi(T) p, int n);  //在p及其n-1个后继中选出最大者

	SListNodePosi(T) selectMax()
	{
		return selectMax(header->succ, _size);
	}  //整体最大者

	   // 可写访问接口




	SListNodePosi(T) insertA(SListNodePosi(T) p, T const& e);  //将e当作p的后继插入（After）

	SListNodePosi(T) insertB(SListNodePosi(T) p, T const& e);  //将e当作p的前驱插入（Before）



	void merge(SList<T>& L)   //全列表归并
	{
		merge(header->succ, _size, L, L.header->succ, L._size);
	}

	void sort(SListNodePosi(T) p, int n);  //列表区间排序

	void sort()   //列表整体排序
	{
		sort(first(), _size);
	}

	int deduplicate();  //无序去重

	int uniquify();  //有序去重

	

					 // 遍历
	void traverse(void(*visit) (T&));  //遍历，依次实施visit操作（函数指针，只读或局部性修改）

	template <typename VST>  //操作器
	void traverse(VST& visit);  //遍历，依次实施visit操作（函数对象，可全局性修改）*/
};





/* 节点结构模板实现 */
template <typename T>
SListNodePosi(T) SListNode<T>::insertAsSucc(T const& e)  //将e紧随当前节点之后插入于当前节点所属列表（
{
	SListNodePosi(T) x = new SListNode(e, succ);  //创建新节点
	succ = x;
	return x;  //返回新节点的位置
}


/* 列表类模板实现 */
template <typename T>
void SList<T>::init()  //列表初始化，在创建列表对象时统一调用
{
	header = new SListNode<T>;  //创建头哨兵节点
	header->succ = nullptr;
	_size = 0;  //记录规模
}

template <typename T>
SListNodePosi(T) SList<T>::insertAsFirst(T const& e)  //e当作末节点插入
{
	_size++;
	return header->insertAsSucc(e);
}

template <typename T>
SListNodePosi(T) SList<T>::insertAsLast(T const& e)  //e当作末节点插入
{
	_size++;
	if (size() - 1 == 0)
		return header->insertAsSucc(e);
	else
		return last()->insertAsSucc(e);
}


template <typename T>
void SList<T>::copyNodes(SListNodePosi(T) p, int n)  //列表内部方法：用 p 之后的 n 项初始化自身
{  //p合法，且至少有n-1个真后继节点
	init();  //创建头哨兵节点并做初始化
	while (n--)
	{
		insertAsLast(p->data);  //将起自p的n项依次作为末节点插入
		p = p->succ;
	}
}

template <typename T>
SList<T>::SList(SList<T> const& L, Rank r, int n)
{
	SListNodePosi(T) p = L.first();  //从首节点出发
	while (0 < r--)
		p = p->succ;
	copyNodes(p, n);
}

template <typename T>
SListNodePosi(T) SList<T>::operator[] (Rank r) const  //重载加法操作符，以通过秩直接访问节点位置（复杂度O(n)）
{
	if (size() == 0)
		return nullptr;
	else
	{
		SListNodePosi(T) p = first();  //从首节点出发
		while (0 < r--)
			p = p->succ;  //顺数第r个节点即是
		return p;  //目标节点，返回位置
	}

}

template <typename T>
T SList<T>::removeSucc(SListNodePosi(T) p)  //删除合法节点p的后继，返回其数值，复杂度 O(1)
{
	if (p->succ)
	{
		SListNodePosi(T) q;
		T e = p->succ->data;    //备份待删除节点的数值（假定T类型可直接赋值）
		q = p->succ;            //将指向 p 后继的一个指针暂存为 q
		p->succ = q->succ;      //重置 p 的后继
		delete q;               //通过 q 删除 p
		_size--;                //更新规模
		return e;               //返回备份的数值
	}
	else
	{
		return p->data;
	}
}


template <typename T>  //清空列表
int SList<T>::clear()
{
	int oldSize = _size;
	while (0 < _size)
		removeSucc(header); //反复删除首节点，直至列表变空
	return oldSize;
}

template <typename T>
SList<T>::~SList()
{
	clear();
	delete header;
}

template <typename T>
void SList<T>::reverse()
{
	SListNodePosi(T) p, q, pr;
	p = header->succ;
	q = NULL;
	header->succ = NULL;
	while (p) {
		pr = p->succ;
		p->succ = q;
		q = p;
		p = pr;
	}
	head->succ = q;
	return head;
}