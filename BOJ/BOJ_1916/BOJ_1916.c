#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int graph[1001][1001];
int dist[1001];
int visited[1001];

int main(void) {
    int N, M, start, end;

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        if (graph[u][v] > w) {
            graph[u][v] = w;
        }
    }
    
    scanf("%d %d", &start, &end);

    for (int i = 1; i <= N; i++) {
        dist[i] = graph[start][i];
    }

    visited[start] = 1;

    for (int i = 1; i < N; i++) {
        int min_dist = INT_MAX;
        int current;

        for (int j = 1; j <= N; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                current = j;
            }
        }

        visited[current] = 1;

        for (int j = 1; j <= N; j++) {
            if (!visited[j] && graph[current][j] != INT_MAX) {
                int new_dist = dist[current] + graph[current][j];

                if (new_dist < dist[j]) {
                    dist[j] = new_dist;
                }
            }
        }
    }

    printf("%d", dist[end]);

    return 0;
}
