#include"queue.h"
#include<iostream>
using namespace std;

void Test(char* real, char* virtu)
{
	if (*real == *virtu)
	{
		cout << "ɾ����������ж�������ƥ�䣡" << endl;
	}
	else
	{
		cout << "��ƥ�䣡" << endl;
	}
}

int main()
{
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char head = queue.deleteHead();
	Test(&head, &a);
	head=queue.deleteHead();
	Test(&head, &b);
    head=queue.deleteHead();
	Test(&head, &c);
	char d = 'd';
	char e = 'e';
	queue.appendTail(e);
	head=queue.deleteHead();
	Test(&head, &c);
	Test(&head, &e);
}