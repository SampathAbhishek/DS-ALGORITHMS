// Just shift the elemnts if given value is less than that otherwise insert it.
#include <stdio.h>

int main()
{
    int x=117,pos=0,i;
    int a[6]={10,20,30,40,50};
    i=4;
    while(a[i]>x)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    for(i=0;i<6;i++)
    {
    printf("%d ",a[i]);
    }
    return 0;
}
