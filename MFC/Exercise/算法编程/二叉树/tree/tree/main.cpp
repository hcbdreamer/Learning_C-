#include"tree.h"


int main()
{
	string s = "ABD##E#F##C##";
	Tree tree;
	tree.CreateBiTree(s);
	cout << "ǰ����������";
    tree.preOrder2();
	cout << "������������";
	tree.inOrder2();
	cout << "������������";
	tree.postOrder2();
	cout<<"����:"<<tree.getHeight()<<endl;
}