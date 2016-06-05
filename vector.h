#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<iostream>
using namespace std;

template <class T>//������
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
	iterator start;//Ŀǰʹ�õ�ͷ
	iterator finish;//Ŀǰʹ�õ�β
	iterator end_of_storage;//Ŀǰ���ÿռ��β
	int MAXSIZE;

	vector(){//���캯��
		start=new T[100];
		finish=start;
		end_of_storage=start+100;
		MAXSIZE=100;
	}

	~vector(){//��������
		delete [] start;
	}

	T* begin(){//���ص�һ��Ԫ��ָ��
		return start;
	}

	T* end(){//�������һ��Ԫ��ָ��
		return finish;
	}

	T& operator [](size_t n){//����[]
		return *(begin()+n);
	}

	void insert(iterator position,T& x){//����λ�ò���
		if(finish+1!=end_of_storage){//�ռ��㹻
			iterator Move=finish;
			while (Move!=position){
				*Move=*(Move--);
			}
			*Move=x;
			++finish;
		}
		else{//�ռ� ����
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

	bool empty(){//�ж��Ƿ�Ϊ��
		return begin()==end();
	}

	size_t size(){//����Ԫ�ظ���
		return size_t(end()-begin());
	}

	size_t capacity(){//����vector�ռ��С
		return size_t(end_of_storage()-begin());
	}

	T& front(){//���ص�һ��Ԫ��
		return *begin();
	}

	T& back(){//�������һ��Ԫ��
		return *(end()-1);
	}

	void push_back(T x){//�������Ԫ��
		insert(finish,x);
	}

	void pop_back(){//pop����Ԫ��
		finish--;
	}

	void clear(){//���Ԫ��
		finish=start;
	}

	void arease(iterator position){//ɾ������λ��Ԫ��
		while(position!=finish-1){
			*position=*(position+1);
			position++;
		}
		finish--;
	}
};

#endif