#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int x[10],count;
void print(int n)
{
    int i,j;
    printf("\n solution=%d \n",count++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if (x[j]==i)
                printf("\tQ");
            else
                printf("\t -");
        }
        printf("\n");
    }
}

int place(k,i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if ((x[j]==i) || abs(x[j]-i)==abs(j-k))
            return 0;
    }
    return 1;
}

void n_queens(int k,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if (place(k,i))
        {
            x[k]=i;
            if(k==n)
                print(n);
            else
                n_queens(k+1,n);
        }
    }
}

int main()
{
    int n;
    printf("\n read no. of queens:");
    scanf("%d",&n);
    if((n==1) || (n==2) || (n==3))
        printf("\n No solution");
    else
        n_queens(1,n);
    return 0;
}
