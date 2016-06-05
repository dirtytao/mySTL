#ifndef _STACK_H_
#define _STACK_H_
#include"list.h"

template <class T>
class stack
{
public:
	list<T> c;

	stack(){//���캯��
	}
	bool empty(){	//�ж�ջ�Ƿ�Ϊ��
		return c.empty();
	}

	int size(){//����ջ�ĳ���
		return c.size();
	}

	T top(){ //����ջ��ջ��Ԫ��
		return c.back();
	}

	void push(T x){//Ԫ����ջ
		c.push_back(x);
	}

	void pop(){//Ԫ�س�ջ
		c.pop_back();
	}

	void clear(){//���ջ
		c.clear();
	}

	bool operator ==(stack<T> x){//�ж�2��ջ�ǲ������
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

	bool operator !=(stack<T> x){//�ж�2��ջ�ǲ��ǲ����
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
