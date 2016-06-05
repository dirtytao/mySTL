#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<iostream>
using namespace std;

template <class T>//迭代器
class vector_iterator
{
public:
	typedef T* iterator; 

};
template <class T>
class vector
{
public:
	typedef T* iterator;
	iterator start;//目前使用的头
	iterator finish;//目前使用的尾
	iterator end_of_storage;//目前可用空间的尾
	int MAXSIZE;

	vector(){//构造函数
		start=new T[100];
		finish=start;
		end_of_storage=start+100;
		MAXSIZE=100;
	}

	~vector(){//析构函数
		delete [] start;
	}

	T* begin(){//返回第一个元素指针
		return start;
	}

	T* end(){//返回最后一个元素指针
		return finish;
	}

	T& operator [](size_t n){//重载[]
		return *(begin()+n);
	}

	void insert(iterator position,T& x){//任意位置插入
		if(finish+1!=end_of_storage){//空间足够
			iterator Move=finish;
			while (Move!=position){
				*Move=*(Move--);
			}
			*Move=x;
			++finish;
		}
		else{//空间 不够
			int i;
			iterator old=start;
			start=new T[MAXSIZE*2];
			for(i=0;i<MAXSIZE;i++)
				*(start+i)=*(old+i);
			finish=start+MAXSIZE;
			MAXSIZE=MAXSIZE*2;
			end_of_storage=start+MAXSIZE;
			delete [] old;
			iterator Move=finish;
			while (Move!=position){
				*Move=*(Move--);
			}
			*Move=x;
			++finish;
		}
	}

	bool empty(){//判断是否为空
		return begin()==end();
	}

	size_t size(){//返回元素个数
		return size_t(end()-begin());
	}

	size_t capacity(){//返回vector空间大小
		return size_t(end_of_storage()-begin());
	}

	T& front(){//返回第一个元素
		return *begin();
	}

	T& back(){//返回最后一个元素
		return *(end()-1);
	}

	void push_back(T x){//往后添加元素
		insert(finish,x);
	}

	void pop_back(){//pop最后的元素
		finish--;
	}

	void clear(){//清空元素
		finish=start;
	}

	void arease(iterator position){//删除任意位置元素
		while(position!=finish-1){
			*position=*(position+1);
			position++;
		}
		finish--;
	}
};

#endif