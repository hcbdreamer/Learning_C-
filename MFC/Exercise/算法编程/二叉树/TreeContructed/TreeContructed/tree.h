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
	//���յݹ鴴����
	//BiTreeNode* CreateTree(string& s, int& pos);
	//ǰ�����������
	void pre_Order(BiTreeNode* temp);
	//�������������
	void in_Order(BiTreeNode* temp);
	//�������������
	void post_Order(BiTreeNode* temp);
	//Ѱ�����߶�
	void get_Height(BiTreeNode* temp, int h);
	//����ǰ��������������ȷ����
	BiTreeNode* ConstructNode(int* startPreorder, int*endPreorder, int* startInorder, int* endInorder);


public:
	Tree()
	{
		root = nullptr, height = 0;
	};
	//����ǰ�����������
	//void CreateBiTree(string s);
	//ǰ�����������
	void preOrder();
	//�������������
	void inOrder();
	//�������������
	void postOrder();
	//Ѱ�����߶�
	int getHeight();
    //����ǰ��������������ȷ����
	BiTreeNode* Construct(int* preorder, int* inorder, int length);
	//���Գ���
	void Test(char* testName, int* preorder, int* inorder, int length);

	void Test1();
	void Test2();
	void Test3();
	void Test4();
	void Test5();
	void Test6();
	void Test7();
};