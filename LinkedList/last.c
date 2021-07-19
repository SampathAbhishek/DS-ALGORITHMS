#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int a[],int n)
{
    int i;
    struct Node *last,*t;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next=NULL;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

struct Node * insert(struct Node *p,int x)
{
    struct Node *t,*q;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(p == NULL)
    {
        t->next=NULL;
        p=t;
        return(p);
    }
    else
    {
        q=p;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=t;
        t->next=NULL;
    }
    return(p);
}

void display(struct Node *p)
{
    while(p)
    {
        printf("->%d",p->data);
        p=p->next;
    }
}
int main()
{
    int a[9]={10,20,30,40,50,60,70,80,90};
    for(int i=0;i<9;i++)
    {
        head = insert(head,a[i]);
    }
    printf("Linked list created using inertion at the last:\n");
    display(head);
}
