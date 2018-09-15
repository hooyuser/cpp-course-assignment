#pragma once
/********************************/
/******EXAMPLES IN TEXTBOOK******/
/********************************/
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


//Chapter4
void P4_1();
namespace P4_2 { void P4_2(); }
void P4_3();
namespace P4_4 { void P4_4(); }
namespace P4_5 { void P4_5(); }
void P4_6();
namespace P4_7 { void P4_7(); }


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
namespace P6_3 { void P6_3(); }
namespace P6_4 { void P6_4(); }
namespace P6_5 { void P6_5(); }
namespace P6_6 { void P6_6(); }
namespace P6_7 { void P6_7(); }

//Chapter7
namespace P7_1 { void P7_1(); }
namespace P7_2 { void P7_2(); }
namespace P7_3 { void P7_3(); }
namespace P7_4 { void P7_4(); }
namespace P7_5 { void P7_5(); }
namespace P7_6 { void P7_6(); }
namespace P7_7 { void P7_7(); }
namespace P7_8 { void P7_8(); }
namespace P7_9 { void P7_9(); }
namespace P7_10 { void P7_10(); }

//Chapter8
void P8_1();
void P8_2();
void P8_3();

/**********************/
/******ASSIGNMENT******/
/**********************/
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
template<class T>  //�����ֽڵ���
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
void toBitArray(const T a, char* bitArray) //�� a ��ռ�ڴ��еĶ�������ת��Ϊ '0'��'1' ��ɵ� char ���飬�������ҵ�ַ�ɵ͵���
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

typedef int Rank;  //��
#define SListNodePosi(T) SListNode<T> *  //�б�ڵ�λ��

/* �б�ڵ�ģ��ṹ */
template <typename T>
struct SListNode
{
	// ��Ա
	T data;                 //��ֵ
	SListNodePosi(T) succ;  //���

	// ���캯��					   
	SListNode() {}          //���ڹ���header
	SListNode(T e, SListNodePosi(T) s = nullptr) : data(e), succ(s) {}      //Ĭ�Ϲ�����

	// �����ӿ�									
	SListNodePosi(T) insertAsSucc(T const& e);  //���浱ǰ�ڵ�֮������½ڵ�
};




/* �б�ģ���� */
template <typename T>
class SList
{
private:
	int _size;  //��ģ
	SListNodePosi(T) header;  //ͷ�ڱ�

protected:
	void init();  //�б���ʱ�ĳ�ʼ��

	int clear();  //������нڵ�

	void copyNodes(SListNodePosi(T) p, int n);  //�����б�����λ��p���n��

	/*
	void merge(SListNodePosi(T)& pp, int n, SList<T>& L, SListNodePosi(T) q, int m);  //�鲢

	void mergeSort(SListNodePosi(T)& p, int n);  //�Դ�p��ʼ������n���ڵ�鲢����

	void selectionSort(SListNodePosi(T) p, int n);  //�Դ�p��ʼ������n���ڵ�ѡ������

	void insertionSort(SListNodePosi(T) p, int n);  //�Դ�p��ʼ������n���ڵ��������
	*/


public:
	// ���캯��
	SList() //Ĭ�Ϲ��캯��
	{
		init();
	}

	SList(SList<T> const& L)  //���帴���б�L
	{
		copyNodes(L.first(), L.size());
	}

	SList(SList<T> const& L, Rank r, int n);  //�����б�L���Ե�r�����n��

	SList(SListNodePosi(T) p, int n)  //�����б�����λ��p���n��
	{
		copyNodes(p, n);
	}

	// ��������
	virtual ~SList();  //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�

			  // ֻ�����ʽӿ�
	Rank size() const  //��ģ
	{
		return _size;
	}

	bool empty() const  //�п�
	{
		return _size <= 0;
	}

	SListNodePosi(T) operator[] (Rank r) const;  //�����[]���أ�֧��ѭ�ȷ��ʣ�Ч�ʵͣ�

	SListNodePosi(T) first() const  //�׽ڵ�λ��
	{
		return header->succ;
	}

	SListNodePosi(T) last() const  //ĩ�ڵ�λ��
	{
		if (size() == 0)
			return nullptr;
		else
		{
			SListNodePosi(T) p = first();  //���׽ڵ����
			while (p->succ)
				p = p->succ;  //˳����r���ڵ㼴��
			return p;  //Ŀ��ڵ㣬����λ��
		}
	}

	// ��д���ʽӿ�
	SListNodePosi(T) insertAsFirst(T const& e);  //��e�����׽ڵ����

	SListNodePosi(T) insertAsLast(T const& e);  //��e����ĩ�ڵ����

	T removeSucc(SListNodePosi(T) p);  //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�

	void reverse();  //ǰ����

	void DeleteElement(T const& data)
	{
		SListNodePosi(T) pA=header;
		SListNodePosi(T) pB = header->succ;
		while (pB)
		{
			if (pB->data == data)
			{
				pA->succ = pB->succ;	//�ؽ�pA���	
				delete pB;              //ɾ��pB		
				pB = pA->succ;          //����pBλ��
				continue;
			}
			else
			{
				pA = pA->succ;
				pB = pB->succ;
			}
		}
	}



	/*
	bool valid(SListNodePosi(T) p)  //�ж�λ��p�Ƿ����Ϸ�
	{
		return p && (trailer != p);  //��ͷ��β�ڵ��ͬ��nullptr
	}

	int disordered() const;  //�ж��б��Ƿ�������

	SListNodePosi(T) find(T const& e) const  //�����б����
	{
		return find(e, _size, trailer);
	}

	

	SListNodePosi(T) find(T const& e, int n, SListNodePosi(T) p) const;  //�����������

	SListNodePosi(T) search(T const& e) const  //�����б����
	{
		return search(e, _size, trailer);
	}
	SListNodePosi(T) search(T const& e, int n, SListNodePosi(T) p) const;  //�����������

	SListNodePosi(T) selectMax(SListNodePosi(T) p, int n);  //��p����n-1�������ѡ�������

	SListNodePosi(T) selectMax()
	{
		return selectMax(header->succ, _size);
	}  //���������

	   // ��д���ʽӿ�




	SListNodePosi(T) insertA(SListNodePosi(T) p, T const& e);  //��e����p�ĺ�̲��루After��

	SListNodePosi(T) insertB(SListNodePosi(T) p, T const& e);  //��e����p��ǰ�����루Before��



	void merge(SList<T>& L)   //ȫ�б�鲢
	{
		merge(header->succ, _size, L, L.header->succ, L._size);
	}

	void sort(SListNodePosi(T) p, int n);  //�б���������

	void sort()   //�б���������
	{
		sort(first(), _size);
	}

	int deduplicate();  //����ȥ��

	int uniquify();  //����ȥ��

	
					 // ����
	void traverse(void(*visit) (T&));  //����������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�

	template <typename VST>  //������
	void traverse(VST& visit);  //����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�*/
};



/* �ڵ�ṹģ��ʵ�� */
template <typename T>
SListNodePosi(T) SListNode<T>::insertAsSucc(T const& e)  //��e���浱ǰ�ڵ�֮������ڵ�ǰ�ڵ������б�
{
	SListNodePosi(T) x = new SListNode(e, succ);  //�����½ڵ�
	succ = x;
	return x;  //�����½ڵ��λ��
}


/* �б���ģ��ʵ�� */
template <typename T>
void SList<T>::init()  //�б��ʼ�����ڴ����б����ʱͳһ����
{
	header = new SListNode<T>;  //����ͷ�ڱ��ڵ�
	header->succ = nullptr;
	_size = 0;  //��¼��ģ
}

template <typename T>
SListNodePosi(T) SList<T>::insertAsFirst(T const& e)  //e����ĩ�ڵ����
{
	_size++;
	return header->insertAsSucc(e);
}

template <typename T>
SListNodePosi(T) SList<T>::insertAsLast(T const& e)  //e����ĩ�ڵ����
{
	_size++;
	if (size() - 1 == 0)
		return header->insertAsSucc(e);
	else
		return last()->insertAsSucc(e);
}


template <typename T>
void SList<T>::copyNodes(SListNodePosi(T) p, int n)  //�б��ڲ��������� p ֮��� n ���ʼ������
{  //p�Ϸ�����������n-1�����̽ڵ�
	init();  //����ͷ�ڱ��ڵ㲢����ʼ��
	while (n--)
	{
		insertAsLast(p->data);  //������p��n��������Ϊĩ�ڵ����
		p = p->succ;
	}
}

template <typename T>
SList<T>::SList(SList<T> const& L, Rank r, int n)
{
	SListNodePosi(T) p = L.first();  //���׽ڵ����
	while (0 < r--)
		p = p->succ;
	copyNodes(p, n);
}

template <typename T>
SListNodePosi(T) SList<T>::operator[] (Rank r) const  //����[]����������ͨ����ֱ�ӷ��ʽڵ�λ�ã����Ӷ�O(n)��
{
	if (size() == 0)
		return nullptr;
	else
	{
		SListNodePosi(T) p = first();  //���׽ڵ����
		while (0 < r--)
			p = p->succ;  //˳����r���ڵ㼴��
		return p;  //Ŀ��ڵ㣬����λ��
	}
}

template <typename T>
T SList<T>::removeSucc(SListNodePosi(T) p)  //ɾ���Ϸ��ڵ�p�ĺ�̣���������ֵ�����Ӷ� O(1)
{
	if (p->succ)
	{
		SListNodePosi(T) q;
		T e = p->succ->data;    //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
		q = p->succ;            //��ָ�� p ��̵�һ��ָ���ݴ�Ϊ q
		p->succ = q->succ;      //���� p �ĺ��
		delete q;               //ͨ�� q ɾ�� p
		_size--;                //���¹�ģ
		return e;               //���ر��ݵ���ֵ
	}
	else
	{
		return p->data;
	}
}


template <typename T>  //����б�
int SList<T>::clear()
{
	int oldSize = _size;
	while (0 < _size)
		removeSucc(header); //����ɾ���׽ڵ㣬ֱ���б���
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
	SListNodePosi(T) p;
	SListNodePosi(T) q;
	SListNodePosi(T) pr;
	p = header->succ;
	q = NULL;
	header->succ = NULL;
	while (p) 
	{
		pr = p->succ;
		p->succ = q;
		q = p;
		p = pr;
	}
	header->succ = q;
}