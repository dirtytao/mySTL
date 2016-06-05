#ifndef _LIST_H_
#define _LIST_H_
//          MyList
#include<iostream>
using namespace std;

template<class T>

class list_node     //����ڵ���
{
public:
	T data;       //����
	list_node<T>* pre;  //ǰָ��
	list_node<T>* next; //��ָ��
};

template<class T>
class list_iter   //list ��������
{
public:
	list_node<T> *node;            //�ڵ�ָ��
	list_iter(list_node<T>* p):node(p){}  //���캯��
	list_iter(){node=new list_node<T>();} //�չ��캯��
	bool operator==(list_iter<T> x){return node==x.node;}  //����==
	bool operator!=(list_iter<T> x){return node!=x.node;}  //���أ�=
	T operator*(){return node->data;}                //����*
	list_iter<T>& operator++();                           //����ǰ++
	list_iter<T> operator++(int);                         //���غ�++
	list_iter<T>& operator--();                           //����ǰ--
	list_iter<T> operator--(int);    //���غ�--
	//T* operator->(){return &(node->data);}//����->
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
class list             //������
{
public:
	list_node<T>* node;   //����ڵ�ָ��
	int len;               //����

	typedef list_iter<T> iterator;
	list();       //���캯��
	~list(){clear();}//��������
	list_iter<T> begin(){return node->next;} //����ͷ
	list_iter<T> end(){return node;} //����β
	T front(){return *begin();} //����ͷ��ֵ
	T back(){return *(--end());}//����β��ֵ
	bool empty(){return len==0;}//�жϿ�
	int size(){return len;}   //����Ԫ�ظ���
	void insert(iterator position,T data);  //����
	void erase(iterator position); //ɾ��
	void push_back(T data);  //����β 
	void push_front(T data);// ����ͷ
	void pop_front();  //ɾ��ͷ
	void pop_back();   //ɾ��β
	void clear();    //�������

};
template<class T>
list<T>::list()
{
	len=0;
	node=new list_node<T>();
	node->next=node;
	node->pre=node;
}
                                                            //����
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
                                                              //ɾ��
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