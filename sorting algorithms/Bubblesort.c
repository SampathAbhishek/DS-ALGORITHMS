/* criteria for analysis of sort:-

1.number of comparisons - O(n^2)
2.number of swaps.- O(n^2)
3.adaptive-can be made adaptive using flag variable.By default no.
4.stable-yes.
5.Extra space-not required.

Time complexity:-
min :- O(n)(When all the lements are sorted)
max :- O(n^2)
*/
#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void BubbleSort(int a[],int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
        if(flag=0)
        {
            break;
        }
    }
}

int main()
{
    int n,i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    BubbleSort(a,n);
    printf("Elements after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return(0);
}
