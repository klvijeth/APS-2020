#include<stdio.h>
int m[10][10];
int v,source;
int visited[10]={0};
void dfs(int source)
{
    int i;
    visited[source]=1;
    for(i=0;i<v;i++)
    {
        if(m[source][i]!=0 && visited[i]==0)
        {
            printf("%d ",i);
            dfs(i);
        }
    }

}
int main()
{
    printf("Enter the number of nodes\n");
    scanf("%d",&v);
    printf("Enter the source node\n");
    scanf("%d",&source);
    printf("Enter the adjacency matrix of the graph\n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            scanf("%d",&m[i][j]);
    }
    printf("%d ",source);
    dfs(source);
}
