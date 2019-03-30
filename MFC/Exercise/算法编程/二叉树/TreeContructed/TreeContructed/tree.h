#include<iostream>
#include<string>
using namespace std;

struct BiTreeNode
{
	int value;
	BiTreeNode* Ltree;
	BiTreeNode* Rtree;
};

class Tree
{
private:
	BiTreeNode* root;
	int height;
	//按照递归创建数
	//BiTreeNode* CreateTree(string& s, int& pos);
	//前序遍历二叉树
	void pre_Order(BiTreeNode* temp);
	//中序遍历二叉树
	void in_Order(BiTreeNode* temp);
	//后序遍历二叉树
	void post_Order(BiTreeNode* temp);
	//寻找树高度
	void get_Height(BiTreeNode* temp, int h);
	//根据前序遍历和中序遍历确定树
	BiTreeNode* ConstructNode(int* startPreorder, int*endPreorder, int* startInorder, int* endInorder);


public:
	Tree()
	{
		root = nullptr, height = 0;
	};
	//按照前序遍历创建树
	//void CreateBiTree(string s);
	//前序遍历二叉树
	void preOrder();
	//中序遍历二叉树
	void inOrder();
	//后序遍历二叉树
	void postOrder();
	//寻找树高度
	int getHeight();
    //根据前序遍历和中序遍历确定树
	BiTreeNode* Construct(int* preorder, int* inorder, int length);
	//测试程序
	void Test(char* testName, int* preorder, int* inorder, int length);

	void Test1();
	void Test2();
	void Test3();
	void Test4();
	void Test5();
	void Test6();
	void Test7();
};