#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q)
{
   q->size = 10;
   q->front = q->rear = 0;
   q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node *x=NULL;
    if(q->rear == q->front){
        printf("Queue is full\n");
    }
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return(x);
}
int isEmpty(struct Queue q)
{
    if(q.rear == q.front){
        return(1);
    }
    else
    {
        return(0);
    }
}

void Tcreate()
{
    int i,x;
    struct Queue q;
    struct Node *t,*p;
    create(&q);
    printf("Enter the root data:\n");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->left=root->right=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
           t = (struct Node *)malloc(sizeof(struct Node));
           t->data = x;
           t->left = t->right = NULL;
           p->left=t;
           enqueue(&q,t);
        }
        printf("Enter the right child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
           t = (struct Node *)malloc(sizeof(struct Node));
           t->data = x;
           t->left = t->right = NULL;
           p->right=t;
           enqueue(&q,t);
        }
    }

}
void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
//same but using iteration ,helps reduce cost due to recursion.
void iterativepreorder(struct Node *t)
{
    struct Stack st;
    screate(&st);
    while(t!=NULL || !isEmpty(st))
    {
        if(t!=NULL)
        {
        printf("%d ",t->data);
        push(&st,t);
        t=t->lchild;
        }
        else
        {
            t=pop(&st);
            t=t->rchild;
        }
    }
    
}
int main()
{
    Tcreate();
    printf("The preorder traversal of the tree is as follows:\n");
    preorder(root);
    return(0);
}
