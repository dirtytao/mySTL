#ifndef _STACK_H_
#define _STACK_H_
#include"list.h"

template <class T>
class stack
{
public:
	list<T> c;

	stack(){//构造函数
	}
	bool empty(){	//判断栈是否为空
		return c.empty();
	}

	int size(){//返回栈的长度
		return c.size();
	}

	T top(){ //返回栈的栈顶元素
		return c.back();
	}

	void push(T x){//元素入栈
		c.push_back(x);
	}

	void pop(){//元素出栈
		c.pop_back();
	}

	void clear(){//清空栈
		c.clear();
	}

	bool operator ==(stack<T> x){//判断2个栈是不是相等
		if(c.size()!=x.c.size())
			return false;
		else{
			list_iter<T> it1;
			list_iter<T> it2;
			it1=c.begin();
			it2=x.c.begin();
			while(it1!=c.end()){
				if(*it1!=*it2)
					break;
				it1++;
				it2++;
			}
			if(it1==c.end())
				return true;
			else
				return false ;
		}
	}

	bool operator !=(stack<T> x){//判断2个栈是不是不相等
		if(c.size()!=x.c.size())
			return true;
		else{
			list_iter<T> it1;
			list_iter<T> it2;
			it1=c.begin();
			it2=x.c.begin();
			while(it1!=c.end()){
				if(*it1!=*it2)
					break;
				it1++;
				it2++;
			}
			if(it1==c.end())
				return false;
			else
				return true ;
		}
	}
};

#endif
