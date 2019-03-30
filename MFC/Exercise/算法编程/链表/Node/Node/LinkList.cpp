#include"LinkList.h"
#include<iostream>
using namespace std;

LinkList::LinkList()
{
	head = nullptr;
	length = 0;
}

LinkList::~LinkList()
{
	node* p;
	while (head != nullptr)
	{
		p = head;
		head = head->next;
		delete p;
	}
}
void LinkList::insert(int val, int pos)
{
	if (pos < 0)
	{
		cout << "只能在大于0的位置插入链表！" << endl;
	}
	int index = 1;
	node* temp = head;
	node* newnode = new node;
	if (pos == 0)
	{
		newnode->value = val;
		head= newnode;
		newnode->next = temp;
		length++;
		return;
	}
	while (temp != nullptr&&index < pos)
	{
		temp = temp->next;
		index++;
	}
	if (temp == nullptr)
	{
		cout << "Insert Failed!" << endl;
		return;
	}
	newnode->value = val;
	newnode->next = temp->next;
	temp->next = newnode;
	length++;
}

void LinkList::print()
{
	if (head == nullptr)
	{
		cout << "链表为空！" << endl;
		return;
	}
	node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}

int LinkList::Find(int val)
{
	int pos=0;
	node* temp = head;
	while (temp != nullptr)
	{
		if (temp->value == val)
		{
			return pos;
		}
		temp = temp->next;
		pos++;
	}
	return -1;
}
void LinkList::Remove(int val)
{
	int pos = Find(val);
	if (pos == -1)
	{
		cout << "链表中无此数！" << endl;
	}
	if (pos == 0)
	{
		head = head->next;
		--length;
		return;
	}
	node* temp = head;
	int index=1;
	if (pos > 0)
	{
		while (index<pos)
		{
			temp = temp->next;
			++index;
		}
		temp->next = temp->next->next;
		--length;
		return;
	}
}

void LinkList::Reverse()
{

	if (head == nullptr)
	{
		return;
	}
	node* headnode = head;
	node* nextnode = head->next;
	node* temp;
	while (nextnode != nullptr)
	{
		temp = nextnode->next;
		nextnode->next = headnode;
		headnode = nextnode;
		nextnode = temp;
	}
	head->next = nullptr;
	head = headnode;
}

int LinkList::Length()
{
	return length;
}