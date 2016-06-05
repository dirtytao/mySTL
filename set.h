#ifndef _SET_H_
#define _SET_H_

#include"AVLtree.h"
                          //myset
template<class T>
class set
{
public:
	typedef  typename tree<T>::tree_iterator iterator;
	tree<T> t;         
	set():t(){}   //���캯��
	iterator begin(){return t.begin();} //begin
	iterator end(){return t.end();}//end
	bool empty(){return t.empty();}//�п�
	int size(){return t.size();}// size
	void insert(T x){t.inst(x);} //����
	void erase(T x){t.dlet(x);}// ɾ��
	iterator find(T x){return t.find(x);} //����
	iterator lower_bound(T x){return t.upper(x);}; //����>=x��Ԫ��
	void clear(){t.clear();}//���
	//iterator lower(T x){return t.lower(x);}//����<=x��Ԫ��
};

#endif