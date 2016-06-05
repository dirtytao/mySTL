#ifndef _AVLTREE_H_
#define _AVLTREE_H_

// AVL tree
#include<iostream>
using namespace std;

template<class T>
class tree_node   //树节点类
{
public:
	T data;
	int height;//高度
	int freq;//相同键的个数
	tree_node* lson;  //左儿子
	tree_node* rson;  //右儿子
	tree_node* parent; //父亲
	tree_node():lson(NULL),rson(NULL),parent(NULL),freq(1),height(0){} //构造函数
};

template<class T> 
class tree_iter      //迭代器
{
public:
	tree_node<T>* node;  //树的节点指针
	tree_iter(tree_node<T>* p):node(p){} //构造函数
	tree_iter(){node=new tree_node<T>();} //空的构造函数
	bool operator==(tree_iter<T> x){return node==x.node;} //重载==
	bool operator!=(tree_iter<T> x){return node!=x.node;}//重载！=
	T operator*(){return node->data;}   //重载*
	tree_iter<T>& operator++();  //重载前++
	tree_iter<T> operator++(int);//重载后++
	tree_iter<T>& operator--();//重载前--
	tree_iter<T> operator--(int);//重载后--
	T* operator->(){return &operator*();}//重载->
};
//重载前++
template<class T> 
tree_iter<T>& tree_iter<T>::operator++()
{
	if(node->rson!=0)//如果有右子节点
	{
		node=node->rson; //向右走
		while(node->lson!=0)// 然后一直往左子树走到底
		{
			node=node->lson;
		}
	}
	else
	{
		tree_node<T>* y=node->parent;//y=当前节点的父亲节点
		while(node==y->rson)//如果node是y的右子节点，则y<node，继续上溯
		{
			node=y;
			y=y->parent;
		}
		if(node->rson!=y)//防止寻找无右子根节点的下一节点的特殊情况的判断
			node=y;
	}
	return *this;
}
template<class T>
tree_iter<T> tree_iter<T>::operator++(int)
{
	tree_iter<T> old=*this;
	++(*this);
	return old;
}
                                                      //重载前--
template<class T> 
tree_iter<T>& tree_iter<T>::operator--()
{
	if(node->parent->parent==node)
	{
		node=node->rson;
	}
	else if(node->lson!=0)                   //如果有左子节点
	{
		tree_node<T>* y=node->lson;   
		while(y->rson!=0)    
		{
			y=y->rson;
		}
		node=y;
	}
	else
	{
		tree_node<T>* y=node->parent;// 同上
		while(node==y->lson)
		{
			node=y;
			y=y->parent;
		}
		node=y;
	}
	return *this;
}
template<class T>
tree_iter<T> tree_iter<T>::operator--(int)
{
	tree_iter<T> old=*this;
	--(*this);
	return old;
}

template<class T>
class tree       //树的类
{
	int sz;  //树的节点个数
	tree_node<T>* root;//根节点
	tree_node<T>* header;//end
	bool flag;
public:
	typedef tree_iter<T> tree_iterator;
	tree(); //构造函数
	~tree(){clear_tree(root);}
	void insert_node(tree_node<T>* &node,T x,tree_node<T>* &father);//插入
	void delete_node(tree_node<T>* &node,T x,tree_node<T>* &father);//删除
	tree_node<T>* find_node(tree_node<T>* node,T x);//查找
	void clear_tree(tree_node<T>* node);
	int height(tree_node<T>* node);//高度
	void insubtree(tree_node<T>* node);//中序遍历
	void llrotate(tree_node<T>* &x);//左左旋转
	void rrrotate(tree_node<T>* &x);//右右旋转
	void lrrotate(tree_node<T>* &x);//左右旋转
	void rlrotate(tree_node<T>* &x);//右左旋转
	tree_iter<T> lower_node(tree_node<T>* node,T x); //查找<=x的数
	tree_iter<T> upper_node(tree_node<T>* node,T x); //查找>=x的数
	void inst(T x){;insert_node(root,x,header);}//插入接口
	void dlet(T x){;delete_node(root,x,header);}//删除接口
	void show();//遍历接口
	tree_iter<T> lower(T x){return lower_node(root,x);}
	tree_iter<T> upper(T x){return upper_node(root,x);}
	void clear(){clear_tree(root);cout<<"clear over"<<endl;}// 清空树接口
	tree_node<T>* find(T x){tree_node<T>*temp=find_node(root,x);return temp;}//查找接口
	tree_node<T>* maxnum(tree_node<T>* x);
	tree_node<T>* minnum(tree_node<T>* x);
	tree_iter<T> begin(){return minnum(root);}
	tree_iter<T> end(){return header;}
	int max(int a,int b){return a>b?a:b;}
	int size(){return sz;}
	bool empty();

};
template<class T> 
tree<T>::tree()
{
	root=new tree_node<T>();
	header=new tree_node<T>();
	root->parent=header;
	header->parent=root;
	header->lson=root;
	header->rson=root;
	sz=0;
	flag=0;
}
template<class T> 
bool tree<T>::empty()
{
	return root==NULL;
}
template<class T> 
tree_node<T>* tree<T>::maxnum(tree_node<T>* x)
{
	while(x->rson!=NULL)
		x=x->rson;
	return x;
}
template<class T>
tree_node<T>* tree<T>::minnum(tree_node<T>* x)
{
	while(x->lson!=NULL)
	{
		x=x->lson;
	}
	return x;
}
//中序遍历
template<class T>
void tree<T>::insubtree(tree_node<T>* node)
{
	if(node==NULL)
		return ;
	insubtree(node->lson);
	cout<<node->data<<" ";
	insubtree(node->rson);
}
template<class T>
void tree<T>::show()
{
	insubtree(root);
}
//高度
template<class T>
int tree<T>::height(tree_node<T>* node)
{
	if(node!=NULL)
		return node->height;
	return 0;
}
//左左单转
template<class T>
void tree<T>::llrotate(tree_node<T>* &k2)
{
	tree_node<T>* k1;
	k1=k2->lson;

	k1->parent=k2->parent;  //parent change
	k2->parent=k1;
	if(k1->rson!=NULL)
		k1->rson->parent=k2;
	k2->lson=k1->rson;
	k1->rson=k2;

	k2->height=max(height(k2->lson),height(k2->rson))+1;
	k1->height=max(height(k1->lson),k2->height)+1;
	k2=k1;//当前根节点变化
}
// 右右单转
template<class T>
void tree<T>::rrrotate(tree_node<T>* &k2)
{
	tree_node<T>* k1;
	k1=k2->rson;

	k1->parent=k2->parent;
	k2->parent=k1;
	if(k1->lson!=NULL)
		k1->lson->parent=k2;


	k2->rson=k1->lson;
	k1->lson=k2;

	k2->height=max(height(k2->lson),height(k2->rson))+1;
	k1->height=max(height(k1->lson),k2->height)+1;
	k2=k1;//当前根节点变化
}
//左右双转
template<class T>
void tree<T>::lrrotate(tree_node<T>* &k3)
{
	rrrotate(k3->lson);
	llrotate(k3);
}
//右左双转
template<class T>
void tree<T>::rlrotate(tree_node<T>* &k3)
{
	llrotate(k3->rson);
	rrrotate(k3);
}
//插入

template<class T>
void tree<T>::insert_node(tree_node<T>* &node,T x,tree_node<T>* &father)
{
	if(node==root&&flag==0)
	{
		flag=1;
		node->data=x;
		sz++;
		return ;
	}
	if(node==NULL)
	{
		node=new tree_node<T>();
		node->data=x;
		node->parent=father;
		sz++;
		return ;
	}
	if(node->data>x)
	{
		insert_node(node->lson,x,node);
		if(height(node->lson)-height(node->rson)==2)
		{
			if(x<node->lson->data)
				llrotate(node);
			else
				lrrotate(node);
		}
	}
	else if(node->data<x)
	{
		insert_node(node->rson,x,node);
		if(height(node->rson)-height(node->lson)==2)
		{
			if(x>node->rson->data)
				rrrotate(node);
			else
				rlrotate(node);
		}
	}
	else
		++(node->freq);
	node->height=max(height(node->lson),height(node->rson))+1;
	header->rson=maxnum(root);
	header->lson=minnum(root);
	header->parent=root;
}
//删除 
template<class T>
void tree<T>::delete_node(tree_node<T>* &node,T x,tree_node<T>* &father)
{
	if(node==NULL)
		return ;
	if(node->data>x)
	{
		delete_node(node->lson,x,node);
		if(height(node->rson)-height(node->lson)==2)
		{
			if(node->rson->lson!=NULL&&(height(node->rson->lson)>height(node->rson->rson)))
				rlrotate(node);
			else
				rrrotate(node);
		}
	}
	else if(x>node->data)
	{
		delete_node(node->rson,x,node);
		if(height(node->lson)-height(node->rson)==2)
		{
			if(node->lson->rson!=NULL&&(height(node->lson->rson)>height(node->lson->lson)))
				lrrotate(node);
			else
				llrotate(node);
		}
	}
	else
	{
		if(node->lson&&node->rson)//此节点有两个儿子,那么就把右子树中的最小值复制到该节点，并且把右子树的最小值删除！
		{
			tree_node<T>* temp=node->rson; //temp指向右节点
			while(temp->lson!=NULL) //找到右子树的最小节点
				temp=temp->lson;
			node->data=temp->data; //把右子树的最小节点赋值给该节点
			node->freq=temp->freq; //同上
			delete_node(node->rson,temp->data,node); //删除右子树中最小节点
			if(height(node->lson)-height(node->rson)==2)//判断平衡
			{
				if(node->lson->rson!=NULL&&(height(node->lson->rson)>height(node->lson->lson)))
					lrrotate(node);
				else
					llrotate(node);
			}
		}
		else  // 此节点只有0或1个儿子
		{
			tree_node<T>* temp=node;
			if(node->lson==NULL)//只有右儿子
			{
				node=node->rson;
				if(node!=NULL)
					node->parent=father;
 			}
			else if(node->rson==NULL)//只有左儿子
			{
				node=node->lson;
				if(node!=NULL)
					node->parent=father;
			}
  			delete temp;
			sz--;
		}
	}
	if(root==NULL)//如果根结点被删除了,所以要重新分配
	{
		root=new tree_node<T>();
	    root->parent=header;
	    header->parent=root;
	    header->lson=root;
	    header->rson=root;
	    sz=0;
	    flag=0;
	}
	if(node==NULL)
		return ;
	node->height=max(height(node->lson),height(node->rson))+1;
	header->rson=maxnum(root);
	header->lson=minnum(root);
	header->parent=root;
}
//查找
template<class T>
tree_node<T>* tree<T>::find_node(tree_node<T>* node,T x)
{
	if(node==NULL)
	{
		return NULL;
	}
	if(node->data>x)
	{
		return find_node(node->lson,x);
	}
	else if(node->data<x)
	{
		return find_node(node->rson,x);
	}
	else
	{
		return node;
	}
}
template<class T> 
void tree<T>::clear_tree(tree_node<T>* node)
{
	if(node==NULL)
		return ;
	if(node->lson!=NULL)
		clear_tree(node->lson);
	if(node->rson!=NULL)
		clear_tree(node->rson);
	delete node;
}
//查找<=x的数
template<class T>
tree_iter<T> tree<T>::lower_node(tree_node<T>* node,T x)
{
	tree_node<T>* temp;
	while(1)
	{
		if(x<node->data)
		{
			if(node->lson==NULL)
				break;
			node=node->lson;
		}
		else 
		{
			temp=node;
			if(node->rson==NULL)
				break;
			node=node->rson;
		}
	}
	return temp;

}
//查找>=x的数
template<class T> 
tree_iter<T> tree<T>::upper_node(tree_node<T>* node,T x)
{
	tree_node<T>* temp;
	while(1)
	{
		if(x>node->data)
		{
			if(node->rson==NULL)
				break;
			node=node->rson;
		}
		else 
		{
			temp=node;
			if(node->lson==NULL)
				break;
			node=node->lson;
		}
	}
	return temp;

}
#endif