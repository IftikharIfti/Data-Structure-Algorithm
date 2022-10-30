#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

struct node
{
    node *parent;
    node *left;
    node *right;
    int data;
    node(){};
    node(int x):data(x){}
};

node* create_node(int x);
void level_order_traversal(node *root);
node* insert_node(node *root,int key);
node* iter_insert(node *root,int key);
node* tree_search(node *root,int key);
void inorder(node *root);
void iter_inorder(node *root);
node *tree_max(node *root);
node *tree_min(node *root);
node *successor(node *root, int key);
node *predecessor(node *root, int key);
node *delete_node(node *root,int key);



node *create_node(int x)
{
    node *newnode=new node();
     newnode->data=x;
     newnode->left=NULL;
     newnode->right=NULL;
     newnode->parent=NULL;
     return newnode;
}

void level_order_traversal(node *root)
{
 if(root==NULL)
  return ;
 queue<node*> q;
 q.push(root);
 while(!q.empty())
 {
    node * front=q.front();
    cout<<front->data<<' ';
    q.pop();
    if(front->left!=NULL)
    {
        q.push(front->left);
    }
    if(front->right!=NULL)
    {
        q.push(front->right);
    }
 }
 cout<<endl;
}
node *insert_node(node *root, int key)
{
   if (root == NULL) {
        return create_node(key);
    }
 
    
    if (key < root->data) {
        root->left = insert_node(root->left, key);
    }
   
    else {
        root->right = insert_node(root->right, key);
    }
 
    return root;
}
node *iter_insert(node *root,int key)
{
    node* newnode=create_node(key);
    node *tmp=root;
    node *tmp_prnt;
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    while(tmp!=NULL)
    {
        tmp_prnt=tmp;
        if(newnode->data<=tmp->data)
        {
            tmp=tmp->left;
        }
        else
        {
            tmp=tmp->right;
        }
    }
    newnode->parent=tmp_prnt;
    if(newnode->data<=tmp_prnt->data)
    tmp_prnt->left=newnode;
    else
    tmp_prnt->right=newnode;

    return root;
}

node *tree_search(node *root,int key)
{
    node *tmp=root;
    while(tmp!=NULL&&tmp->data!=key)
     {
        if(key<=tmp->data)
        {
            tmp=tmp->left;
        }
        else
        {
            tmp=tmp->right;
        }
     }
     return tmp;
}
void inorder(node *root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void iter_inorder(node *root)
{
   stack<node*> s;
   node *tmp=root;
   while(tmp!=NULL||s.empty()==false)
   {
    while(tmp!=NULL)
     {
        s.push(tmp);
        tmp=tmp->left;
     }
     tmp=s.top();
     s.pop();
     cout<<tmp->data<<" ";
     tmp=tmp->right;
   }
}

node *tree_max(node *root)
{
   
   while(root->right!=NULL)
   root=root->right;
   
   return root;
}

node *tree_min(node *root)
{
    node *tmp=root;
    while(tmp->left!=NULL)
    tmp=tmp->left;

    return tmp;
}

node *successor(node *root,int key)
{
    node *x=tree_search(root,key);
    if(x==tree_max(root))
    return NULL;
    else if(x->right!=NULL)
    {
        return tree_min(x->right);
    }
    else
    {
      node *y=x->parent;
      while(y->data<x->data)
      {
        y=y->parent;
      }
      return y;
    }
}
node *predecessor(node *root,int key)
{
    node *x=tree_search(root,key);

    if(x==tree_min(root))
   {
     return NULL;
   }
    else if(x->left!=NULL) return tree_max(x->left);

    else
    {
        node *y=x->parent;
        while(y->data>x->data)
        {
            y=y->parent;
        }
        return y;
    }
}


node *delete_node(node *root,int key)
{
     node *z = tree_search(root, key);
    node *p = z->parent;
    /*Case 1*/
    if (z->left == NULL && z->right == NULL)
    {
        if (p != NULL)
        {
            if (p->left == z)
                p->left = NULL;
            else
                p->right = NULL;
            delete z;
        }
        else
        {
            delete z;
            root = NULL;
        }
        return root;
    }
   

    /*Case 2*/
    else if ((z->left == NULL && z->right != NULL) || (z->left != NULL && z->right == NULL))
    {
        if (p != NULL)
        {
            if (p->right == z)
            {
                if (z->left == NULL)
                {
                    p->right = z->right;
                    z->right->parent = p;
                }
                else
                {
                    p->right = z->left;
                    z->left->parent = p;
                }
            }
            else
            {
                if (z->left == NULL)
                {
                    p->left = z->right;
                    z->right->parent = p;
                }
                else
                {
                    p->left = z->left;
                    z->left->parent = p;
                }
            }
        }
        else //check
        {
            if (z->left != NULL)
                root = z->left;
            else
                root = z->right;
        }
        delete z;
        return root;
    }
    /*Case 3*/
    // (z->left != NULL && z->right != NULL)
    else
    {
        node *y = successor(root, key);

        if (p != NULL)
        {
            if (p->right == z)
                p->right = z->right;
            else
                p->left = z->right;
            z->right->parent = p;
            y->left = z->left;
            z->left->parent = y;
        }
        else
        {
            root = z->right;
            z->right->parent = p;
            y->left = z->left;
            z->left->parent = y;
        }
        delete z;
        return root;
    }
}