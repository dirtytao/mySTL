#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"list.h"

template <class T>
class queue
{
public:
	list<T> c;
	queue(){//���캯��
	}

	bool empty(){//�ж��Ƿ�Ϊ��
		return c.empty();
	}

	int size(){//���ض���Ԫ�ظ���
		return c.size();
	}

	void push(T x){//Ԫ�������
		c.push_back(x);
	}

	void pop(){//Ԫ�س�����
		c.pop_front();
	}

	T top(){//���ض�ͷԪ��
		return c.front();
	}

	void clear(){//��ն���
		c.clear();
	}

	bool operator ==(queue<T> x){//�ж�2�������ǲ������
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

	bool operator !=(queue<T> x){//�ж�2�������ǲ��ǲ����
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
