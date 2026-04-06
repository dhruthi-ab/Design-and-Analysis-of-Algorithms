#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int table[SIZE];

void shifttable(char P[10])
{
    int i, m;
    m=strlen(P);
    for(i=0;i<SIZE;i++)
        table[i]=m;
    for(i=0;i<=m;i++)
        table[P[i]]=m-1-i;
}
int horspool(char T[50],char P[10])
{
    int i, m,n,k;
    n=strlen(T);
    m=strlen(P);
    shifttable(P);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<m && P[m-1-k]==T[i-k])
            k=k+1;
        if(k==m)
            return i-m+1;
        else
            return i+table[T[i]];
    }
    return -1;
}

int main()
{
   char T[50],P[10];
   int pos=-1;
   printf("\n Read text:\n");
   scanf("%s",T);
   printf("\n Read pattern:\n");
   scanf("%s",P);
   pos=horspool(T,P);
   if(pos==-1)
    printf("\n pattern not found");
   else
    printf("\n pattern found with %d\n",pos);
   return 0;
}
