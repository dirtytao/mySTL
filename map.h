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
	bool empty(){return t.empty();}//判空
	int size(){return t.size();}// size
	void insert(T x){t.inst(x);} //插入
	void erase(key x){t.dlet(T(x,value()));}// 删除
	iterator find(key x){return t.find(T(x,value()));} //查找
	iterator lower_bound(key x){return t.upper(T(x,value()));}; //查找>=x的元素
	void clear(){t.clear();}//清空
};
#endif