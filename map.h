#ifndef _MAP_H_
#define _MAP_H_
#include"AVLtree.h"
#include"pair.h"

template<class key,class value>
class map
{
public:
	typedef   mypair<key,value> T;
	typedef  typename tree<T>::tree_iterator iterator;
	tree<T> t;
	map():t(){};
	iterator begin(){return t.begin();} //begin
	iterator end(){return t.end();}//end
	bool empty(){return t.empty();}//�п�
	int size(){return t.size();}// size
	void insert(T x){t.inst(x);} //����
	void erase(key x){t.dlet(T(x,value()));}// ɾ��
	iterator find(key x){return t.find(T(x,value()));} //����
	iterator lower_bound(key x){return t.upper(T(x,value()));}; //����>=x��Ԫ��
	void clear(){t.clear();}//���
};
#endif