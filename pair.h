#ifndef _pair_H_
#define _pair_H_

#include <iostream>
using namespace std;

template <class key,class value>
class mypair
{
public:
	key first;   //key
	value second; //value
	mypair():first(),second(){}  //�չ���
	mypair(key f ,key s):first(f),second(s){}//����
	mypair& Make_pair(key f,value s){return mypair(f,s);} 
	bool operator<(mypair x){return first<x.first;}
	bool operator>(mypair x){return first>x.first;}
	bool operator==(mypair x){return first==x.first;}
	bool operator!=(mypair x){return first!=x.first;}
};

#endif