#include<stdio.h>
void binary_search(int x,int *p,int n)
{
    int m=n/2;
    if(x==*(p+m))
    {
        printf("present\n");
        return;
    }
    else if (x<*(p+m))
    {
        int a[m];
        int *q;
        q=&a[0];
        for(int i=0;i<m;i++)
        {
            *(q+i)=*(p+i);
        }
        return binary_search(x,q,m);
    }
    else if(x>*(p+m))
    {
        int a[m];
        int *q;
        q=&a[0];
        for(int i=m;i<2*m;i++)
        {
            *(q+i)=*(p+i);
        }
        return binary_search(x,q,m);
    }
    else
    {
        printf("absent\n");
    }
}
void main()
{
    int *p;
    int n;
    int x;
    int arr[n];
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("enter numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    p=&arr[0];
    printf("enter number to search\n");
    scanf("%d",&x);
    binary_search(x,p,n);
}
    
