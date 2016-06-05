#ifndef _AVLTREE_H_
#define _AVLTREE_H_

// AVL tree
#include<iostream>
using namespace std;

template<class T>
class tree_node   //���ڵ���
{
public:
	T data;
	int height;//�߶�
	int freq;//��ͬ���ĸ���
	tree_node* lson;  //�����
	tree_node* rson;  //�Ҷ���
	tree_node* parent; //����
	tree_node():lson(NULL),rson(NULL),parent(NULL),freq(1),height(0){} //���캯��
};

template<class T> 
class tree_iter      //������
{
public:
	tree_node<T>* node;  //���Ľڵ�ָ��
	tree_iter(tree_node<T>* p):node(p){} //���캯��
	tree_iter(){node=new tree_node<T>();} //�յĹ��캯��
	bool operator==(tree_iter<T> x){return node==x.node;} //����==
	bool operator!=(tree_iter<T> x){return node!=x.node;}//���أ�=
	T operator*(){return node->data;}   //����*
	tree_iter<T>& operator++();  //����ǰ++
	tree_iter<T> operator++(int);//���غ�++
	tree_iter<T>& operator--();//����ǰ--
	tree_iter<T> operator--(int);//���غ�--
	T* operator->(){return &operator*();}//����->
};
//����ǰ++
template<class T> 
tree_iter<T>& tree_iter<T>::operator++()
{
	if(node->rson!=0)//��������ӽڵ�
	{
		node=node->rson; //������
		while(node->lson!=0)// Ȼ��һֱ���������ߵ���
		{
			node=node->lson;
		}
	}
	else
	{
		tree_node<T>* y=node->parent;//y=��ǰ�ڵ�ĸ��׽ڵ�
		while(node==y->rson)//���node��y�����ӽڵ㣬��y<node����������
		{
			node=y;
			y=y->parent;
		}
		if(node->rson!=y)//��ֹѰ�������Ӹ��ڵ����һ�ڵ������������ж�
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
                                                      //����ǰ--
template<class T> 
tree_iter<T>& tree_iter<T>::operator--()
{
	if(node->parent->parent==node)
	{
		node=node->rson;
	}
	else if(node->lson!=0)                   //��������ӽڵ�
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
		tree_node<T>* y=node->parent;// ͬ��
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
class tree       //������
{
	int sz;  //���Ľڵ����
	tree_node<T>* root;//���ڵ�
	tree_node<T>* header;//end
	bool flag;
public:
	typedef tree_iter<T> tree_iterator;
	tree(); //���캯��
	~tree(){clear_tree(root);}
	void insert_node(tree_node<T>* &node,T x,tree_node<T>* &father);//����
	void delete_node(tree_node<T>* &node,T x,tree_node<T>* &father);//ɾ��
	tree_node<T>* find_node(tree_node<T>* node,T x);//����
	void clear_tree(tree_node<T>* node);
	int height(tree_node<T>* node);//�߶�
	void insubtree(tree_node<T>* node);//�������
	void llrotate(tree_node<T>* &x);//������ת
	void rrrotate(tree_node<T>* &x);//������ת
	void lrrotate(tree_node<T>* &x);//������ת
	void rlrotate(tree_node<T>* &x);//������ת
	tree_iter<T> lower_node(tree_node<T>* node,T x); //����<=x����
	tree_iter<T> upper_node(tree_node<T>* node,T x); //����>=x����
	void inst(T x){;insert_node(root,x,header);}//����ӿ�
	void dlet(T x){;delete_node(root,x,header);}//ɾ���ӿ�
	void show();//�����ӿ�
	tree_iter<T> lower(T x){return lower_node(root,x);}
	tree_iter<T> upper(T x){return upper_node(root,x);}
	void clear(){clear_tree(root);cout<<"clear over"<<endl;}// ������ӿ�
	tree_node<T>* find(T x){tree_node<T>*temp=find_node(root,x);return temp;}//���ҽӿ�
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
//�������
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
//�߶�
template<class T>
int tree<T>::height(tree_node<T>* node)
{
	if(node!=NULL)
		return node->height;
	return 0;
}
//����ת
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
	k2=k1;//��ǰ���ڵ�仯
}
// ���ҵ�ת
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
	k2=k1;//��ǰ���ڵ�仯
}
//����˫ת
template<class T>
void tree<T>::lrrotate(tree_node<T>* &k3)
{
	rrrotate(k3->lson);
	llrotate(k3);
}
//����˫ת
template<class T>
void tree<T>::rlrotate(tree_node<T>* &k3)
{
	llrotate(k3->rson);
	rrrotate(k3);
}
//����

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
//ɾ�� 
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
		if(node->lson&&node->rson)//�˽ڵ�����������,��ô�Ͱ��������е���Сֵ���Ƶ��ýڵ㣬���Ұ�����������Сֵɾ����
		{
			tree_node<T>* temp=node->rson; //tempָ���ҽڵ�
			while(temp->lson!=NULL) //�ҵ�����������С�ڵ�
				temp=temp->lson;
			node->data=temp->data; //������������С�ڵ㸳ֵ���ýڵ�
			node->freq=temp->freq; //ͬ��
			delete_node(node->rson,temp->data,node); //ɾ������������С�ڵ�
			if(height(node->lson)-height(node->rson)==2)//�ж�ƽ��
			{
				if(node->lson->rson!=NULL&&(height(node->lson->rson)>height(node->lson->lson)))
					lrrotate(node);
				else
					llrotate(node);
			}
		}
		else  // �˽ڵ�ֻ��0��1������
		{
			tree_node<T>* temp=node;
			if(node->lson==NULL)//ֻ���Ҷ���
			{
				node=node->rson;
				if(node!=NULL)
					node->parent=father;
 			}
			else if(node->rson==NULL)//ֻ�������
			{
				node=node->lson;
				if(node!=NULL)
					node->parent=father;
			}
  			delete temp;
			sz--;
		}
	}
	if(root==NULL)//�������㱻ɾ����,����Ҫ���·���
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
//����
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
//����<=x����
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
//����>=x����
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