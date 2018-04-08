#include<iostream>
#include<iomanip>
#include"head.h"

using namespace std;

//判断某个字符是否为数字
inline bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

//字符串长度
int myStrLen(char* pStr)
{
	char* const pHeader = pStr;
	while (*(++pStr));
	return pStr - pHeader;
}

//字符串翻转
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

//字符串连接
void myStrCat(char* pStr1, const char* pStr2)
{
	myStrCpy(pStr1 = pStr1 + myStrLen(pStr1), pStr2);
}

//字符串比较
int myStrCompare(const char* pStr1, const char* pStr2)
{
	while (*(pStr1++) && *(pStr2++))
	{
		if (*pStr1 > *pStr2)
			return 1;
		else if (*pStr1 < *pStr2)
			return -1;
	}
	return 0;
}

//字符串拷贝
void myStrCpy(char* pStr1, const char* pStr2)
{
	while (*(pStr1++) = *(pStr2++));
}

//删除 pStr[index]
void myStrRemove(char *pStr, int index)
{
	while (*pStr)
	{
		pStr++;
		*(pStr + index - 1) = *(pStr + index);
	}
}

//删除数字
void eraseDigital(char *pStr)
{
	char* ins = pStr; //用ins记录待插入位置
	while (!isNumber(*(pStr++))) //将两个指针置于初始位置
		ins++;
	while (*pStr)
	{
		if (!isNumber(*pStr)) //如果pStr所指位置不是数字，
		{
			*(ins++) = *(pStr); //则进行一次插入，并将指针ins后移
		}
		pStr++;
	}
	*ins = '\0';
}


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
	cout << myStrCompare("13341", "133451") << endl;
}