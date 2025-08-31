#include<stdio.h>
#include<stdlib.h>

void DFS(int a[7][7], int visit[], int vertx) {
    printf("%d ", vertx);
    visit[vertx] = 1;

    for(int j=0; j<7; j++) {
        if(a[vertx][j] == 1 && visit[j] == 0) {
            DFS(a, visit, j);
        }
    }
}

int main() {
    int visited[7] = {0,0,0,0,0,0,0};
    int i;
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("The elements are: ");
    i=0;
    DFS(a, visited, i);

    return 0;
}