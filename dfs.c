#include <stdio.h>
#include <stdlib.h>

void dfs(int A[10][10],int n, int visited[10],int source)
{
    int i;
   visited[source]=1;
   for(i=1;i<=n;i++)
   {
       if(A[source][i]==1 && visited[i]==0)
        dfs(A,n,visited,i);
   }
}
int main()
{
   int n,A[10][10],i,j,visited[10],count=0;
   printf("\n read no of nodes");
   scanf("%d",&n);
   printf("\n read adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
        scanf("%d",&A[i][j]);
   }
   for(i=1;i<=n;i++)
    visited[i]=0;
   for(i=1;i<=n;i++)
   {
       if(visited[i]==0)
       {
           dfs(A,n,visited,i);
           count++;
       }
   }
   if(count==1)
    printf("\n graph connected,%d component",count);
   else
    printf("\n Graph not connected,%d component",count);
   return 0;
}
