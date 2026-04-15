#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n,W,w[10],p[10],i,j,V[10][10],x[10]={10};
    printf("\n Read number of objects:");
    scanf("%d",&n);
    printf("\n Read knapsack capacity:");
    scanf("%d",&W);
    printf("\n Read weight of objects:");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("\n Read the profits of object:");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                V[i][j]=0;
            else if(j-w[i]<0)
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+p[i]);
                printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
    i=n;
    j=W;
    while(i!=0 && j!=0)
    {
        if(V[i][j]!=V[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i=i-1;
    }
    printf("\n the maximum profit is %d",V[n][W]);
    printf("\n object\t weight\t profit\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
            printf("%d\t %d\t %d\n",i,w[i],p[i]);
    }
    return 0;
}
