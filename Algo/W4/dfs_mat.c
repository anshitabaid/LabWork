#include "graph.h"

int main ()
{
    int v;
    int ** mat;
    printf ("Enter v:\t");
    scanf ("%d", &v);
    mat = initMatrix (v);
    dfs (mat, v);
}