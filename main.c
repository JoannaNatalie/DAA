#include <stdio.h>
#include <stdlib.h>
int max(int A,int B)
{
    if(A>B)
        return A;
    else
        return B;
}
int main()
{
  int n,w[10],v[10],V[10][10],W,i,j,x[10]={0};
  printf("\nRead no of objects:");
  scanf("%d",&n);
  printf("\nRead weights of the objects:\n");
  for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
  printf("\nRead profits of the objects:\n");
  for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
  printf("\nRead knapsack capacity:");
  scanf("%d",&W);
  for(i=0;i<=n;i++)
  {
      for(j=0;j<=W;j++)
      {
          if(i==0||j==0)
            V[i][j]=0;
          else if(j<w[i])
            V[i][j]=V[i-1][j];
          else
            V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
          printf("%d\t",V[i][j]);
      }
      printf("\n");
  }
  printf("\nThe max profit is %d",V[n][W]);
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
  printf("\nObjects included are:\n");
  for(i=1;i<=n;i++)
  {
      if(x[i]==1)
        printf("\n %d object is included",i);
  }
  return 0;
}
