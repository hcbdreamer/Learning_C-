#include"tree.h"
#include<stack>



BiTreeNode* Tree::CreateTree(string &s,int& pos)
{
	++pos;
	BiTreeNode* temp;
	if ((unsigned)pos > s.size())
	{
		return nullptr;
	}
	else
	{
		if (s[pos] == '#')
		{
			temp = nullptr;
		}
		else
		{
			temp = new BiTreeNode;
			temp->data = s[pos];
			temp->Ltree = CreateTree(s, pos);
			temp->Rtree = CreateTree(s, pos);
		}
	}
	return temp;
}

void Tree::CreateBiTree(string s)
{
	int pos = -1;
	root=CreateTree(s,pos);
}

void Tree::pre_Order(BiTreeNode* temp)
{
	if (temp != nullptr)
	{
		cout << temp->data<<' ';
		pre_Order(temp->Ltree);
		pre_Order(temp->Rtree);
	}
}

void Tree::pre_Order2(BiTreeNode* temp)
{
	if (temp == nullptr)
	{
		cout << "Empty!" << endl;
	}
	stack<BiTreeNode*>my_stack;
	while (temp || !my_stack.empty())
	{
		while (temp)
		{
			cout << temp->data<< ' ';
			my_stack.push(temp);
			temp = temp->Ltree;
		}
		temp = my_stack.top();
		my_stack.pop();
		temp = temp->Rtree;
	}

}

void Tree::preOrder2()
{
	pre_Order2(root);
	cout << endl;
}
void Tree::preOrder()
{
	pre_Order(root);
	cout << endl;
}

void Tree::in_Order(BiTreeNode* temp)
{
	if (temp != nullptr)
	{
		in_Order(temp->Ltree);
		cout << temp->data << ' ';
		in_Order(temp->Rtree);
	}
}
void Tree::in_Order2(BiTreeNode* temp)
{
	if (temp == nullptr)
	{
		cout << "Empty!" << endl;
	}
	stack<BiTreeNode*>my_stack;
	while (temp || !my_stack.empty())
	{
		while (temp)
		{
			my_stack.push(temp);
			temp = temp->Ltree;
		}
		temp = my_stack.top();
		my_stack.pop();
		cout << temp->data << ' ';
		temp = temp->Rtree;
	}
}

void Tree::inOrder()
{
	in_Order(root);
	cout << endl;
}

void Tree::inOrder2()
{
	in_Order2(root);
	cout << endl;
}

void Tree::post_Order(BiTreeNode* temp)
{
	if (temp != nullptr)
	{
		post_Order(temp->Ltree);
		post_Order(temp->Rtree);
		cout << temp->data << ' ';
	}
}

void Tree::postOrder()
{
	post_Order(root);
	cout << endl;
}

void Tree::post_Order2(BiTreeNode* temp)
{
	if (temp == nullptr)
	{
		cout << "Empty!" << endl;
	}
	BiTreeNode* r=nullptr;//临时节点
	stack<BiTreeNode*>my_stack;
	while (temp||!my_stack.empty())
	{
		//遍历左树
		if (temp)
		{
			my_stack.push(temp);
			temp = temp->Ltree;
		}
		else
		{
			temp = my_stack.top();
			if (temp->Rtree != nullptr&&temp->Rtree != r)
			{
				//如果右子树没有遍历，遍历右子树
				temp = temp->Rtree;
				my_stack.push(temp);
				///注意这里需要向左转，因为如果不向左转，
				///将会遍历右子树节点两边
				temp = temp->Ltree;
			}
			else
			{
				///否则遍历根节点
				temp = my_stack.top();
				my_stack.pop();
				cout << temp->data << ' ';
				//更新最新遍历的节点
				r = temp;
				//将遍历后的节点设为null,进行下一个节点的遍历
				temp = nullptr;
			}
		}
	}
}
void Tree::postOrder2()
{
	post_Order2(root);
	cout << endl;
}
//寻找树高度
void Tree::get_Height(BiTreeNode* temp, int h)
{
	++h;
	if (temp != nullptr)
	{
		if (h > height)
		{
			height = h;
			get_Height(temp->Ltree,h);
			get_Height(temp->Rtree,h);
		}
	}
}

int Tree::getHeight()
{
    get_Height(root, height);
	return height;
}

