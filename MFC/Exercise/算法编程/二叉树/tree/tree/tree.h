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
	//���յݹ鴴����
	BiTreeNode* CreateTree(string& s, int& pos);
	//�ݹ�ǰ�����������
	void pre_Order(BiTreeNode* temp);
	//�ǵݹ�ջǰ�����������
	void pre_Order2(BiTreeNode* temp);
	//�������������
	void in_Order(BiTreeNode* temp);
	//�ǵݹ�ջ�������������
	void in_Order2(BiTreeNode* temp);
	//�������������
	void post_Order(BiTreeNode* temp);
	//�ǵݹ�ջ�������������
	void post_Order2(BiTreeNode* temp);
	//Ѱ�����߶�
	void get_Height(BiTreeNode* temp, int h);
	//����ǰ��������������ȷ����


public:
	Tree()
	{
		root = nullptr, height = 0;
	};
	//����ǰ�����������
	void CreateBiTree(string s);
	//ǰ�����������
	void preOrder();
	void preOrder2();
	//�������������
	void inOrder();
	void inOrder2();
	//�������������
	void postOrder();
	void postOrder2();
	//Ѱ�����߶�
	int getHeight();

};