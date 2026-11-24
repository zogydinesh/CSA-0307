#include <stdio.h>
#include <stdlib.h>
#define V 5
struct Edge{int u,v,w;};
int cmp(const void*a,const void*b){return ((struct Edge*)a)->w-((struct Edge*)b)->w;}
int find(int p[],int x){while(p[x]!=x){p[x]=p[p[x]];x=p[x];}return x;}
int main(void){int c[V][V]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};int key[V],par[V],in[V]={0},total=0;for(int i=0;i<V;i++)key[i]=999,par[i]=-1;key[0]=0;for(int z=0;z<V;z++){int u=-1;for(int i=0;i<V;i++)if(!in[i]&&(u<0||key[i]<key[u]))u=i;in[u]=1;total+=key[u];for(int v=0;v<V;v++)if(c[u][v]&&!in[v]&&c[u][v]<key[v])key[v]=c[u][v],par[v]=u;}puts("Prim selected edges:");for(int v=1;v<V;v++)printf("%d-%d (%d)\n",par[v],v,c[par[v]][v]);printf("Prim total cost = %d lakh\n",total);
 struct Edge e[]={{0,1,2},{1,2,3},{0,3,6},{1,4,5},{1,3,8},{2,4,7},{3,4,9}};int m=sizeof(e)/sizeof(e[0]),p[V];for(int i=0;i<V;i++)p[i]=i;qsort(e,m,sizeof(e[0]),cmp);total=0;puts("Kruskal selected edges:");for(int i=0;i<m;i++){int a=find(p,e[i].u),b=find(p,e[i].v);if(a!=b){p[a]=b;printf("%d-%d (%d)\n",e[i].u,e[i].v,e[i].w);total+=e[i].w;}}printf("Kruskal total cost = %d lakh\n",total);return 0;}