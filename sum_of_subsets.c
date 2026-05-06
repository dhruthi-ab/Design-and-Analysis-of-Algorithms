#include <stdio.h>
#include <stdlib.h>
int w[10],x[10],d,n;

void sum_of_subsets(int s,int k,int r)
{
    int i;
    static int count=1;
    x[k]=1;
    if(w[k]+s==d)
    {
        printf("\n solution %d = ",count++);
        for(i=1;i<=k;i++)
        {
            if(x[i]==1)
                printf("%d \t",w[i]);
        }
        printf("\n");
    }
    else if (s+w[k] + w[k+1] <=d)
        sum_of_subsets(s+w[k],k+1,r-w[k]);
    if ((s+r-w[k]>=d) && (s+w[k]<=d))
    {
        x[k]=0;
        sum_of_subsets(s,k+1,r-w[k]);
    }
}
int main()
{
    int i,sum=0;
    printf("\n read no. of elements:");
    scanf("%d",&n);
    printf("\n read elements in ascending order \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
    }
    printf("\n read value for d:");
    scanf("%d",&d);
    sum_of_subsets(0,1,sum);
    return 0;
}
