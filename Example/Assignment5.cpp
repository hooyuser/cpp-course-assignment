#include<iostream>
#include<fstream>
#include"head.h"

using namespace std;


void swapNode(stuNode* pPreA, stuNode* pA, stuNode* pB)  //�����ڵ�
{
	pPreA->next = pB;
	pA->next = pB->next;
	pB->next = pA;
}

void delNode(stuNode* p)           //ɾ�� p �ڵ�ĺ��
{
	stuNode* pNext;
	if (p->next != NULL)
	{
		pNext = p->next;            //��ָ�� p ��̵�һ��ָ���ݴ�Ϊ pNext
		p->next = pNext->next;      //���� p �ĺ��
		delete pNext;               //ͨ�� q ɾ�� p
	}
}

stuNode* insertInnerNode(stuNode* p, stuNode* ins)  //�������е� ins->next �Ƴ������ڽڵ� p ����룬�����µ� ins-next
{
	if (p == ins) return p;
	stuNode* insNext = ins->next;               //Ϊ ins->next ��ָ�ռ��½�ָ��
	ins->next = insNext->next;                  //���� ins �ĺ�� 
	insNext->next = p->next;                    //���� insNext �ĺ��
	p->next = insNext;                          //���� p �ĺ��
	return insNext;
}

void insertNode(stuNode* p, stuNode* newp)  //�� p �����ڵ� newp
{
	newp->next = p->next;             //���� newp �ĺ��
	p->next = newp;                   //���� p �ĺ�� 
}


stuNode* searchLessThan(stuNode* startNode, stuNode* endNode, int key)  //���� startNode->next �� endNode ֮���һ�� fScore[4] <= key �Ľڵ��ǰ�������ޣ�����endNode
{
	if (startNode == NULL) return NULL;
	stuNode* p = startNode;
	while (p != endNode)          //�� p ����β�ڵ�ʱ
	{
		if (p->next->fScore[4] <= key)      //��� p �ĺ�̵� score С�� key
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

void listInsertSort_D(stuNode* head)    //�������򣨽���
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	stuNode* p = head->next;
	while (p->next != NULL)
	{
		p = insertInnerNode(searchLessThan(head, p, p->next->fScore[4]), p); //�� p->next ���뵽 head �� p ֮����ʵ�λ��	
		p = p->next;
	}
}

void readTxtFile(const char* fileName)
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\ѧ���ɼ��������1.txt");
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
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\����ɼ�.txt");
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
