#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        printf("%d ",arr->A[i]);
    }
    printf("\n");
}

void append(struct Array *arr,int x){
    arr->A[arr->length]=x;
    arr->length++;
}

void insert_at_index(struct Array *arr,int index,int x){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
}

int main()
{
    int n;
    struct Array arr;
    printf("Enter size of array:\n");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;
    display(&arr);
    printf("43 appended:\n");
    append(&arr,43);
    display(&arr);
    printf("2 inserted at 1(i.e.) at second position:\n");
    insert_at_index(&arr,1,2);
    display(&arr);
    return 0;
}
