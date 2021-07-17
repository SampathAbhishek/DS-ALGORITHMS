#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

void IterativeInsert(int x)
{
    struct Node *p,*r,*t=root;
    if(t==NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        p->left=p->right=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r = t;
        if(x < t->data)
        {
            t=t->left;
        }
        else if(x > t->data)
        {
            t=t->right;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data=x;
    p->left=p->right=NULL;
    if(x<r->data)
    {
        r->left=p;
    }
    else
    {
        r->right=p;
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

int main()
{
    IterativeInsert(10);
    IterativeInsert(30);
    IterativeInsert(9);
    IterativeInsert(11);
    IterativeInsert(40);
    inorder(root);
}
