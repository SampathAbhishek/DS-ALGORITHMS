#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void create_queue(struct Queue *qt,int x)
{
    qt->size=x;
    qt->front=qt->rear=-1;
    qt->Q=(int *)malloc(qt->size*sizeof(int));
}

void enqueue(struct Queue *qt,int x)
{
    if(qt->rear==qt->size-1)
    {
        printf("Queue full");
    }
    else
    {
        qt->rear++;
        qt->Q[qt->rear]=x;
    }
}

int dequeue(struct Queue *qt)
{
    int x;
    if(qt->front==qt->rear){
        printf("Queue empty");
    }
    else
    {
        qt->front++;
        x=qt->Q[qt->front];
    }
    return(x);
}

void display(struct Queue qt)
{
    int i=qt.front+1;
    for(;i<=qt.rear;i++)
    {
        printf("%d ",qt.Q[i]);
    }
}

int main()
{
    struct Queue q;
    create_queue(&q,15);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);
    return(0);
}


