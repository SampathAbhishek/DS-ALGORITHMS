#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Stack overflow");
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x;
    struct Node *p;
    if(top==NULL){
        printf("Stack underflow");
    }
    else
    {
        p=top;
        x = p->data;
        top=top->next;
        free(p);
        return(x);
    }
}

int peek(struct Node *p,int pos)
{
    int i;
    for(i=0;i<pos;i++)
    {
        p=p->next;
    }
    return(p->data);
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int isEmpty()
{
    return top==NULL ? 1:0;
}
int stackTop()
{
    return(top->data);
}
int isOperand(char x)
{
    if(x=='+'||x=='*'||x=='/'||x=='-'){
        return(0);
    }
    else
    {
        return(1);
    }
}
int precedence(char x)
{
    if(x=='+'||x=='-')
    {
        return(1);
    }
    else if(x=='*'||x=='/')
    {
        return(2);
    }
    return(0);
}
int evaluate(char * infix)
{
    int i;
    for(i=0;infix[i]!='\0';i++)
    {
        if(isOperand(infix[i]))
        {
            push(infix[i]-'0');
        }
        else
        {
            int x2=pop();
            int x1 =pop();
            switch(infix[i])
            {
                case '+':
                  push(x1+x2);
                  break;
                case '-':
                  push(x1-x2);
                  break;
                case '*':
                  push(x1*x2);
                  break;
                case '/':
                  push(x1/x2);
                  break;
            }
        }
    }
    return (pop());
    
}



int main()
{
    char *expr ="35*62/+4-";
    int x=evaluate(expr);
    printf("%d",x);
    return(0);
}
