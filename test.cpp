#include "list.h"
#include "algorithm.h"
#include "AVLtree.h"
#include "map.h"
#include "queue.h"
#include "set.h"
#include "stack.h"
#include "vector.h"
#include "deque.h"
#include <string>
#include <iostream>
using namespace std;

void list_test() //list测试
{
	list<int> mylist;
	list<int>::iterator  it;//list迭代器
	cout<<"insert     插入list头：2"<<endl;
	mylist.insert(mylist.begin(),2);//insert插入list头
	cout<<"insert     插入list尾：3"<<endl;
	mylist.insert(mylist.end(),3);//insert插入list尾
	cout<<"push_back  插入list尾：1"<<endl;
	mylist.push_back(1);
	cout<<"push_back  插入list尾：10"<<endl;
	mylist.push_back(10);
	cout<<"push_back  插入list尾：55"<<endl;
	mylist.push_back(55);
	cout<<"push_front 插入list头：15"<<endl;
	mylist.push_front(15);
	cout<<"push_front 插入list头：7"<<endl;
	mylist.push_front(7);
	cout<<"push_front 插入list头：8"<<endl;
	mylist.push_front(8);
	cout<<"输出链表：";
	for(it=mylist.begin();it!=mylist.end();++it)//list遍历
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"list长度：";
	cout<<mylist.size()<<endl;//输出list的长度
	cout<<"输出list头：";
	cout<<mylist.front()<<endl;//输出list头
	cout<<"输出list尾：";
	cout<<mylist.back()<<endl;//输出list尾
	cout<<"pop_back   删除list尾 "<<endl;
	mylist.pop_back();//删除list尾
	cout<<"pop_back   删除list头 "<<endl;
	mylist.pop_front();//删除list头
	cout<<"erase      删除list头 "<<endl;
	mylist.erase(mylist.begin());//用erase删除list头
	cout<<"list长度：";
	cout<<mylist.size()<<endl;//输出list的长度
	cout<<"输出链表：";
	for(it=mylist.begin();it!=mylist.end();++it)//list遍历
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"清空链表"<<endl;
	mylist.clear(); //清空list
}
void stack_test()//stack测试
{
	stack<int> st;
	stack<int> st1;
	cout<<"1 入栈"<<endl;
	cout<<"2 入栈"<<endl;
	cout<<"3 入栈"<<endl;
	cout<<"4 入栈"<<endl;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<"栈的长度:";
	cout<<st.size()<<endl;
	cout<<"从栈顶开始输出栈："<<endl;
	while(!st.empty())//判空
	{
		cout<<st.top()<<" 出栈"<<endl;//输出栈顶
		st1.push(st.top());
		st.pop();              //出栈;
	}
	cout<<"栈的长度:";
	cout<<st.size()<<endl;
	if(st==st1)
		cout<<"栈和栈2相等"<<endl;
	else
		cout<<"栈和栈2不相等"<<endl;
	cout<<"判断栈是否为空：";
	if(st.empty())
		cout<<"栈为空！"<<endl;
	else
		cout<<"栈不为空!"<<endl;
	cout<<"清空栈";
	st.clear();
	st1.clear();
	cout<<endl;

}
void queue_test()//queue测试
{
	queue<int> qu;
	queue<int> qu1;
	cout<<"1 入队列"<<endl;
	cout<<"2 入队列"<<endl;
	cout<<"3 入队列"<<endl;
	cout<<"4 入队列"<<endl;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	cout<<"队列的长度："<<qu.size()<<endl;
	cout<<"从队头输出队列："<<endl;
	while(!qu.empty())
	{
		cout<<qu.top()<<" 出队列"<<endl;
		qu1.push(qu.top());
		qu.pop();
	}
	if(qu==qu1)
		cout<<"队列和队列1相等"<<endl;
	else
		cout<<"队列和队列1不相等"<<endl;
	cout<<"队列的长度："<<qu.size()<<endl;
	cout<<"判断队列是否为空：";
	if(qu.empty())
		cout<<"队列为空！"<<endl;
	else
		cout<<"队列不为空!"<<endl;
	cout<<"清空队列";
	qu.clear();
	qu1.clear();
	cout<<endl;

}
void vector_test()//vector测试
{
	vector<int>vc1;
	int i;
	cout<<"push_back 插入vector尾：1"<<endl;
	vc1.push_back(1);
	cout<<"push_back 插入vector尾：2"<<endl;	
	vc1.push_back(2);
	cout<<"push_back 插入vector尾：3"<<endl;
	vc1.push_back(3);
	cout<<"push_back 插入vector尾：4"<<endl;
	vc1.push_back(4);
	cout<<"输出vector：";
	for(i=0;i<vc1.size();i++)
	{
		cout<<vc1[i]<<" "; 
	}
	cout<<endl;
	cout<<"输出vector[3]:";
	cout<<vc1[3]<<endl;
	cout<<"判断是否为空：";
	if(vc1.empty())
		cout<<"空"<<endl;
	else
		cout<<"非空"<<endl;
	cout<<"vector长度：";
	cout<<vc1.size()<<endl;
	cout<<"pop_back  删除vetor最后一个"<<endl;
	vc1.pop_back();
	cout<<"输出vector：";
	for(i=0;i<vc1.size();i++)
	{
		cout<<vc1[i]<<" "; 
	}
	cout<<endl;
	cout<<"清空vector"<<endl;
	vc1.clear();
}
void set_test()//set测试
{
	set<int> s;
	set<int>::iterator it;//set迭代器
	cout<<"insert  插入set：100"<<endl; //insert插入 
	s.insert(100);
	cout<<"insert  插入set：10"<<endl;
	s.insert(10);
	cout<<"insert  插入set：1"<<endl;
	s.insert(1);
	cout<<"insert  插入set：5"<<endl;
	s.insert(5);
	cout<<"insert  插入set：8"<<endl;
	s.insert(8);
	cout<<"insert  插入set：55"<<endl;
	s.insert(55);
	cout<<"insert  重复插入set：55"<<endl;
	s.insert(55);
	cout<<"insert  重复插入set：55"<<endl;
	s.insert(55);
	cout<<"输出set：";
	for(it=s.begin();it!=s.end();++it)  //输出set元素
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"输出第一个元素：";
	cout<<*s.begin()<<endl;
	cout<<"输出最后一个元素：";
	cout<<*(--s.end())<<endl;
	cout<<"size:";
	cout<<s.size()<<endl;
	cout<<"判空：";
	if(s.empty())
		cout<<"set 空"<<endl;
	else
		cout<<"set 非空"<<endl;
	cout<<"find    查找set元素：55  并输出:";
	cout<<*s.find(55)<<endl;//查找
	cout<<"lower_bound  查找大于等于 9的元素：";
	cout<<*s.lower_bound(9)<<endl;//查找大于等于x
	cout<<"erase   删除set元素：55"<<endl;
	s.erase(55);// erase删除
	cout<<"输出set：";
	for(it=s.begin();it!=s.end();++it)   //输出set元素
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"清空set"<<endl;

}
void map_test()//map测试
{
	map<int,char> m;
	map<int,char>::iterator it;//map 迭代器
	cout<<"insert       插入map  key:1 ,  value:a"<<endl;//插入
	m.insert(mypair<int,char>(1,'a'));
	cout<<"insert       插入map  key:55 , value:h"<<endl;
	m.insert(mypair<int,char>(55,'h'));
	cout<<"insert       插入map  key:20 , value:S"<<endl;
	m.insert(mypair<int,char>(20,'S'));
	cout<<"insert       插入map  key:6 ,  value:d"<<endl;
	m.insert(mypair<int,char>(6,'d'));
	cout<<"insert       插入map  key:10 , value:x"<<endl;
	m.insert(mypair<int,char>(10,'x'));
	cout<<"insert       插入map  key:12 , value:b"<<endl;
	m.insert(mypair<int,char>(12,'b'));
	cout<<"insert       插入map  key:1 ,  value:d"<<endl;
	m.insert(mypair<int,char>(1,'d'));
	cout<<"insert   重复插入map  key:1 ,  value:h"<<endl;
	m.insert(mypair<int,char>(1,'h'));
	cout<<"insert   重复插入map  key:1 ,  value:k"<<endl;
	m.insert(mypair<int,char>(1,'k'));
	cout<<"输出map:"<<endl;
	for(it=m.begin();it!=m.end();++it)
	{
		cout<<"first:"<<it->first<<"    second:"<<it->second<<endl;
	}
	cout<<"输出最后一个元素：";
	cout<<"first:"<<(--m.end())->first<<"   second:"<<(--m.end())->second<<endl;
	cout<<"size:";
	cout<<m.size()<<endl;
	if(m.empty())
		cout<<"map 空"<<endl;
	else
		cout<<"map 非空"<<endl;
	cout<<"find    查找map key：55  并输出value:";
	cout<<m.find(55)->second<<endl;//查找
	cout<<"lower_bound  查找key大于等于 9的 value：";
	cout<<m.lower_bound(9)->second<<endl;//查找大于等于x
	cout<<"erase   删除map元素：55"<<endl;
	m.erase(55);// erase删除
	cout<<"输出map:"<<endl;
	for(it=m.begin();it!=m.end();++it)
	{
		cout<<"first:"<<it->first<<"    second:"<<it->second<<endl;
	}
	cout<<endl;
	cout<<"清空map"<<endl;
}
void deque_test()
{
	Deque<int> q;
	if (q.empty())
		cout << "当前队列空"<<endl;
	else 
		cout << "当前队列非空"<<endl;
	cout << "1从队尾入队列"<<endl;
	q.push_back(1);
	cout << "2从队尾入队列"<<endl;
	q.push_back(2);
	cout << "3从队尾入队列"<<endl;
	q.push_back(3);
	cout << "4从队头入队列"<<endl;
	q.push_front(4);
	cout << "5从队头入队列"<<endl;
	q.push_front(5);
	cout << "6从队头入队列"<<endl;
	q.push_front(6);
	cout << "当前队列长度:"<<q.size()<<endl;
	cout << "当前队列"<<endl;
	for (int i=0;i<q.size();i++)
	{
		cout << q[i]<<" ";
	}
	cout << endl;
	cout << "队头元素出队"<<endl;
	q.pop_front();
	cout << "当前队列长度:"<<q.size()<<endl;
	cout << "队尾元素出队"<<endl;
	q.pop_back();
	cout << "当前队列长度:"<<q.size()<<endl;
	cout << "当前队列"<<endl;
	for (Deque<int>::Iterator iter=q.front();iter!=q.back();++iter)
	{
		cout << *iter<<" ";
	}
	cout << endl;
	if (q.empty())
		cout << "当前队列空"<<endl;
	else 
		cout << "当前队列非空"<<endl;
}

int main()
{
	cout<<"                   ----------list_测试--------------"<<endl;
	list_test();
	cout<<endl;
	cout<<"                   ----------stack_测试-------------"<<endl;
	stack_test();
	cout<<endl;
	cout<<"                   ----------queue_测试-------------"<<endl;
	queue_test();
	cout<<endl;
	cout<<"                   ----------vector_测试-------------"<<endl;
	vector_test();
	cout<<endl;
	cout<<"                   ------------deque_测试--------------"<<endl;
	deque_test();
	cout<<endl;
	cout<<"                   ------------set_测试--------------"<<endl;
	set_test();
	cout<<endl;
	cout<<"                   ------------map_测试--------------"<<endl;
	map_test();
	cout<<endl;
	cout<<"                   -------------Thanks--------------"<<endl;
	return 0;
}