#include<iostream>
using namespace std;

class DLL_Node
{
    int   _DATA;
    DLL_Node* _PREV;
    DLL_Node* _NEXT;
    public:
    static int _DLL_SIZE;
    DLL_Node():_DATA(0),_PREV(NULL),_NEXT(NULL){}
    DLL_Node(int dat,DLL_Node* prev,DLL_Node* next):_DATA(dat),_PREV(prev),_NEXT(next){}
    DLL_Node* CREATE_NODE(int val)
    {
        
      DLL_Node *temp=new DLL_Node(val,NULL,NULL);
      return temp;
    } 
    void INSERT_AFTER_VALUE(int x,int val,DLL_Node *head)
    {
        DLL_Node* newnode= CREATE_NODE(x);
         DLL_Node* temp=head;
         while(temp->_DATA!=val)
               temp=temp->_NEXT;
          
        
         newnode->_NEXT=temp->_NEXT;
         temp->_NEXT->_PREV=newnode;
         temp->_NEXT=newnode;
         newnode->_PREV=temp;
         _DLL_SIZE++;
    }
    void INSERT_AT_THE_END(int x,DLL_Node *head)
    {
        DLL_Node* newnode= CREATE_NODE(x);
        DLL_Node* temp=head;
        while(temp->_NEXT!=NULL)
        {
         temp=temp->_NEXT;
        }
        newnode->_NEXT=NULL;
        temp->_NEXT=newnode;
        newnode->_PREV=temp;
        _DLL_SIZE++;
    }
    void INSERT_AFTER_POSITION(int x,int position,DLL_Node*head)
    {
        DLL_Node* newnode=CREATE_NODE(x);
        DLL_Node* temp=head;
        for(int i=1;i<=position-1;i++)
        {
            temp=temp->_NEXT;
        }
        newnode->_NEXT=temp->_NEXT;
        temp->_NEXT->_PREV=newnode;
        temp->_NEXT=newnode;
        newnode->_PREV=temp;
        _DLL_SIZE++;
    }
    DLL_Node* INSERT_AT_FRONT(int x,DLL_Node *head)
    {
        DLL_Node* newnode=CREATE_NODE(x);
        newnode->_NEXT=head;
        head->_PREV=newnode;
        head=newnode;
        _DLL_SIZE++;
        return head;
    }
    void DELETE_NODE(int position,DLL_Node*head)
    {
      DLL_Node* temp=head;
      DLL_Node* prev;
      for(int i=1;i<=position-1;i++)
      {
        temp=temp->_NEXT;
      }
      prev=temp->_PREV;
      prev->_NEXT=temp->_NEXT;
      temp->_NEXT->_PREV=prev;
      delete(temp);
      _DLL_SIZE--;
    }
    void PRINT_DLL(DLL_Node* head)
    {
     DLL_Node* temp=head;
     while(temp!=NULL)
     {
        cout<<temp->_DATA<<endl;
        temp=temp->_NEXT;
     }
     cout<<_DLL_SIZE<<endl;
    }
    void PRINT_DLL_REVERSE(DLL_Node* head)
    {
        
    DLL_Node* temp=head;
    while(temp->_NEXT!=NULL)
     {
        
        temp=temp->_NEXT;
     }
        cout<<endl;
        for(int i=_DLL_SIZE;i>=1;i--)
        {
         cout<<temp->_DATA<<endl;
         temp=temp->_PREV;
        }
    }
    void UPDATE_NODE(int x,int position,DLL_Node* head)
    {
        DLL_Node* temp=head;
        if(position>_DLL_SIZE)
        {
            cout<<"OUT OF BOUND\n";
            return;
        }
        for(int i=1;i<=position-1;i++)
        {
         temp=temp->_NEXT;
        }
        temp->_DATA=x;
    }
};
int DLL_Node::_DLL_SIZE=1;
DLL_Node* head=NULL;

int main()
{
    head=head->CREATE_NODE(5);
    head->INSERT_AT_THE_END(6,head);
    head->INSERT_AT_THE_END(8,head);
    head->INSERT_AFTER_VALUE(7,5,head);
    head->INSERT_AFTER_POSITION(10,2,head);
    head=head->INSERT_AT_FRONT(11,head);
    head->PRINT_DLL(head);
    cout<<endl;
    head->DELETE_NODE(2,head);
    head->PRINT_DLL(head);
    head->PRINT_DLL_REVERSE(head);
}


