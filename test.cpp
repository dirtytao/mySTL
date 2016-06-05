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

void list_test() //list����
{
	list<int> mylist;
	list<int>::iterator  it;//list������
	cout<<"insert     ����listͷ��2"<<endl;
	mylist.insert(mylist.begin(),2);//insert����listͷ
	cout<<"insert     ����listβ��3"<<endl;
	mylist.insert(mylist.end(),3);//insert����listβ
	cout<<"push_back  ����listβ��1"<<endl;
	mylist.push_back(1);
	cout<<"push_back  ����listβ��10"<<endl;
	mylist.push_back(10);
	cout<<"push_back  ����listβ��55"<<endl;
	mylist.push_back(55);
	cout<<"push_front ����listͷ��15"<<endl;
	mylist.push_front(15);
	cout<<"push_front ����listͷ��7"<<endl;
	mylist.push_front(7);
	cout<<"push_front ����listͷ��8"<<endl;
	mylist.push_front(8);
	cout<<"�������";
	for(it=mylist.begin();it!=mylist.end();++it)//list����
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"list���ȣ�";
	cout<<mylist.size()<<endl;//���list�ĳ���
	cout<<"���listͷ��";
	cout<<mylist.front()<<endl;//���listͷ
	cout<<"���listβ��";
	cout<<mylist.back()<<endl;//���listβ
	cout<<"pop_back   ɾ��listβ "<<endl;
	mylist.pop_back();//ɾ��listβ
	cout<<"pop_back   ɾ��listͷ "<<endl;
	mylist.pop_front();//ɾ��listͷ
	cout<<"erase      ɾ��listͷ "<<endl;
	mylist.erase(mylist.begin());//��eraseɾ��listͷ
	cout<<"list���ȣ�";
	cout<<mylist.size()<<endl;//���list�ĳ���
	cout<<"�������";
	for(it=mylist.begin();it!=mylist.end();++it)//list����
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"�������"<<endl;
	mylist.clear(); //���list
}
void stack_test()//stack����
{
	stack<int> st;
	stack<int> st1;
	cout<<"1 ��ջ"<<endl;
	cout<<"2 ��ջ"<<endl;
	cout<<"3 ��ջ"<<endl;
	cout<<"4 ��ջ"<<endl;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<"ջ�ĳ���:";
	cout<<st.size()<<endl;
	cout<<"��ջ����ʼ���ջ��"<<endl;
	while(!st.empty())//�п�
	{
		cout<<st.top()<<" ��ջ"<<endl;//���ջ��
		st1.push(st.top());
		st.pop();              //��ջ;
	}
	cout<<"ջ�ĳ���:";
	cout<<st.size()<<endl;
	if(st==st1)
		cout<<"ջ��ջ2���"<<endl;
	else
		cout<<"ջ��ջ2�����"<<endl;
	cout<<"�ж�ջ�Ƿ�Ϊ�գ�";
	if(st.empty())
		cout<<"ջΪ�գ�"<<endl;
	else
		cout<<"ջ��Ϊ��!"<<endl;
	cout<<"���ջ";
	st.clear();
	st1.clear();
	cout<<endl;

}
void queue_test()//queue����
{
	queue<int> qu;
	queue<int> qu1;
	cout<<"1 �����"<<endl;
	cout<<"2 �����"<<endl;
	cout<<"3 �����"<<endl;
	cout<<"4 �����"<<endl;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	cout<<"���еĳ��ȣ�"<<qu.size()<<endl;
	cout<<"�Ӷ�ͷ������У�"<<endl;
	while(!qu.empty())
	{
		cout<<qu.top()<<" ������"<<endl;
		qu1.push(qu.top());
		qu.pop();
	}
	if(qu==qu1)
		cout<<"���кͶ���1���"<<endl;
	else
		cout<<"���кͶ���1�����"<<endl;
	cout<<"���еĳ��ȣ�"<<qu.size()<<endl;
	cout<<"�ж϶����Ƿ�Ϊ�գ�";
	if(qu.empty())
		cout<<"����Ϊ�գ�"<<endl;
	else
		cout<<"���в�Ϊ��!"<<endl;
	cout<<"��ն���";
	qu.clear();
	qu1.clear();
	cout<<endl;

}
void vector_test()//vector����
{
	vector<int>vc1;
	int i;
	cout<<"push_back ����vectorβ��1"<<endl;
	vc1.push_back(1);
	cout<<"push_back ����vectorβ��2"<<endl;	
	vc1.push_back(2);
	cout<<"push_back ����vectorβ��3"<<endl;
	vc1.push_back(3);
	cout<<"push_back ����vectorβ��4"<<endl;
	vc1.push_back(4);
	cout<<"���vector��";
	for(i=0;i<vc1.size();i++)
	{
		cout<<vc1[i]<<" "; 
	}
	cout<<endl;
	cout<<"���vector[3]:";
	cout<<vc1[3]<<endl;
	cout<<"�ж��Ƿ�Ϊ�գ�";
	if(vc1.empty())
		cout<<"��"<<endl;
	else
		cout<<"�ǿ�"<<endl;
	cout<<"vector���ȣ�";
	cout<<vc1.size()<<endl;
	cout<<"pop_back  ɾ��vetor���һ��"<<endl;
	vc1.pop_back();
	cout<<"���vector��";
	for(i=0;i<vc1.size();i++)
	{
		cout<<vc1[i]<<" "; 
	}
	cout<<endl;
	cout<<"���vector"<<endl;
	vc1.clear();
}
void set_test()//set����
{
	set<int> s;
	set<int>::iterator it;//set������
	cout<<"insert  ����set��100"<<endl; //insert���� 
	s.insert(100);
	cout<<"insert  ����set��10"<<endl;
	s.insert(10);
	cout<<"insert  ����set��1"<<endl;
	s.insert(1);
	cout<<"insert  ����set��5"<<endl;
	s.insert(5);
	cout<<"insert  ����set��8"<<endl;
	s.insert(8);
	cout<<"insert  ����set��55"<<endl;
	s.insert(55);
	cout<<"insert  �ظ�����set��55"<<endl;
	s.insert(55);
	cout<<"insert  �ظ�����set��55"<<endl;
	s.insert(55);
	cout<<"���set��";
	for(it=s.begin();it!=s.end();++it)  //���setԪ��
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"�����һ��Ԫ�أ�";
	cout<<*s.begin()<<endl;
	cout<<"������һ��Ԫ�أ�";
	cout<<*(--s.end())<<endl;
	cout<<"size:";
	cout<<s.size()<<endl;
	cout<<"�пգ�";
	if(s.empty())
		cout<<"set ��"<<endl;
	else
		cout<<"set �ǿ�"<<endl;
	cout<<"find    ����setԪ�أ�55  �����:";
	cout<<*s.find(55)<<endl;//����
	cout<<"lower_bound  ���Ҵ��ڵ��� 9��Ԫ�أ�";
	cout<<*s.lower_bound(9)<<endl;//���Ҵ��ڵ���x
	cout<<"erase   ɾ��setԪ�أ�55"<<endl;
	s.erase(55);// eraseɾ��
	cout<<"���set��";
	for(it=s.begin();it!=s.end();++it)   //���setԪ��
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"���set"<<endl;

}
void map_test()//map����
{
	map<int,char> m;
	map<int,char>::iterator it;//map ������
	cout<<"insert       ����map  key:1 ,  value:a"<<endl;//����
	m.insert(mypair<int,char>(1,'a'));
	cout<<"insert       ����map  key:55 , value:h"<<endl;
	m.insert(mypair<int,char>(55,'h'));
	cout<<"insert       ����map  key:20 , value:S"<<endl;
	m.insert(mypair<int,char>(20,'S'));
	cout<<"insert       ����map  key:6 ,  value:d"<<endl;
	m.insert(mypair<int,char>(6,'d'));
	cout<<"insert       ����map  key:10 , value:x"<<endl;
	m.insert(mypair<int,char>(10,'x'));
	cout<<"insert       ����map  key:12 , value:b"<<endl;
	m.insert(mypair<int,char>(12,'b'));
	cout<<"insert       ����map  key:1 ,  value:d"<<endl;
	m.insert(mypair<int,char>(1,'d'));
	cout<<"insert   �ظ�����map  key:1 ,  value:h"<<endl;
	m.insert(mypair<int,char>(1,'h'));
	cout<<"insert   �ظ�����map  key:1 ,  value:k"<<endl;
	m.insert(mypair<int,char>(1,'k'));
	cout<<"���map:"<<endl;
	for(it=m.begin();it!=m.end();++it)
	{
		cout<<"first:"<<it->first<<"    second:"<<it->second<<endl;
	}
	cout<<"������һ��Ԫ�أ�";
	cout<<"first:"<<(--m.end())->first<<"   second:"<<(--m.end())->second<<endl;
	cout<<"size:";
	cout<<m.size()<<endl;
	if(m.empty())
		cout<<"map ��"<<endl;
	else
		cout<<"map �ǿ�"<<endl;
	cout<<"find    ����map key��55  �����value:";
	cout<<m.find(55)->second<<endl;//����
	cout<<"lower_bound  ����key���ڵ��� 9�� value��";
	cout<<m.lower_bound(9)->second<<endl;//���Ҵ��ڵ���x
	cout<<"erase   ɾ��mapԪ�أ�55"<<endl;
	m.erase(55);// eraseɾ��
	cout<<"���map:"<<endl;
	for(it=m.begin();it!=m.end();++it)
	{
		cout<<"first:"<<it->first<<"    second:"<<it->second<<endl;
	}
	cout<<endl;
	cout<<"���map"<<endl;
}
void deque_test()
{
	Deque<int> q;
	if (q.empty())
		cout << "��ǰ���п�"<<endl;
	else 
		cout << "��ǰ���зǿ�"<<endl;
	cout << "1�Ӷ�β�����"<<endl;
	q.push_back(1);
	cout << "2�Ӷ�β�����"<<endl;
	q.push_back(2);
	cout << "3�Ӷ�β�����"<<endl;
	q.push_back(3);
	cout << "4�Ӷ�ͷ�����"<<endl;
	q.push_front(4);
	cout << "5�Ӷ�ͷ�����"<<endl;
	q.push_front(5);
	cout << "6�Ӷ�ͷ�����"<<endl;
	q.push_front(6);
	cout << "��ǰ���г���:"<<q.size()<<endl;
	cout << "��ǰ����"<<endl;
	for (int i=0;i<q.size();i++)
	{
		cout << q[i]<<" ";
	}
	cout << endl;
	cout << "��ͷԪ�س���"<<endl;
	q.pop_front();
	cout << "��ǰ���г���:"<<q.size()<<endl;
	cout << "��βԪ�س���"<<endl;
	q.pop_back();
	cout << "��ǰ���г���:"<<q.size()<<endl;
	cout << "��ǰ����"<<endl;
	for (Deque<int>::Iterator iter=q.front();iter!=q.back();++iter)
	{
		cout << *iter<<" ";
	}
	cout << endl;
	if (q.empty())
		cout << "��ǰ���п�"<<endl;
	else 
		cout << "��ǰ���зǿ�"<<endl;
}

int main()
{
	cout<<"                   ----------list_����--------------"<<endl;
	list_test();
	cout<<endl;
	cout<<"                   ----------stack_����-------------"<<endl;
	stack_test();
	cout<<endl;
	cout<<"                   ----------queue_����-------------"<<endl;
	queue_test();
	cout<<endl;
	cout<<"                   ----------vector_����-------------"<<endl;
	vector_test();
	cout<<endl;
	cout<<"                   ------------deque_����--------------"<<endl;
	deque_test();
	cout<<endl;
	cout<<"                   ------------set_����--------------"<<endl;
	set_test();
	cout<<endl;
	cout<<"                   ------------map_����--------------"<<endl;
	map_test();
	cout<<endl;
	cout<<"                   -------------Thanks--------------"<<endl;
	return 0;
}