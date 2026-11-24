#include <stdio.h>
#define V 7
int g[V][V]={{0,1,1,0,0,0,0},{1,0,0,1,1,0,0},{1,0,0,0,0,1,0},{0,1,0,0,0,0,0},{0,1,0,0,0,0,0},{0,0,1,0,0,0,1},{0,0,0,0,0,1,0}};
void bfs(int s){int q[V],seen[V]={0},h=0,t=0;seen[s]=1;q[t++]=s;while(h<t){int u=q[h++];printf("%d ",u);for(int v=0;v<V;v++)if(g[u][v]&&!seen[v])seen[v]=1,q[t++]=v;}puts("");}
void dfs(int u,int seen[V]){seen[u]=1;printf("%d ",u);for(int v=0;v<V;v++)if(g[u][v]&&!seen[v])dfs(v,seen);}
int main(void){int seen[V]={0};printf("BFS from 0: ");bfs(0);printf("DFS from 0: ");dfs(0,seen);puts("");return 0;}