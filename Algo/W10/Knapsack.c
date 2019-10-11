#include<stdio.h>
#include<stdlib.h>
int max(int a ,int b){
    return a>b?a:b;
}
int knapsack(int v[], int w[], int m, int W){
    int F[m+1][W+1];
    for(int i = 0;i<=m;i++)
        F[i][0] = 0;
    for(int i = 0;i<=W;i++){
        F[0][i] = 0;
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=W;j++){
            if(j-w[i]>=0)
                F[i][j] = max(F[i-1][j], v[i]+F[i-1][j-w[i]]);
            else
                F[i][j] = F[i-1][j];  
        }
        
    }
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=W;j++){
            printf("%d\t", F[i][j]);
        }
        printf("\n");
    }
    return F[m][W];
}
void main(){
    int m, W;
    printf("Number of items?\n");
    scanf("%d", &m);
    int v[m+1], w[m+1];
    printf("Value\tWeight\n");
    for(int i = 1;i<=m;i++){
        scanf("%d", &v[i]);
        scanf("%d", &w[i]);
    }
    printf("\nEnter maximum capacity:\n");
    scanf("%d", &W);
    printf("Optimal solution: %d\n", knapsack(v, w, m, W));
}