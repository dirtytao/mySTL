#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"list.h"

template <class T>
class queue
{
public:
	list<T> c;
	queue(){//构造函数
	}

	bool empty(){//判断是否为空
		return c.empty();
	}

	int size(){//返回队列元素个数
		return c.size();
	}

	void push(T x){//元素入队列
		c.push_back(x);
	}

	void pop(){//元素出队列
		c.pop_front();
	}

	T top(){//返回队头元素
		return c.front();
	}

	void clear(){//清空队列
		c.clear();
	}

	bool operator ==(queue<T> x){//判断2个队列是不是相等
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
				return false;
		}

	}

	bool operator !=(queue<T> x){//判断2个函数是不是不相等
		if(c.size()!=x.c.size())
			return true;;
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
				return true;
		}
	}
};
#endif
