#include <stdio.h>
#include <stdlib.h>
void heapify(int h[10],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
                if(v>=h[j])
                    heap=1;
                else
                {
                    h[k]=h[j];
                    k=j;
                }
        }
        h[k]=v;
    }
}
void heapsort(int h[10], int n)
{
    int i,temp;
    for(i=n;i>1;i--)
    {
        temp=h[1];
        h[1]=h[i];
        h[i]=temp;
        heapify(h,i-1);
    }
}
int main()
{
    int i,n,h[10];
    printf("\n read array size:");
    scanf("%d",&n);
    printf("\n read array elements \n");
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    heapify(h,n);
    printf("\n elements after heap \n");
    for(i=1;i<=n;i++)
        printf("%d\t",h[i]);
    heapsort(h,n);
    printf("\n sorted elements are \n");
    for(i=1;i<=n;i++)
        printf("%d\t",h[i]);
    return 0;
}
