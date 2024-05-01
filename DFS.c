#include<stdio.h>

int graph[101][101];
int visited[101]={0};

int sum = 0;

void DFS(int cur, int n) {
    int i;
    visited[cur] = 1;
    for(i=1;i<=n;i++){
        if(graph[cur][i] == 1 && visited[i] == 0){
            visited[i]=1;
            sum++;
            DFS(i, n);
        }
    }
}

int main()
{
    int start = 1;
    int com, line;
    int a=0, b=0;

    for(int i=1;i<=101;i++){
        for(int j=1;j<=101;j++){
            graph[i][j] = 0;
        }
    }
    
    scanf("%d", &com);
    scanf("%d", &line);

    for(int i=0;i<line;i++){
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(start,101);

    printf("%d", sum);

    return 0;
}
