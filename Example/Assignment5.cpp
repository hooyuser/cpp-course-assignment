#include<iostream>
#include<fstream>
#include"head.h"

using namespace std;


void swapNode(stuNode* pPreA, stuNode* pA, stuNode* pB)  //交换节点
{
	pPreA->next = pB;
	pA->next = pB->next;
	pB->next = pA;
}

void delNode(stuNode* p)           //删除 p 节点的后继
{
	stuNode* pNext;
	if (p->next != NULL)
	{
		pNext = p->next;            //将指向 p 后继的一个指针暂存为 pNext
		p->next = pNext->next;      //重置 p 的后继
		delete pNext;               //通过 q 删除 p
	}
}

stuNode* insertInnerNode(stuNode* p, stuNode* ins)  //将链表中的 ins->next 移除，并在节点 p 后插入，返回新的 ins-next
{
	if (p == ins) return p;
	stuNode* insNext = ins->next;               //为 ins->next 所指空间新建指针
	ins->next = insNext->next;                  //重置 ins 的后继 
	insNext->next = p->next;                    //重置 insNext 的后继
	p->next = insNext;                          //重置 p 的后继
	return insNext;
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
	return p;
}

void listInsertSort_D(stuNode* head)    //插入排序（降序）
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	stuNode* p = head->next;
	while (p->next != NULL)
	{
		p = insertInnerNode(searchLessThan(head, p, p->next->fScore[4]), p); //将 p->next 插入到 head 到 p 之间的适当位置	
		p = p->next;
	}
}

void readTxtFile(const char* fileName)
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\学生成绩链表测试1.txt");
	if (!in.is_open()) return;
	int nStuCount = 0;
	char cTemp[128];
	in >> nStuCount;

	stuNode* pHeader = new stuNode();
	stuNode* pT = pHeader;
	for (int i = 0; i < nStuCount; i++)
	{
		stuNode* pStu = new stuNode();

		in >> pStu->sName >> pStu->sNum >> cTemp >> cTemp;
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

	/*stuNode* pStart = pHeader;
	while (pStart->next->next->next != 0)
	{
		stuNode* pPreA = pStart;
		stuNode* pA = pStart->next;
		stuNode* pB = pStart->next->next;
		while (pB->next != 0)
		{
			if (pA->fScore[4] < pB->fScore[4])
			{
				pPreA->next = pB;
				pA->next = pB->next;
				pB->next = pA;
			}
			pPreA = pPreA->next;
			pA = pA->next;
			pB = pB->next;
		}
		pStart = pStart->next;
	}
	*/

	ofstream out;
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\输出成绩.txt");
	pT = pHeader->next;
	while (pT)
	{
		out << pT->sName << "  " << pT->sNum << "  ";
		for (int j = 0; j < 5; j++)
		{
			out << pT->fScore[j] << " ";
		}
		out << endl;
		pT = pT->next;
	}
	out.close();


}
