#include <stdio.h>
#include <stdlib.h>
int w[10],x[10],d;
void sum_subset(int s,int k,int r)
{
    int i;
    static int b=1;
    x[k]=1;
    if(w[k]+s==d)
    {
        printf("\nSolution %d=",b++);
        for(i=1;i<=k;i++)
        {
            if(x[i]==1)
                printf("%d\t",w[i]);
        }
    }
    else if(s+w[k]+w[k+1]<=d)
        sum_subset(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=d && s+w[k]+1<=d)
    {
        x[k]=0;
        sum_subset(s,k+1,r-w[k]);
    }
    if(b==1)
    {
        printf("\n No solutions");
        exit(0);
    }
}
int main()
{
   int i,n,sum=0;
   printf("\n Read number of elements");
   scanf("%d",&n);
   printf("\nRead elements in order\n");
   for(i=1;i<=n;i++)
   {
       scanf("%d",&w[i]);
       sum=sum+w[i];

   }
   printf("\nRead value for d");
   scanf("%d",&d);
   sum_subset(0,1,sum);
   return 0;
}
