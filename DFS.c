#include<stdio.h>
int adj[10][10]={0},visited[10]={0},n;
void dfs(int node)
{
	int i;
	visited[node]=1;
	printf("%d ",node+1);
	for(i=0;i<n;i++)
	{
		if(adj[node][i]==1 && visited[i]==0)
		dfs(i);
	}
}
int main()
{
	int e,i,v1,v2,node;
	printf("enter nos of nodes\n");
	scanf("%d",&n);
	printf("enter nos of edges\n");
	scanf("%d",&e);
	printf("enter edge details\n");
	for(i=0;i<e;i++)
	{
		printf(" enter edge\n");
		scanf("%d %d",&v1,&v2);
		adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
	}
	printf("enter starting vertex\n");
	scanf("%d",&node);
	dfs(node-1);
	return 0;
}
