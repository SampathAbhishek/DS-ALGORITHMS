#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

class LinkedList
{
  public:
      Node *head;
    LinkedList()
    {
        head=NULL;
    }
    void insert_roopu_hi(int x);
    void display();
};

void LinkedList::insert_roopu_hi(int x)
{
    Node *t;
    t = new Node;
    t->next=NULL;
    t->data=x;
    if(head==NULL)
    {
        head=t;
    }
    else
    {   
        t->next=head;
        head=t;
    }
    
}

void LinkedList::display()
{
    Node *p=head;
    while(p!=nullptr)
    {
        cout<<"->"<<p->data;
        p=p->next;
    }
}


int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    LinkedList obj;
    for(i=0;i<n;i++)
     obj.insert_roopu_hi(a[i]);
    obj.display();
    return(0);
    
}


