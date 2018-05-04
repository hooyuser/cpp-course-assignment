#include<iostream>
#include<iomanip>
#include<fstream>
#include"head.h"

using namespace std;

void DelList(stuNode* head)          //销毁以 head 为首节点的链表
{
	stuNode* p;
	p = head;                     //将待删除节点 p 初始化为 head
	while (head->next != NULL)    //当 head 不是尾节点时：
	{
		head = head->next;			//head 后移
		delete p;                   //删除 p 节点
		p = head;                   //再次将待删除节点 p 设置为 head
	}
	delete head;                  //此时 head 为尾节点，删除 head
}

void swapNode(stuNode* pPreA, stuNode* pA, stuNode* pB)  //交换节点
{
	pPreA->next = pB;
	pA->next = pB->next;
	pB->next = pA;
}

void delNode(stuNode* p)            //删除 p 节点的后继
{
	stuNode* pNext;
	if (p->next != NULL)
	{
		pNext = p->next;            //将指向 p 后继的一个指针暂存为 pNext
		p->next = pNext->next;      //重置 p 的后继
		delete pNext;               //通过 q 删除 p
	}
}

stuNode* insertInnerNode(stuNode* p, stuNode* ins)  //将链表中的 ins->next 移除，并在节点 p 后插入。若 ins 是列表的第 n 项，返回列表的第 n+1 项
{
	if (p == ins) return ins->next;
	stuNode* insNext = ins->next;               //为 ins->next 所指空间新建指针
	ins->next = insNext->next;                  //重置 ins 的后继 
	insNext->next = p->next;                    //重置 insNext 的后继
	p->next = insNext;                          //重置 p 的后继
	return ins;                                 //因为 ins 之后的某项被移到 ins 之前，ins 成为列表的第 n+1 项
}

void insertNode(stuNode* p, stuNode* newp)  //在 p 后插入节点 newp
{
	newp->next = p->next;             //设置 newp 的后继
	p->next = newp;                   //重置 p 的后继 
}


stuNode* searchLessThan(stuNode* startNode, stuNode* endNode, int key)  //返回 startNode->next 与 endNode 之间第一个 fScore[4] <= key 的节点的前驱，若无，返回endNode
{
	if (startNode == NULL) return NULL;
	stuNode* p = startNode;
	while (p != endNode)          //当 p 不是尾节点时
	{
		if (p->next->fScore[4] <= key)      //如果 p 的后继的 score 小于 key
		{
			return p;
		}
		p = p->next;
	}
	return endNode;
}

void listInsertSort_D(stuNode* head)    //插入排序（降序）
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	stuNode* p = head->next;
	while (p != NULL && p->next != NULL)
	{
		p = insertInnerNode(searchLessThan(head, p, p->next->fScore[4]), p); //将 p->next 插入到 head 到 p 之间的适当位置	
	}
}

void readTxtFile(const char* fileName)
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\学生成绩链表测试1.txt");
	if (!in.is_open()) return;
	int nStuCount = 0;

	in >> nStuCount;

	stuNode* pHeader = new stuNode();
	stuNode* pT = pHeader;
	for (int i = 0; i < nStuCount; i++)
	{
		char cTemp[128];
		stuNode* pStu = new stuNode();
		in >> pStu->sNum >> pStu->sName >> cTemp >> cTemp;
		for (int j = 0; j < 5; j++)
		{
			in >> pStu->fScore[j];
		}
		pT->next = pStu;
		pT = pT->next;
		pT->next = NULL;
	}
	in.close();

	listInsertSort_D(pHeader);

	ofstream out;
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\输出成绩.txt");
	pT = pHeader->next;
	while (pT)
	{
		out << pT->sNum << "  " << setiosflags(ios::left) << setw(6) << pT->sName << "  ";
		for (int j = 0; j < 5; j++)
		{
			out << pT->fScore[j] << " ";
		}
		out << endl;
		pT = pT->next;
	}
	out.close();

	DelList(pHeader);
}
