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


void insertNode(stuNode* p, stuNode* newp)  //p 后插入节点 newp
{
	newp->next = p->next;             //设置 newp 的后继
	p->next = newp;                   //重置 p 的后继 
}


stuNode* searchLessThan(stuNode* startNode, stuNode* endNode, int key)  //返回 startNode->next 与 endNode 之间第一个 fScore[4] <= key 的节点的前驱，若无，返回endNode
{
	if (startNode) return;
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
	if (head)return;
	if (head->next) return;
	stuNode* p = head->next;
	while (p->next)
	{
		insertNode(searchLessThan(head, p, p->next->fScore[4]), p->next);
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
		pT->next = 0;
	}
	in.close();

	stuNode* pStart = pHeader;
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
