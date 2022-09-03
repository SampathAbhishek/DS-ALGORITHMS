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
    if(index>=0 && index<=arr->length){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }
    }
    arr->A[index]=x;
    arr->length++;
}

int delete_at_index(struct Array*arr,int index){
    int x = -1;
    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return(x);
    }
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
    printf("200 inserted at 4(i.e.) at fourth position:\n");
    insert_at_index(&arr,4,200);
    display(&arr);
    int del = delete_at_index(&arr,4);
    printf("%d is deleted\n",del);
    display(&arr);
    return 0;
}
