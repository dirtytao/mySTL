#ifndef __DEQUE__
#define __DEQUE__

#include <cstdio>

template<class T,size_t BuffSize>
struct __Deque_Iterator__
{
public:
	//嵌套型别定义
	typedef T Value_Type;
	typedef Value_Type * Pointer;
	typedef Value_Type & Reference;
	typedef size_t Size_Type;
	typedef ptrdiff_t Difference_Type;
	typedef Pointer * Map_Pointer;
public:
	T * cur;
	T * first;
	T * last;
	Map_Pointer node;
public:
	void set_node(Map_Pointer newnode)
	{
		node=newnode;
		first=*newnode;
		last=*newnode+ptrdiff_t(BuffSize);
	}
	Reference operator * ()const {return *cur;}
	Pointer operator & ()const {return cur;}
	Pointer operator -> ()const {return &(operator*());}
	bool operator != (__Deque_Iterator__<T,BuffSize> iter){return !(*this==iter);}
	bool operator == (__Deque_Iterator__<T,BuffSize> iter){return first==iter.first&&last==iter.last&&cur==iter.cur;}
	__Deque_Iterator__<T,BuffSize> &operator ++ ()
	{
		++cur;
		if (cur==last)
		{
			set_node(node+1);
			cur=first;
		}
		return *this;
	}
	__Deque_Iterator__<T,BuffSize> operator ++ (int)
	{
		__Deque_Iterator__<T,BuffSize> ret(*this);
		++(*this);
		return ret;
	}
	__Deque_Iterator__<T,BuffSize> &operator -- ()
	{
		if (cur==first)
		{
			set_node(node-1);
			cur=last;
		}
		--cur;
		return *this;
	}
	__Deque_Iterator__<T,BuffSize> operator -- (int)
	{
		__Deque_Iterator__<T,BuffSize> ret(*this);
		--(*this);
		return ret;
	}
	__Deque_Iterator__<T,BuffSize> operator + (const int n)
	{
		__Deque_Iterator__<T,BuffSize> ret(*this);
		for (int i=0;i<n;i++)
			++ret;
	}
	__Deque_Iterator__<T,BuffSize> operator - (const int n)
	{
	__Deque_Iterator__<T,BuffSize> ret(*this);
		for (int i=0;i<n;i++)
			--ret;
	}
};

template <class T,size_t BuffSize=50,size_t InitMapSize=100>	//缓冲区大小为BuffSize*sizeof(T)
class Deque
{
public:
	//嵌套型别定义
	typedef T Value_Type;
	typedef __Deque_Iterator__<T,BuffSize> Iterator;
	typedef Value_Type * Pointer;
	typedef Value_Type & Reference;
	typedef size_t Size_Type;
	typedef ptrdiff_t Difference_Type;
protected:
	typedef Pointer * Map_Pointer;
private:
	Map_Pointer Map_Ptr;
	Size_Type Map_Size;
	Iterator start,finish;
	void expand();
public:
	Deque();
	~Deque();

	Iterator front(){return start;};
	Iterator back(){return finish;};
	void push_front(T x);
	void pop_front();
	void push_back(T x);
	void pop_back();
	Size_Type size();
	bool empty();
	T & operator [](const int index);
};

template<class T,size_t BuffSize,size_t InitMapSize>
void Deque<T,BuffSize,InitMapSize>::expand()
{
	Map_Pointer newptr=new Pointer[3*Map_Size];
	for (int i=0;i<Map_Size;i++)
		*(newptr + i )= new Value_Type[BuffSize];
	for (int i=BuffSize;i<2*BuffSize;i++)
	{
		*(newptr+i)=*(Map_Ptr+i);
		if (start.node==(Map_Ptr+i))
		{
			start.node=(newptr+i);
		}
		if (finish.node==(Map_Ptr+i))
		{
			finish.node=(newptr+i);
		}
	}
	for (int i=2*BuffSize;i<3*Map_Size;i++)
		*(newptr + i )= new Value_Type[BuffSize];
	delete []Map_Ptr;
	Map_Ptr=newptr;
	Map_Size=3*Map_Size;
}

template<class T,size_t BuffSize,size_t InitMapSize>
Deque<T,BuffSize,InitMapSize>::Deque()
{
	Map_Size=InitMapSize;
	Map_Ptr=new Pointer[Map_Size];
	for (int i=0;i<Map_Size;i++)
	{
		*(Map_Ptr + i )= new Value_Type[BuffSize];
	}
	start.set_node(Map_Ptr+Map_Size/2);
	start.cur=start.first;
	finish.set_node(Map_Ptr+Map_Size/2);
	finish.cur=start.first;
}

template<class T,size_t BuffSize,size_t InitMapSize>
Deque<T,BuffSize,InitMapSize>::~Deque()
{
	for (int i=0;i<Map_Size;i++)
	{
		delete []*(Map_Ptr+i);
	}
	delete []Map_Ptr;
}

template<class T,size_t BuffSize,size_t InitMapSize>
void Deque<T,BuffSize,InitMapSize>::push_front(T x)
{
	if (start.node==Map_Ptr&&start.cur==start.first)
		expand();
	start--;
	*(start.cur)=x;
}

template<class T,size_t BuffSize,size_t InitMapSize>
void Deque<T,BuffSize,InitMapSize>::pop_front()
{
	if (!empty())
		start++;
}

template<class T,size_t BuffSize,size_t InitMapSize>
void Deque<T,BuffSize,InitMapSize>::push_back(T x)
{
	if (finish.node==(Map_Ptr+Map_Size-1)&&finish.cur==finish.last-1)
		expand();
	*(finish.cur)=x;
	finish++;
}

template<class T,size_t BuffSize,size_t InitMapSize>
void Deque<T,BuffSize,InitMapSize>::pop_back()
{
	if (!empty())
		finish--;
}

template<class T,size_t BuffSize,size_t InitMapSize>
typename Deque<T,BuffSize,InitMapSize>::Size_Type Deque<T,BuffSize,InitMapSize>::size()
{
	if (finish.node!=start.node)
		return Size_Type((start.last-start.cur)+(finish.cur-finish.first)+BuffSize*(finish.node-start.node-1));
	else 
		return Size_Type(finish.cur-start.cur);
}

template<class T,size_t BuffSize,size_t InitMapSize>
T & Deque<T,BuffSize,InitMapSize>::operator [](const int index)
{
	Iterator iter;
	iter.set_node(start.node);
	iter.cur=start.cur;
	for (int i=0;i<index;i++)
		iter++;
	return *(iter.cur);
}

template<class T,size_t BuffSize,size_t InitMapSize>
bool Deque<T,BuffSize,InitMapSize>::empty()
{
	if (start.cur!=finish.cur)
		return false ;
	else 
		return true ;
}

#endif