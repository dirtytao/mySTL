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
	set():t(){}   //构造函数
	iterator begin(){return t.begin();} //begin
	iterator end(){return t.end();}//end
	bool empty(){return t.empty();}//判空
	int size(){return t.size();}// size
	void insert(T x){t.inst(x);} //插入
	void erase(T x){t.dlet(x);}// 删除
	iterator find(T x){return t.find(x);} //查找
	iterator lower_bound(T x){return t.upper(x);}; //查找>=x的元素
	void clear(){t.clear();}//清空
	//iterator lower(T x){return t.lower(x);}//查找<=x的元素
};

#endif