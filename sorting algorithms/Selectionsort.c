#include <stdio.h>

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

void selectionSort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)//passes
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }
        swap(&a[k],&a[i]);
    }
}

int main()
{
    int n;
    printf("Enter the total number of elements in array:\n");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    printf("Elements after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
