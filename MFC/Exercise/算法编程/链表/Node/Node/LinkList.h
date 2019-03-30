/*class node{
public:
	int value;
	node* next;
	node()
	{
		value = 0;
		next = nullptr;//nullptr «ø’÷∏’Î
	}
};*/

struct node
{
	int value;
	node* next;
};
class LinkList{
private:
	node* head;
	int length;
public:
	LinkList();
	~LinkList();
	void insert(int val, int pos);
	void print();
	void Remove(int val);
	void Reverse();
	int Find(int val);
	int Length();
};

