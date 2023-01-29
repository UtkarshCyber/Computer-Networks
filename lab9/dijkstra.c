#include<stdio.h>
void dijkstras();
int c[10][10],n,src;
void main()
{
int i,j;
printf("\nEnter the no of vertices :\t");
scanf("%d",&n);
printf("\nEnter the cost matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&c[i][j]);
  }
 }
 printf("\nenter the source node:\t");
 scanf("%d",&src);
 dijkstras();
 getch();
}

void dijkstras()
{
int vis[10],dist[10],u,j,count,min;
for(j=1;j<=n;j++)
  {
   dist[j]=c[src][j];
  }
  for(j=1;j<=n;j++)
  {
   vis[j]=0;
  }
  dist[src]=0;
  vis[src]=1;
  count=1;
  while(count!=n)
  {
   min=9999;
   for(j=1;j<=n;j++)
   {
    if(dist[j]<min&&vis[j]!=1)
    {
     min=dist[j];
     u=j;
    }
   }
   vis[u]=1;
   count++;
   for(j=1;j<=n;j++)
   {
    if(min+c[u][j]<dist[j]&&vis[j]!=1)
    {
     dist[j]=min+c[u][j];
    }
   }
  }
  printf("\nthe shortest distance is:\n");
  for(j=1;j<=n;j++)
  {
   printf("\n%d----->%d=%d",src,j,dist[j]);
  }
}

/*OUTPUT:
Enter the num of vertices: 	5
Enter the cost matrix:
9999 3 9999 7 9999
3 9999 4 2 9999
9999 4 9999 5 6
7 2 5 9999 4
9999 9999 6 4 9999
Enter the source node: 	1
The shortest distance is:
1----->1 = 0
1----->2 = 3
1----->3 = 7
1----->4 = 5
1----->5 = 9
*/
