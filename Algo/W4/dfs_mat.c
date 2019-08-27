#include "graph.h"

int main ()
{
    int v=4;
    //printf ("Enter v:\t");
    //scanf ("%d", &v);
    //int mat [v][v];
    //initMatrix (mat, v);
    //makeMatrix (mat,v);
    //printAdjMat (mat, v);
    int mat[4][4]={{1,1,1,0}, {1,1,0,1}, {1,0,1,1}, {0,1,1,1}};
    dfs (mat, v);
    bfs (mat, v);
}