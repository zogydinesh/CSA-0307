#include <stdio.h>
#include <stdlib.h>
#define N 8
#define INF 1000000
struct Edge{int u,v,w;};

struct Node { int v; int d; };
struct Node heap[256]; int hs=0;
void push(int v,int d){int i=++hs;while(i>1&&heap[i/2].d>d){heap[i]=heap[i/2];i/=2;}heap[i].v=v;heap[i].d=d;}
struct Node popmin(void){struct Node out=heap[1],last=heap[hs--];int i=1,child;while((child=i*2)<=hs){if(child<hs&&heap[child+1].d<heap[child].d)child++;if(last.d<=heap[child].d)break;heap[i]=heap[child];i=child;}heap[i]=last;return out;}
int heap_dijkstra(struct Edge e[],int m,int result[N]){for(int i=0;i<N;i++)result[i]=INF;hs=0;result[0]=0;push(0,0);while(hs){struct Node cur=popmin();int u=cur.v;if(cur.d!=result[u])continue;for(int k=0;k<m;k++){int v=-1;if(e[k].u==u)v=e[k].v;else if(e[k].v==u)v=e[k].u;if(v>=0&&cur.d+e[k].w<result[v]){result[v]=cur.d+e[k].w;push(v,result[v]);}}}return result[N-1];}

int main(void){struct Edge e[]={{0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5},{3,4,3},{4,5,2},{5,6,1},{6,7,2},{4,7,8}};int m=sizeof(e)/sizeof(e[0]);int d[N],used[N]={0};for(int i=0;i<N;i++)d[i]=INF;d[0]=0;for(int z=0;z<N;z++){int u=-1;for(int i=0;i<N;i++)if(!used[i]&&(u<0||d[i]<d[u]))u=i;if(u<0||d[u]==INF)break;used[u]=1;for(int k=0;k<m;k++){int v=-1;if(e[k].u==u)v=e[k].v;if(e[k].v==u)v=e[k].u;if(v>=0&&d[u]+e[k].w<d[v])d[v]=d[u]+e[k].w;}}printf("Array Dijkstra distance 0->7 = %d\n",d[7]);
 int f[N][N];for(int i=0;i<N;i++)for(int j=0;j<N;j++)f[i][j]=(i==j?0:INF);for(int k=0;k<m;k++)f[e[k].u][e[k].v]=f[e[k].v][e[k].u]=e[k].w;for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(f[i][k]+f[k][j]<f[i][j])f[i][j]=f[i][k]+f[k][j];printf("Floyd-Warshall distance 0->7 = %d\n",f[0][7]);int hd[N];printf("Heap Dijkstra distance 0->7 = %d\n",heap_dijkstra(e,m,hd));
 int blocked[5][7]={{0,0,0,0,0,0,0},{0,1,1,1,0,1,0},{0,0,0,0,0,1,0},{1,1,1,1,0,0,0},{0,0,0,0,0,0,0}};int dist[35],open[35]={0},closed[35]={0},sr=0,sc=0,gr=4,gc=6;for(int i=0;i<35;i++)dist[i]=INF;int s=0,goal=34;dist[s]=0;open[s]=1;int expanded=0;while(1){int u=-1,best=INF;for(int i=0;i<35;i++)if(open[i]){int r=i/7,c=i%7, h=abs(r-gr)+abs(c-gc),score=dist[i]+h;if(score<best)best=score,u=i;}if(u<0)break;if(u==goal)break;open[u]=0;closed[u]=1;expanded++;int dr[]={-1,1,0,0},dc[]={0,0,-1,1};for(int k=0;k<4;k++){int r=u/7+dr[k],c=u%7+dc[k];if(r<0||r>=5||c<0||c>=7||blocked[r][c])continue;int v=r*7+c;if(dist[u]+1<dist[v])dist[v]=dist[u]+1;if(!closed[v])open[v]=1;}}printf("A* grid shortest steps = %d\n",dist[goal]);printf("A* expanded vertices (excluding goal) = %d\n",expanded);return 0;}