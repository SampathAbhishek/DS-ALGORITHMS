#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p = (int *)malloc(5*sizeof(int));
    p[0]=10;p[1]=20;p[2]=30;p[3]=40;p[4]=50;
    for(int i=0;i<5;i++){
        printf("%d ",p[i]);
    }
    int *q = (int *)malloc(10*sizeof(int));
    
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    q[5]=60;q[6]=70;q[7]=80;q[8]=90;q[9]=100;
    free(p);
    p=q;
    q = NULL;
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",p[i]);
    }
    return 0;
}
