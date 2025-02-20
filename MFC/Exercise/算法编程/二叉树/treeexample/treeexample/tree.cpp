/*
二叉树实现
1.创建二叉树
2.递归输出二叉树
2.1递归先序输出
2.2递归中序输出
2.3递归后序输出
3.非递归输出
3.1非递归先序输出
3.2非递归中序输出
3.3非递归后序输出
4.层次遍历二叉树
5.求树高
6.求树叶子节点
7.按值查找对应节点，输出左孩子结点值和右孩子结点值
8.计算所有节点数
*/
#include<iostream>  
#include<string>  
#include<stack>  
#include<deque>  
#include<fstream>  
using namespace std;

//const int MAX_N = 100;  
//数据节点  
class Node
{
public:
	char data;//数据  
	class Node *lchild;//左节点  
	class Node *rchild;//右节点  
};

//二叉树  
class Tree
{
public:
	Tree(){}
	~Tree(){}

	//构建二叉树  
	void Create(string name)
	{
		ifstream readfile;
		string str;
		readfile.open(name);
		if (readfile.is_open())
		{
			getline(readfile, str);//读取一行  
		}
		readfile.close();
		CreateNode(str);//构建二叉树  
	}


	//先序遍历非递归算法  
	void Disp()
	{
		if (t == NULL)
		{
			return;
		}
		stack<Node *> m_stack;//定义栈  
		m_stack.push(t);
		while (!m_stack.empty())
		{
			Node *p = m_stack.top();//赋值一份当前双亲节点  
			cout << p->data << ends;
			m_stack.pop();
			if (p->rchild)//先存储右子树，确保先输出左子树  
			{
				m_stack.push(p->rchild);
			}
			if (p->lchild)//后存储左子树  
			{
				m_stack.push(p->lchild);
			}
		}

	}

	//非递归中序遍历二叉树  
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
			while (p != NULL)//一路直走至左下角  
			{
				m_stack.push(p);
				p = p->lchild;
			}
			if (!m_stack.empty())
			{
				p = m_stack.top();//备份当前栈顶地址  
				m_stack.pop();
				cout << p->data << ends;
				p = p->rchild;
			}
		}
	}

	//非递归后序遍历二叉树  
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
			while (p != NULL)//一路直走至左下角  
			{
				m_stack.push(p);
				p = p->lchild;
			}
			p = m_stack.top();
			//右子树为空或者已访问，输出当前节点  
			if (p->rchild == NULL || p->rchild == pre)
			{
				cout << p->data << ends;
				pre = p;//将当前结点地址赋值pre作为下一次判断标志，防止重复访问  
				m_stack.pop();
				p = NULL;//p赋值空以便访问右子树  
			}
			else
			{
				p = p->rchild;//访问子树的右子树  
			}
		}
	}

	//层次遍历  
	void level_display()
	{
		if (t == NULL)
		{
			return;
		}
		deque<Node *>m_qu;//定义队列  
		m_qu.push_back(t);//树根入队列  
		while (!m_qu.empty())
		{
			Node *p = m_qu.front();//拷贝当前对头  
			cout << p->data << ends;//输出  
			m_qu.pop_front();
			if (p->lchild)//左孩子入队列  
			{
				m_qu.push_back(p->lchild);
			}
			if (p->rchild)//右孩子入队列  
			{
				m_qu.push_back(p->rchild);
			}
		}
	}

	//递归先序遍历输出二叉树  
	void display()
	{
		cout << "递归先序：";
		output(t);
		cout << endl;
	}

	//递归中序遍历输出二叉树  
	void displayMid()
	{
		cout << "递归中序:";
		outputMid(t);
		cout << endl;
	}

	//递归后序遍历输出二叉树  
	void displayBhind()
	{
		cout << "递归后序";
		outputBhind(t);
		cout << endl;
	}
	//二叉树高度  
	void Height()
	{
		int height = get_height(t);
		cout << "Height: " << height << endl;
	}

	//输出叶子节点值  
	void display_leaf()
	{
		cout << "Leaves: ";
		output_leaf(t);
		cout << endl;
	}

	//查找二叉树中值data域为elem的节点  
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

	//计算节点数  
	void nodes_count()
	{
		int sum;
		if (t == NULL)//若为空，则0个节点  
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

	//构建二叉树  
	void CreateNode(string str)
	{
		stack<Node *> m_stack;
		Node *p;
		int k;
		while (str.length() != 0)
		{
			//若当前为'('，将双亲节点推入栈，下一位存储的p值作为左节点处理  
			if (str[0] == '(')
			{
				m_stack.push(p); k = 1;
			}
			//为右括号则栈顶退出一位  
			else if (str[0] == ')')
			{
				m_stack.pop();
			}
			//为','，则下一个字符作右节点处理  
			else if (str[0] == ',')
			{
				k = 2;
			}
			//存储值用作双亲结点  
			else
			{
				p = (Node *)malloc(sizeof(Node));
				p->data = str[0];
				p->lchild = p->rchild = NULL;
				//树根为空时，将第一个节点作为树根并赋值给私有成员变量  
				if (t == NULL)
				{
					t = p;
				}
				//树根不为空  
				else
				{
					if (k == 1)//作为左节点处理，将栈中双亲节点的左指针指向当前节点  
					{
						m_stack.top()->lchild = p;
					}
					else//作为右节点处理  
					{
						m_stack.top()->rchild = p;
					}
				}
			}
			//重构串，除去首字符，并将串长度减小1  
			str.assign(str.substr(1, str.length() - 1));
		}
	}

	//递归先序遍历输出二叉树  
	void output(Node *t)
	{
		if (t != NULL)//当树根不为空时  
		{
			cout << t->data;//输出  
			if (t->lchild != NULL || t->rchild != NULL)//左/右结点不为空时递归到下一层  
			{
				cout << "(";
				output(t->lchild);
				if (t->rchild != NULL)//当左节点遍历结束后，左节点递归返回一层，递归右节点  
				{
					cout << ",";
				}
				output(t->rchild);
				cout << ")";
			}
		}
	}

	//递归中序遍历二叉树  
	void outputMid(Node *t)
	{
		if (t == NULL)//空则返回  
		{
			return;
		}
		else
		{
			cout << "(";
			outputMid(t->lchild);//递归左孩子节点  
			if (t->rchild != NULL)
			{
				cout << ",";
			}
			cout << t->data;//输出  
			outputMid(t->rchild);//递归右孩子结点  
			cout << ")";
		}
	}

	//递归后序遍历输出二叉树  
	void outputBhind(Node *t)
	{
		if (!t)//空则返回  
		{
			return;
		}
		else
		{
			cout << "(";
			outputBhind(t->lchild);//递归左孩子节点  
			if (t->rchild != NULL)
			{
				cout << ",";
			}
			outputBhind(t->rchild);//递归右孩子结点  
			cout << t->data;//输出  
			cout << ")";
		}
	}
	//求树高  
	int get_height(Node *t)
	{
		int leftheight, rightheight;
		if (t == NULL)//递归至不存在子节点时返回0  
		{
			return 0;
		}
		else
		{
			leftheight = get_height(t->lchild);//递归求左子树高度  
			rightheight = get_height(t->rchild);//递归其右子树高度  
			return leftheight > rightheight ? leftheight + 1 : rightheight + 1;//递归返回时返回最大值  
		}
	}

	//查找左节点  
	Node *leftchild(Node *p)
	{
		return p->lchild;
	}

	//查找右节点  
	Node *rightchild(Node *p)
	{
		return p->rchild;
	}

	//输出叶子节点  
	void output_leaf(Node *t)
	{
		if (t != NULL)//树根不为空时  
		{
			//当前节点没有子节点时输出节点数据  
			if (t->lchild == NULL&&t->rchild == NULL)
			{
				cout << t->data << ends;
			}
			output_leaf(t->lchild);//递归左子树  
			output_leaf(t->rchild);//递归右子树  
		}
	}

	//查找二叉树中值data域为elem的节点  

	Node * find_node(Node *t, char elem, Node *res = NULL)
	{
		//Node *res = NULL;  
		if (t == NULL)//若当前节点为空，则返回结束  
		{
			return NULL;
		}
		else
		{
			if (t->data == elem)//若找到值，返回地址  
			{
				//res = t;  
				return t;
			}
			else
			{
				if (res == NULL)//若保存结果的指针不为空，则递归查找左节点  
				{
					res = find_node(t->lchild, elem, res);
				}
				if (res == NULL)//若保存结果的指针不为空，且左节点为搜索到，则递归查找右节点  
				{
					res = find_node(t->rchild, elem, res);
				}
			}
			return res;
		}
	}

	//计算节点数  
	int node_count(Node *t)
	{
		int lcount = 0, rcount = 0;
		if (t == NULL)//空则返回  
		{
			return 0;
		}
		else
		{
			if (t->lchild != NULL)//遍历左孩子节点  
			{
				lcount = node_count(t->lchild);
				lcount += 1;
			}
			if (t->rchild != NULL)//遍历右孩子节点  
			{
				rcount = node_count(t->rchild);
				rcount += 1;
			}
			return lcount + rcount;//返回当前左右孩子节点数  
		}
	}
};


int main()
{
	Tree m_tree;
	m_tree.Create("data");
	m_tree.display();//递归先序输出  
	m_tree.displayMid();//递归中序输出  
	m_tree.displayBhind();//递归后序输出  
	m_tree.Height();//树高  
	m_tree.display_leaf();//叶子节点  
	cout << "非递归先序:";
	//cout << "Fir:";  
	m_tree.Disp();//非递归先序遍历  
	cout << endl;
	cout << "非递归中序:";
	//cout << "Mid:";  
	m_tree.DispMid();//非递归中序遍历  
	cout << endl;
	cout << "非递归后序:";
	//cout << "Bac:";  
	m_tree.DispBehid();//非递归后序遍历  
	cout << endl;
	cout << "层次遍历:";
	m_tree.level_display();//层次遍历  
	cout << endl;
	cout << "Input element:";
	char elem;
	cin >> elem;
	m_tree.find_node(elem);//按节点值查找  
	m_tree.nodes_count();//计算节点数  
	return 0;
}