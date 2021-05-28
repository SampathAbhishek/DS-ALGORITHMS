#include<iostream>
using namespace std;

class Node
{
public:
  Node *left;
  int data;
  Node *right;
};

class Queue
{
  private:
    int size;
    int front;
    int rear;
    Node **Q;
 public:
    Queue(){
        size = 10;
        front = rear = -1;
        Q = new Node * [size];
    }
    ~Queue()
    {
        delete [] Q;
    };
    void enqueue(Node *x);
    Node * dequeue();
    int isEmpty();
};

void Queue::enqueue(Node *x)
{
    if((rear+1%size)==front){
        cout<<"Queue is Full:\n";
    }
    else
    {
        rear = (rear+1)%size;
        Q[rear]=x;
    }
}

Node * Queue::dequeue()
{
    Node *x=NULL;
    if(rear == front){
        cout<<"Queue is empty";
    }
    else
    {
        front = (front+1)%size;
        x=Q[front];
    }
    return(x);
}

int Queue::isEmpty()
{
    return(front==rear);
}

class Tree
{
    public:
    Node *root;
    public:
     Tree(){
         root=NULL;
     }
      void Tcreate();
      void preorder(Node *p);
};


void Tree::Tcreate()
{
    int x;
    Queue q;
    Tree a;
    Node *p,*t;
    cout<<"Enter the root value:"<<endl;
    cin>>x;
    root = new Node;
    root->data = x;
    root->left = root->right = NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter the left cild of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->left=t->right=NULL;
            p->left=t;
            q.enqueue(t);
        }
        cout<<"Enter the right cild of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->left=t->right=NULL;
            p->right=t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
    
}
int main()
{
   Tree obj;
   obj.Tcreate();
   obj.preorder(obj.root);
   return(0);
}





