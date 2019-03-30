#include"tree.h"


int main()
{
	string s = "ABD##E#F##C##";
	Tree tree;
	tree.CreateBiTree(s);
	cout << "前序遍历输出：";
    tree.preOrder2();
	cout << "中序遍历输出：";
	tree.inOrder2();
	cout << "后序遍历输出：";
	tree.postOrder2();
	cout<<"树高:"<<tree.getHeight()<<endl;
}