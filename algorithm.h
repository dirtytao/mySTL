#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include<iostream>
using namespace std;

//范围打印
template<class iter>
void printf(iter a,iter b)
{
	iter it;
	for(it=a;it!=b;++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
template<class iter>
//范围求和
void show_sum(iter a,iter b)
{
	double sum=0;
	iter it;
	for(it=a;it!=b;++it)
	{
		sum+=*it;
	}
	cout<<sum<<endl;
}
template<class iter>
//范围求最大值
void show_max(iter a,iter b)
{
	iter max=a;
	iter it;
	++a;
	for(it=a;it!=b;++it)
	{
		if(*max<*it)
		{
			max=it;
		}
	}
	cout<<*max<<endl;
}
template<class iter>
//范围求最小值
void show_min(iter a,iter b)
{
	iter min=a;
	iter it;
	++a;
	for(it=a;it!=b;++it)
	{
		if(*min>*it)
		{
			min=it;
		}
	}
	cout<<*min<<endl;
}
// 查找范围内是否存在数x
template<class iter,class T>
bool find_num(iter a,iter b,T x)
{
	iter it;
	for(it=a;it!=b;++it)
	{
		if(*it==x)
			return true;
	}
	if(*b==x)
		return true;
	return false;
}
//两个中返回大的
template<class iter>
iter max(iter a, iter b)
{
	return *a>*b?a:b;
}
//两个中返回小的
template<class iter>
iter min(iter a, iter b)
{
	return *a<*b?a:b;
}

#endif