#include"LinkList.h"
#include<iostream>
using namespace std;

int main(){
	LinkList list;
	list.print();
	list.insert(1, 0);
	list.insert(12, 1);
	list.insert(25, 2);
	list.print();
	list.Reverse();
	list.print();
	cout << "³¤¶ÈÊÇ:" << list.Length();
	//cout<<list.Find(1)<<endl;
	//list.Remove(1);
	//list.print();
	//cout<<list.Find(12)<<endl;

	/*node1.next = &node2;
	cout << node1.next->value << endl;
	cout << sizeof(node) << endl;
	cout << &node1 << endl;
	cout << &node2 << endl;*/

}