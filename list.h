#ifndef _LIST_H_
#define _LIST_H_
//          MyList
#include<iostream>
using namespace std;

template<class T>

class list_node     //链表节点类
{
public:
	T data;       //数据
	list_node<T>* pre;  //前指针
	list_node<T>* next; //后指针
};

template<class T>
class list_iter   //list 迭代器类
{
public:
	list_node<T> *node;            //节点指针
	list_iter(list_node<T>* p):node(p){}  //构造函数
	list_iter(){node=new list_node<T>();} //空构造函数
	bool operator==(list_iter<T> x){return node==x.node;}  //重载==
	bool operator!=(list_iter<T> x){return node!=x.node;}  //重载！=
	T operator*(){return node->data;}                //重载*
	list_iter<T>& operator++();                           //重载前++
	list_iter<T> operator++(int);                         //重载后++
	list_iter<T>& operator--();                           //重载前--
	list_iter<T> operator--(int);    //重载后--
	//T* operator->(){return &(node->data);}//重载->
};
template<class T>
list_iter<T>& list_iter<T>::operator++()
{
	node=node->next;
	return *this;
}
template<class T>
list_iter<T>& list_iter<T>::operator--()
{
	node=node->pre;
	return *this;
}
template<class T>
list_iter<T> list_iter<T>::operator++(int)
{
	list_iter<T> old=*this;
	++(*this);
	return old;
}
template<class T>
list_iter<T> list_iter<T>::operator--(int)
{
	list_iter<T> old=*this;
	--(*this);
	return old;
}


template<class T>
class list             //链表类
{
public:
	list_node<T>* node;   //链表节点指针
	int len;               //长度

	typedef list_iter<T> iterator;
	list();       //构造函数
	~list(){clear();}//析构函数
	list_iter<T> begin(){return node->next;} //链表头
	list_iter<T> end(){return node;} //链表尾
	T front(){return *begin();} //链表头的值
	T back(){return *(--end());}//链表尾的值
	bool empty(){return len==0;}//判断空
	int size(){return len;}   //返回元素个数
	void insert(iterator position,T data);  //插入
	void erase(iterator position); //删除
	void push_back(T data);  //插入尾 
	void push_front(T data);// 插入头
	void pop_front();  //删除头
	void pop_back();   //删除尾
	void clear();    //清空链表

};
template<class T>
list<T>::list()
{
	len=0;
	node=new list_node<T>();
	node->next=node;
	node->pre=node;
}
                                                            //插入
template<class T>
void list<T>::insert(iterator position,T data)
{
	list_node<T>* temp=new list_node<T>();
	temp->data=data;
	temp->next=position.node;
	temp->pre=position.node->pre;
	(position.node->pre)->next=temp;
	position.node->pre=temp;
	len++;
}
                                                              //删除
template<class T>
void list<T>::erase(iterator position)
{
	list_node<T>* next_node=position.node->next;
	list_node<T>* pre_node=position.node->pre;
	pre_node->next=next_node;
	next_node->pre=pre_node;
	len--;
	delete position.node;
}
template<class T>
void list<T>::pop_front()
{
	erase(begin());
}
template<class T>
void list<T>::pop_back()
{
	list_iter<T> temp=end();
	erase(--temp);
}
template<class T>
void list<T>::push_front(T data)
{
	insert(begin(),data);
}
template<class T>
void list<T>::push_back(T data)
{
	insert(end(),data);
}
template<class T>
void list<T>::clear()
{
	list_node<T>* cur=node->next;
	while(cur!=node)
	{
		list_node<T>* temp=cur;
		cur=cur->next;
		delete temp;
	}
	node->next=node;
	node->pre=node;
	len=0;
}

#endif