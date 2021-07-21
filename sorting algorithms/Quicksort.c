/*Quick sort works on the principle of divide and conquer.
So,we divide the list in such a way that,all the elements to the left of the pivot are smaller 
than pivot and right are greater.
We follow this procedure recursively until low<height of series.
*/
#include <stdio.h>
#include<stdint.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
        swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&a[l],&a[j]);
    return(j);
}

void Quicksort(int a[],int l,int h)
{
    int index;
    if(l<h)
    {
        index = partition(a,l,h);
        Quicksort(a,l,index);
        Quicksort(a,index+1,h);
    }
}
int main()
{
    int n;
    printf("Enter the total number of elements in array:\n");
    scanf("%d",&n);
    int a[n+1],i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n]=INT32_MAX;
    Quicksort(a,0,n);
    printf("Elements after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
