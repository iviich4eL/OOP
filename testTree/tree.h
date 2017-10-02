#ifndef _TREE_H
#define _TREE_H

template <class NODETYPE> class Tree;
#include "node.h"
#include <iostream>
using namespace std;

template <class NODETYPE>
class Tree
{
public:
    Tree();
    int insert_node(const NODETYPE &);
    TreeNode<NODETYPE>* delete_node(TreeNode<NODETYPE> *);
    void inorder_walk(TreeNode<NODETYPE>*);
    TreeNode<NODETYPE>* find_max(TreeNode<NODETYPE>*);
    TreeNode<NODETYPE>* find_min(TreeNode<NODETYPE>*);
    TreeNode<NODETYPE>* find_node(TreeNode<NODETYPE>*,const NODETYPE &);
    TreeNode<NODETYPE>* find_succsessor(const NODETYPE &);
    TreeNode<NODETYPE> *get_root();
private:
    TreeNode<NODETYPE> *root;
};

template<class NODETYPE>
Tree<NODETYPE>::Tree()
{
    root=0;
}
template<class NODETYPE>
int Tree<NODETYPE>::insert_node(const NODETYPE &x)
{
    TreeNode<NODETYPE>* n=new TreeNode<NODETYPE>(x);
    TreeNode<NODETYPE>* ptr;
    TreeNode<NODETYPE>* ptr1;

    n->parent=n->left=n->right=0;
    ptr=root;
    while(ptr!=0)
    {
        ptr1=ptr;
        if(x < ptr->get_data() )
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    n->parent=ptr1;
    if(ptr1==0)
        root=n;
    else
    {
        if(x < ptr1->get_data() )
            ptr1->left=n;
        else
            ptr1->right=n;
    }
    return 0;
}
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::delete_node(TreeNode<NODETYPE> *z)
{
    TreeNode<NODETYPE>* y;
    TreeNode<NODETYPE>* x;
    if(z->left == 0 || z->right == 0)
        y=z;
    else
        y=find_succsessor(z->get_data());
    if(y->left!=0)
        x=y->left;
    else
        x=y->right;
    if(x!=0)
        x->parent=y->parent;
    if(y->parent == 0)
        root=x;
    else
    {
        if (y== (y->parent)->left)
            (y->parent)->left=x;
        else
            (y->parent)->right=x;
    }
    if(y!=z)
        z->data=y->get_data();
    return y;
}
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_max(TreeNode<NODETYPE>* x)
{
    while(x->right!=0)
        x=x->right;
    return x;
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_min(TreeNode<NODETYPE>* x)
{
    while(x->left!=0)
        x=x->left;
    return x;
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_succsessor(const NODETYPE & val)
{
    TreeNode<NODETYPE>* x=find_node(root,val);
    TreeNode<NODETYPE>* y;
    if(x == 0)
        return 0;
    if(x->right!=0)
        return find_min(x->right);
    y=x->parent;
    while(y!=0 && x == y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::find_node(TreeNode<NODETYPE>* n,
                                              const NODETYPE & val)
{
    if(n==0 || val==n->get_data())
        return n;
    if(val > n->get_data() )
        return find_node(n->right,val);
    else
        return find_node(n->left,val);
}
template<class NODETYPE>
void Tree<NODETYPE>::inorder_walk(TreeNode<NODETYPE>* n)
{
    if(n!=0)
    {
        inorder_walk(n->left);
        cout<<n->get_data()<<endl;
        inorder_walk(n->right);
    }
}

template<class NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::get_root()
{
    return root;
}
#endif
