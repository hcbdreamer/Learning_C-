#include<iostream>
#include<string>
using namespace std;

struct BiTreeNode
{
	char data;
	BiTreeNode* Ltree;
	BiTreeNode* Rtree;
};


class Tree
{
private:
	BiTreeNode* root;
	int height;
	//按照递归创建数
	BiTreeNode* CreateTree(string& s, int& pos);
	//递归前序遍历二叉树
	void pre_Order(BiTreeNode* temp);
	//非递归栈前序遍历二叉树
	void pre_Order2(BiTreeNode* temp);
	//中序遍历二叉树
	void in_Order(BiTreeNode* temp);
	//非递归栈中序遍历二叉树
	void in_Order2(BiTreeNode* temp);
	//后序遍历二叉树
	void post_Order(BiTreeNode* temp);
	//非递归栈后序遍历二叉树
	void post_Order2(BiTreeNode* temp);
	//寻找树高度
	void get_Height(BiTreeNode* temp, int h);
	//根据前序遍历和中序遍历确定树


public:
	Tree()
	{
		root = nullptr, height = 0;
	};
	//按照前序遍历创建树
	void CreateBiTree(string s);
	//前序遍历二叉树
	void preOrder();
	void preOrder2();
	//中序遍历二叉树
	void inOrder();
	void inOrder2();
	//后序遍历二叉树
	void postOrder();
	void postOrder2();
	//寻找树高度
	int getHeight();

};