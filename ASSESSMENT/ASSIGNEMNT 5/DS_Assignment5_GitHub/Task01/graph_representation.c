#include <stdio.h>
#define V 5
int main(void) {
    int matrix[V][V] = {0};
    int edges[][2]={{0,1},{0,2},{1,3},{2,3},{3,4}};
    int E=sizeof(edges)/sizeof(edges[0]);
    for(int i=0;i<E;i++){int u=edges[i][0],v=edges[i][1];matrix[u][v]=matrix[v][u]=1;}
    puts("Undirected road graph: 5 junctions, 5 road segments");
    puts("Adjacency matrix:");
    for(int i=0;i<V;i++){for(int j=0;j<V;j++)printf("%d ",matrix[i][j]);putchar('\n');}
    printf("\nVertices = %d, Edges = %d\n",V,E);
    puts("Representation decision: adjacency list / CSR for a large sparse road network.");
    return 0;
}