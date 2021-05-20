#include<iostream>
using namespace std;
//Stack created using linked list.
class Node
{
public:
    char data;
    Node *next;
};
//push,pop,isempty,display and isBalanced functions are defined under stack adt.
class Stack
{
  private:
    Node *top;
  public:
    Stack(){top=NULL;}
    void push(char x);
    char pop();
    void display();
    int isBalanced(const char *expression);
    int isEmpty();
};

void Stack:: push(char x)
{
    Node *t;
    t = new Node;
    if(t==NULL){
        cout<<"Stack overflow "<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop()
{
    char x = -1;
    Node *p;
    if(top == NULL){
        cout<<"Stack underflow "<<endl;
    }
    else
    {
        x = top->data;
        p = top;
        top = top->next;
        delete p;
    }
    return(x);
}

void Stack::display()
{
    Node *p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Stack::isEmpty()
{
    if(top == NULL){
        return(1);
    }
    return(0);
}

int Stack::isBalanced(const char *expression)
{
    int i;
    for(i=0;expression[i]!='\0';i++)
    {
      //check if opening brackets encounter.
        if(expression[i]=='['||expression[i]=='{'||expression[i]=='(')
        {
            push(expression[i]);
        }
      /*if closing bracket encounters.
      follow these two steps:-
      step 1 : check if stack is empty.if it is empty return 0 else pop.
      // step 2: after traversing the entire expression if stack is empty return true else return false i.e. 0. 
       */
        else if(expression[i]==']'||expression[i]=='}'||expression[i]==')')
        {
            if(isEmpty()){
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if(isEmpty()){
        return(1);
    }
    else
    {
        return(0);
    }
}
//The main driver function
int main()
{
    const char *ex = "{[(a+b)*(c+d)/e]}";
    Stack st;
    (st.isBalanced(ex))? cout<<ex<<" is balanced ":cout<<ex<<" is not balanced ";
    return(0);
}
