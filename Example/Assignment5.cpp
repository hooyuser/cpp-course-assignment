#include<iostream>
#include<iomanip>
#include<fstream>
#include"head.h"

using namespace std;

void DelList(stuNode* head)          //������ head Ϊ�׽ڵ������
{
	stuNode* p;
	p = head;                     //����ɾ���ڵ� p ��ʼ��Ϊ head
	while (head->next != NULL)    //�� head ����β�ڵ�ʱ��
	{
		head = head->next;			//head ����
		delete p;                   //ɾ�� p �ڵ�
		p = head;                   //�ٴν���ɾ���ڵ� p ����Ϊ head
	}
	delete head;                  //��ʱ head Ϊβ�ڵ㣬ɾ�� head
}

void swapNode(stuNode* pPreA, stuNode* pA, stuNode* pB)  //�����ڵ�
{
	pPreA->next = pB;
	pA->next = pB->next;
	pB->next = pA;
}

void delNode(stuNode* p)            //ɾ�� p �ڵ�ĺ��
{
	stuNode* pNext;
	if (p->next != NULL)
	{
		pNext = p->next;            //��ָ�� p ��̵�һ��ָ���ݴ�Ϊ pNext
		p->next = pNext->next;      //���� p �ĺ��
		delete pNext;               //ͨ�� q ɾ�� p
	}
}

stuNode* insertInnerNode(stuNode* p, stuNode* ins)  //�������е� ins->next �Ƴ������ڽڵ� p ����롣�� ins ���б�ĵ� n ������б�ĵ� n+1 ��
{
	if (p == ins) return ins->next;
	stuNode* insNext = ins->next;               //Ϊ ins->next ��ָ�ռ��½�ָ��
	ins->next = insNext->next;                  //���� ins �ĺ�� 
	insNext->next = p->next;                    //���� insNext �ĺ��
	p->next = insNext;                          //���� p �ĺ��
	return ins;                                 //��Ϊ ins ֮���ĳ��Ƶ� ins ֮ǰ��ins ��Ϊ�б�ĵ� n+1 ��
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
	return endNode;
}

void listInsertSort_D(stuNode* head)    //����������򣨽���
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	stuNode* p = head->next;
	while (p != NULL && p->next != NULL)
	{
		p = insertInnerNode(searchLessThan(head, p, p->next->fScore[4]), p); //�� p->next ���뵽 head �� p ֮����ʵ�λ��	
	}
}

void readTxtFile(const char* fileName)
{
	ifstream in;
	in.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\ѧ���ɼ��������1.txt");
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
	out.open("D:\\CHY\\Program\\C++\\Textbook\\Example\\Example\\����ɼ�.txt");
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




