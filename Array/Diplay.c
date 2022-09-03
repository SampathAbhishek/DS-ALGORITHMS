#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main()
{
    int n;
    struct Array arr;
    printf("Enter the size of Array:\n");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    printf("Enter the no of elements to be inserted:\n");
    scanf("%d",&n);
    arr.length=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
        arr.length++;
    }
    display(arr.A,arr.length);
    return 0;
}
