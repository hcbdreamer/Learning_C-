
struct BiTreeNode
{
	int m_nvalue;
	BiTreeNode* m_pLeft;
	BiTreeNode* m_pRight;
	BiTreeNode* m_pParent;
};


BiTreeNode* GetNext(BiTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}
	BiTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BiTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BiTreeNode* pCurrent = pNode;
		BiTreeNode* pParent=pNode->m_pParent;
		while (pParent != nullptr&&pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;

}
