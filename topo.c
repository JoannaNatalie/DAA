#include <stdio.h>
#include <stdlib.h>
int topo[10],k;
void dfs(int A[10][10],int n, int visited[10],int source)
{
    int i;
   visited[source]=1;
   for(i=1;i<=n;i++)
   {
       if(A[source][i]==1 && visited[i]==0)
        dfs(A,n,visited,i);
   }
   topo[++k]=source;
}
int main()
{
   int n,A[10][10],i,j,visited[10];
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

       }
   }
   printf("\n topological ordering is\n");
   for(i=k;i>=1;i--)
    printf("%d\t",topo[i]);
   return 0;
}
