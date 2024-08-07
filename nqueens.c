#include <stdio.h>
#include <stdlib.h>
int x[10];
static int b=1;
void printboard(int n)
{
    int i,j;
    printf("\n solution %d\n",b++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
                printf("Q\t");
            else
                printf("*\t");

        }
        printf("\n");
    }
}
int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    }
    return 1;
}
void nqueens(int k,int n)
{

int i;
for(i=1;i<=n;i++)
{
    if(place(k,i))
    {
        x[k]=i;
        if(k==n)
        {
            printf("\n");
            printboard(n);
        }
        else
            nqueens(k+1,n);
    }
}
}
int main()
{
   int n;
   printf("\nRead the number of Queens:");
   scanf("%d",&n);
   nqueens(1,n);
   if(b==1)
    printf("No solutions");

   return 0;
}
