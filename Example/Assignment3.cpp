#include<iostream>
#include<iomanip>
#include"head.h"

using namespace std;

//�ж�ĳ���ַ��Ƿ�Ϊ����
inline bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

//�ַ�������
int myStrLen(char* pStr)
{
	char* const pHeader = pStr;
	while (*(++pStr));
	return pStr - pHeader;
}

//�ַ�����ת
void myStrReverse(char* pStr)
{
	int len = myStrLen(pStr);
	char* p = pStr + len + 1;
	for (int i = 0; i < len; i++)
	{
		*(p + i) = *(pStr + len - i - 1);
	}
	*(p + len) = '\0';
	myStrCpy(pStr, p);
}

//�ַ�������
void myStrCat(char* pStr1, const char* pStr2)
{
	myStrCpy(pStr1 = pStr1 + myStrLen(pStr1), pStr2);
}

//�ַ����Ƚ�
int myStrCompare(const char* pStr1, const char* pStr2)
{
	while (*(pStr1++) && *(pStr2++))
	{
		if (*pStr1 > *pStr2)
		{
			return 1;
		}
		else if (*pStr1 < *pStr2)
		{
			return -1;
		}
	}
	return 0;
}

//�ַ�������
void myStrCpy(char* pStr1, const char* pStr2)
{
	while (*(pStr1++) = *(pStr2++));
}

//ɾ�� pStr[index]
void myStrRemove(char *pStr, int index)
{
	while (*pStr)
	{
		pStr++;
		*(pStr + index - 1) = *(pStr + index);
	}
}

//ɾ������
void eraseDigital(char *pStr)
{
	char* ins = pStr; //��ins��¼������λ��
	while (!isNumber(*(pStr++))) //������ָ�����ڳ�ʼλ��
	{
		ins++;
	}
	do
	{
		if (!isNumber(*pStr)) //���pStr��ָλ�ò������֣�
		{
			*(ins++) = *(pStr); //�����һ�β��룬����ָ��ins����
		}
	} while (*(pStr++));
}

//��������
void strTest()
{
	char myChar[100] = { '0','1','2','3','\0' };
	char* pchar = myChar;
	cout << myStrLen(myChar) << endl;
	myStrRemove(pchar, 1);
	cout << pchar << endl;
	myStrCat(pchar, "123456789abcde");
	cout << pchar << endl;
	myStrCpy(pchar, "987654321");
	cout << pchar << endl;
	myStrReverse(pchar);
	cout << pchar << endl;
	myStrCat(pchar, "a1b2c3d4");
	cout << pchar << endl;
	myStrCpy(pchar, "we23wr245e3er5");
	cout << pchar << endl;
	eraseDigital(pchar);
	cout << pchar << endl;
	myStrCpy(pchar, "45254");
	cout << pchar << endl;
	eraseDigital(pchar);
	cout << pchar << endl;
	cout << myStrCompare("13341", "133451") << endl;
}