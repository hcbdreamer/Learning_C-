/*
������ʵ��
1.����������
2.�ݹ����������
2.1�ݹ��������
2.2�ݹ��������
2.3�ݹ�������
3.�ǵݹ����
3.1�ǵݹ��������
3.2�ǵݹ��������
3.3�ǵݹ�������
4.��α���������
5.������
6.����Ҷ�ӽڵ�
7.��ֵ���Ҷ�Ӧ�ڵ㣬������ӽ��ֵ���Һ��ӽ��ֵ
8.�������нڵ���
*/
#include<iostream>  
#include<string>  
#include<stack>  
#include<deque>  
#include<fstream>  
using namespace std;

//const int MAX_N = 100;  
//���ݽڵ�  
class Node
{
public:
	char data;//����  
	class Node *lchild;//��ڵ�  
	class Node *rchild;//�ҽڵ�  
};

//������  
class Tree
{
public:
	Tree(){}
	~Tree(){}

	//����������  
	void Create(string name)
	{
		ifstream readfile;
		string str;
		readfile.open(name);
		if (readfile.is_open())
		{
			getline(readfile, str);//��ȡһ��  
		}
		readfile.close();
		CreateNode(str);//����������  
	}


	//��������ǵݹ��㷨  
	void Disp()
	{
		if (t == NULL)
		{
			return;
		}
		stack<Node *> m_stack;//����ջ  
		m_stack.push(t);
		while (!m_stack.empty())
		{
			Node *p = m_stack.top();//��ֵһ�ݵ�ǰ˫�׽ڵ�  
			cout << p->data << ends;
			m_stack.pop();
			if (p->rchild)//�ȴ洢��������ȷ�������������  
			{
				m_stack.push(p->rchild);
			}
			if (p->lchild)//��洢������  
			{
				m_stack.push(p->lchild);
			}
		}

	}

	//�ǵݹ��������������  
	void DispMid()
	{
		if (t == NULL)
		{
			return;
		}
		Node *p = t;
		stack<Node *>m_stack;
		while (p != NULL || !m_stack.empty())
		{
			while (p != NULL)//һ·ֱ�������½�  
			{
				m_stack.push(p);
				p = p->lchild;
			}
			if (!m_stack.empty())
			{
				p = m_stack.top();//���ݵ�ǰջ����ַ  
				m_stack.pop();
				cout << p->data << ends;
				p = p->rchild;
			}
		}
	}

	//�ǵݹ�������������  
	void DispBehid()
	{
		if (t == NULL)
		{
			return;
		}
		Node *pre = NULL, *p = t;
		stack<Node *>m_stack;
		while (p != NULL || !m_stack.empty())
		{
			while (p != NULL)//һ·ֱ�������½�  
			{
				m_stack.push(p);
				p = p->lchild;
			}
			p = m_stack.top();
			//������Ϊ�ջ����ѷ��ʣ������ǰ�ڵ�  
			if (p->rchild == NULL || p->rchild == pre)
			{
				cout << p->data << ends;
				pre = p;//����ǰ����ַ��ֵpre��Ϊ��һ���жϱ�־����ֹ�ظ�����  
				m_stack.pop();
				p = NULL;//p��ֵ���Ա����������  
			}
			else
			{
				p = p->rchild;//����������������  
			}
		}
	}

	//��α���  
	void level_display()
	{
		if (t == NULL)
		{
			return;
		}
		deque<Node *>m_qu;//�������  
		m_qu.push_back(t);//���������  
		while (!m_qu.empty())
		{
			Node *p = m_qu.front();//������ǰ��ͷ  
			cout << p->data << ends;//���  
			m_qu.pop_front();
			if (p->lchild)//���������  
			{
				m_qu.push_back(p->lchild);
			}
			if (p->rchild)//�Һ��������  
			{
				m_qu.push_back(p->rchild);
			}
		}
	}

	//�ݹ�����������������  
	void display()
	{
		cout << "�ݹ�����";
		output(t);
		cout << endl;
	}

	//�ݹ�����������������  
	void displayMid()
	{
		cout << "�ݹ�����:";
		outputMid(t);
		cout << endl;
	}

	//�ݹ����������������  
	void displayBhind()
	{
		cout << "�ݹ����";
		outputBhind(t);
		cout << endl;
	}
	//�������߶�  
	void Height()
	{
		int height = get_height(t);
		cout << "Height: " << height << endl;
	}

	//���Ҷ�ӽڵ�ֵ  
	void display_leaf()
	{
		cout << "Leaves: ";
		output_leaf(t);
		cout << endl;
	}

	//���Ҷ�������ֵdata��Ϊelem�Ľڵ�  
	void find_node(char elem)
	{
		Node *res = NULL;
		res = find_node(t, elem, res);
		if (res != NULL)
		{
			cout << "nice." << endl;
			if (res->lchild)
			{
				cout << "left child:";
				cout << leftchild(res)->data << endl;
			}
			if (res->rchild)
			{
				cout << "right child:";
				cout << rightchild(res)->data << endl;
			}
		}
		else
		{
			cout << "NO." << endl;
		}
	}

	//����ڵ���  
	void nodes_count()
	{
		int sum;
		if (t == NULL)//��Ϊ�գ���0���ڵ�  
		{
			sum = 0;
		}
		else
		{
			sum = node_count(t);
			cout << "Total Nodes:" << sum + 1 << endl;
		}
	}
private:
	Node *t;

	//����������  
	void CreateNode(string str)
	{
		stack<Node *> m_stack;
		Node *p;
		int k;
		while (str.length() != 0)
		{
			//����ǰΪ'('����˫�׽ڵ�����ջ����һλ�洢��pֵ��Ϊ��ڵ㴦��  
			if (str[0] == '(')
			{
				m_stack.push(p); k = 1;
			}
			//Ϊ��������ջ���˳�һλ  
			else if (str[0] == ')')
			{
				m_stack.pop();
			}
			//Ϊ','������һ���ַ����ҽڵ㴦��  
			else if (str[0] == ',')
			{
				k = 2;
			}
			//�洢ֵ����˫�׽��  
			else
			{
				p = (Node *)malloc(sizeof(Node));
				p->data = str[0];
				p->lchild = p->rchild = NULL;
				//����Ϊ��ʱ������һ���ڵ���Ϊ��������ֵ��˽�г�Ա����  
				if (t == NULL)
				{
					t = p;
				}
				//������Ϊ��  
				else
				{
					if (k == 1)//��Ϊ��ڵ㴦����ջ��˫�׽ڵ����ָ��ָ��ǰ�ڵ�  
					{
						m_stack.top()->lchild = p;
					}
					else//��Ϊ�ҽڵ㴦��  
					{
						m_stack.top()->rchild = p;
					}
				}
			}
			//�ع�������ȥ���ַ������������ȼ�С1  
			str.assign(str.substr(1, str.length() - 1));
		}
	}

	//�ݹ�����������������  
	void output(Node *t)
	{
		if (t != NULL)//��������Ϊ��ʱ  
		{
			cout << t->data;//���  
			if (t->lchild != NULL || t->rchild != NULL)//��/�ҽ�㲻Ϊ��ʱ�ݹ鵽��һ��  
			{
				cout << "(";
				output(t->lchild);
				if (t->rchild != NULL)//����ڵ������������ڵ�ݹ鷵��һ�㣬�ݹ��ҽڵ�  
				{
					cout << ",";
				}
				output(t->rchild);
				cout << ")";
			}
		}
	}

	//�ݹ��������������  
	void outputMid(Node *t)
	{
		if (t == NULL)//���򷵻�  
		{
			return;
		}
		else
		{
			cout << "(";
			outputMid(t->lchild);//�ݹ����ӽڵ�  
			if (t->rchild != NULL)
			{
				cout << ",";
			}
			cout << t->data;//���  
			outputMid(t->rchild);//�ݹ��Һ��ӽ��  
			cout << ")";
		}
	}

	//�ݹ����������������  
	void outputBhind(Node *t)
	{
		if (!t)//���򷵻�  
		{
			return;
		}
		else
		{
			cout << "(";
			outputBhind(t->lchild);//�ݹ����ӽڵ�  
			if (t->rchild != NULL)
			{
				cout << ",";
			}
			outputBhind(t->rchild);//�ݹ��Һ��ӽ��  
			cout << t->data;//���  
			cout << ")";
		}
	}
	//������  
	int get_height(Node *t)
	{
		int leftheight, rightheight;
		if (t == NULL)//�ݹ����������ӽڵ�ʱ����0  
		{
			return 0;
		}
		else
		{
			leftheight = get_height(t->lchild);//�ݹ����������߶�  
			rightheight = get_height(t->rchild);//�ݹ����������߶�  
			return leftheight > rightheight ? leftheight + 1 : rightheight + 1;//�ݹ鷵��ʱ�������ֵ  
		}
	}

	//������ڵ�  
	Node *leftchild(Node *p)
	{
		return p->lchild;
	}

	//�����ҽڵ�  
	Node *rightchild(Node *p)
	{
		return p->rchild;
	}

	//���Ҷ�ӽڵ�  
	void output_leaf(Node *t)
	{
		if (t != NULL)//������Ϊ��ʱ  
		{
			//��ǰ�ڵ�û���ӽڵ�ʱ����ڵ�����  
			if (t->lchild == NULL&&t->rchild == NULL)
			{
				cout << t->data << ends;
			}
			output_leaf(t->lchild);//�ݹ�������  
			output_leaf(t->rchild);//�ݹ�������  
		}
	}

	//���Ҷ�������ֵdata��Ϊelem�Ľڵ�  

	Node * find_node(Node *t, char elem, Node *res = NULL)
	{
		//Node *res = NULL;  
		if (t == NULL)//����ǰ�ڵ�Ϊ�գ��򷵻ؽ���  
		{
			return NULL;
		}
		else
		{
			if (t->data == elem)//���ҵ�ֵ�����ص�ַ  
			{
				//res = t;  
				return t;
			}
			else
			{
				if (res == NULL)//����������ָ�벻Ϊ�գ���ݹ������ڵ�  
				{
					res = find_node(t->lchild, elem, res);
				}
				if (res == NULL)//����������ָ�벻Ϊ�գ�����ڵ�Ϊ����������ݹ�����ҽڵ�  
				{
					res = find_node(t->rchild, elem, res);
				}
			}
			return res;
		}
	}

	//����ڵ���  
	int node_count(Node *t)
	{
		int lcount = 0, rcount = 0;
		if (t == NULL)//���򷵻�  
		{
			return 0;
		}
		else
		{
			if (t->lchild != NULL)//�������ӽڵ�  
			{
				lcount = node_count(t->lchild);
				lcount += 1;
			}
			if (t->rchild != NULL)//�����Һ��ӽڵ�  
			{
				rcount = node_count(t->rchild);
				rcount += 1;
			}
			return lcount + rcount;//���ص�ǰ���Һ��ӽڵ���  
		}
	}
};


int main()
{
	Tree m_tree;
	m_tree.Create("data");
	m_tree.display();//�ݹ��������  
	m_tree.displayMid();//�ݹ��������  
	m_tree.displayBhind();//�ݹ�������  
	m_tree.Height();//����  
	m_tree.display_leaf();//Ҷ�ӽڵ�  
	cout << "�ǵݹ�����:";
	//cout << "Fir:";  
	m_tree.Disp();//�ǵݹ��������  
	cout << endl;
	cout << "�ǵݹ�����:";
	//cout << "Mid:";  
	m_tree.DispMid();//�ǵݹ��������  
	cout << endl;
	cout << "�ǵݹ����:";
	//cout << "Bac:";  
	m_tree.DispBehid();//�ǵݹ�������  
	cout << endl;
	cout << "��α���:";
	m_tree.level_display();//��α���  
	cout << endl;
	cout << "Input element:";
	char elem;
	cin >> elem;
	m_tree.find_node(elem);//���ڵ�ֵ����  
	m_tree.nodes_count();//����ڵ���  
	return 0;
}