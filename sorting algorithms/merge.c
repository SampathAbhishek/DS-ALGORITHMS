#include<stdio.h>
#include<stdlib.h>

int * merge(int a[],int b[],int m,int n)
{
    int i=0,j=0,k=0;
    int *c;
    c = (int *)malloc((m+n)*sizeof(int));
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++){
        c[k++]=a[i++];
    }
    for(;i<n;i++){
        c[k++]=b[j++];
    }
    return(c);
}



int main()
{
    int a[5]={3,7,45,67,100};
    int b[5]={1,2,5,8,11};
    int *p=merge(a,b,5,5);
    for(int i=0;i<9;i++)
    {
        printf("%d ",p[i]);
    }
    
}
