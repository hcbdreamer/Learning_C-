#include<stack>
using namespace std;

template<typename T>class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	//在队列尾部插入节点
	void appendTail(const T& node);
	//在队列头部删除节点
	T deleteHead();

private:
	stack<T>stack1;
	stack<T>stack2;

};

template<typename T>CQueue<T>:: CQueue(void)
{
}
template<typename T>CQueue<T>::~CQueue(void)
{
}

template<typename T>void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size()<=0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}
	T head = stack2.top();
	stack2.pop();

	return head;
}