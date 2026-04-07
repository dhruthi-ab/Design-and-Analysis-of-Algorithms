#include <stdio.h>
#include <stdlib.h>
int s[10];
int count = 0;
void comparision_count_sort(int A[10], int n)
{
    int i,j,count[10];
    for(i=0;i<=n-1;i++)
        count[i]=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if (A[i]>A[j])
                count[i]=count[i]+1;
            else
                count[j]=count[j]+1;
        }
    }
     for(i=0;i<n;i++)
            s[count[i]]=A[i];
        return s;
}
int main()
{
    int n, i, A[10];

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    comparision_count_sort(A, n);

    printf("\nSorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }

    printf("\nTotal number of comparisons = %d", count);

    return 0;
}
