#include<bits/stdc++.h>
using namespace std;
 
// An AVL tree node
class Node
{
    public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int height;
};
Node *root=NULL;
int max(int a, int b);
 
int height(Node *x)
{
    if (x == NULL)
        return -1;
    else
        return x->height;
}

void update_height(Node *x)
{
    x->height = 1 + max(height(x->left), height(x->right));
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->parent=NULL;
    node->height = 0;
    return(node);
}
Node *bst_insert(int data)
{
    Node* newnode=newNode(data);
    Node *tmp=root;
    Node *tmp_prnt;
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
void right_rotate(Node *y)
{
   Node *x = y->left;
    Node *xR = x->right;
    x->parent = y->parent;
    if (y == root)
        root = x;
    else
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
            y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
    y->left = xR;

    if (xR != NULL)
    {
        xR->parent = y;
    }

    Node *temp = y;
    while (temp)
    {
        update_height(temp);
        temp = temp->parent;
    }
}
void left_rotate(Node *y)
{
    Node *x = y->right;
    Node *xL = x->left;

    x->parent = y->parent;

    if (y == root)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    x->left = y;
    y->parent = x;
    y->right = xL;
    if (xL != NULL)
        xL->parent = y;

    Node *temp = y;
    while (temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }
}
int balance_factor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
Node *max_node(Node *root)
{
    Node *temp = root, *position;
    while (temp)
    {
        position = temp;
        temp = temp->right;
    }

    return position;
}

Node *min_node(Node *root)
{
    Node *temp = root, *position;
    while (temp)
    {
        position = temp;
        temp = temp->left;
    }

    return position;
}
Node *successor_node(Node *x)
{
    if (x == max_node(root))
        return NULL;
    else if (x->right != NULL)
    {
        return min_node(x->right);
    }
    else
    {
        Node *temp = x->parent;
        while (temp->data < x->data)
        {
            temp = temp->parent;
        }
        return temp;
    }
}

void inorder(Node *root)
{
    Node *temp;
    temp = min_node(root);

    while (temp)
    {
        cout << temp->data << "(" << balance_factor(temp) << ")"
             << " ";
        temp = successor_node(temp);
    }
}
void balance_node(Node *temp, int bfact, Node *newnode)
{
    if (bfact > 1 && newnode->data < temp->left->data)
    {
        right_rotate(temp);
    }
    else if (bfact > 1 && newnode->data > temp->left->data)
    {
        left_rotate(temp->left);
        right_rotate(temp);
    }
    else if (bfact < -1 && newnode->data > temp->right->data)
    {
        left_rotate(temp);
    }
    else if (bfact < -1 && newnode->data < temp->right->data)
    {
        
        right_rotate(temp->right);
        left_rotate(temp);
    }
}

void AVL_insert(int data)
{
    Node *newnode = bst_insert(data);
    Node *temp = newnode;
    while (temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }
    temp = newnode;
    while (temp != NULL)
    {
        int bfactor = balance_factor(temp);
        if (bfactor < -1 || bfactor > 1)
        {
            balance_node(temp, bfactor, newnode);
            break;
        }
        else
            temp = temp->parent;
    }
}