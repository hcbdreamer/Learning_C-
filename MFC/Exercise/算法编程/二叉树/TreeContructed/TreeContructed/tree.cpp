#include"tree.h"
#include <exception>
#include <cstdio>

/*BiTreeNode* Tree::CreateTree(string &s,int& pos)
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
}*/

/*void Tree::CreateBiTree(string s)
{
	int pos = -1;
	root=CreateTree(s,pos);
}*/

void Tree::pre_Order(BiTreeNode* temp)
{
	if (temp != nullptr)
	{
		cout << temp->value<<' ';
		pre_Order(temp->Ltree);
		pre_Order(temp->Rtree);
	}
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
		cout << temp->value<< ' ';
		in_Order(temp->Rtree);
	}
}

void Tree::inOrder()
{
	in_Order(root);
	cout << endl;
}

void Tree::post_Order(BiTreeNode* temp)
{
	if (temp != nullptr)
	{
		post_Order(temp->Ltree);
		post_Order(temp->Rtree);
		cout << temp->value << ' ';
	}
}

void Tree::postOrder()
{
	post_Order(root);
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

BiTreeNode* Tree::ConstructNode(int* startPreorder, int*endPreorder, int* startInorder, int* endInorder)
{
	int rootvalue = startPreorder[0];//根节点值
	BiTreeNode* root1 = new BiTreeNode;
	root1->value = rootvalue;
	root1->Ltree = root1->Rtree = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder&&*startPreorder == *endInorder)
			return root1;
		else
			throw std::exception("Invalid input!");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootvalue)
	{
		rootInorder++;
	}
	if (rootInorder == endInorder&&*rootInorder != rootvalue)
	{
		throw std::exception("Invalid input.");
	}
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0){
		root1->Ltree = ConstructNode(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root1->Rtree = ConstructNode(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root1;
}

BiTreeNode* Tree::Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length < 0)
	{
		return nullptr;
	}
	return ConstructNode(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void Tree::Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		root = Construct(preorder, inorder, length);
		cout << "前序序列是： ";
		preOrder();
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Tree::Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Tree::Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Tree::Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Tree::Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Tree::Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Tree::Test6()
{
	Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Tree::Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
}