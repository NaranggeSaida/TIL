#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a ,b) (((a) < (b)) ? (a) : (b))

int graph[801][801] = { 0, };

int dijkstra(int start, int end, int N) {
	int dist[801] = { 0, };
	int visit[801] = { 0, };

	visit[start] = 1;

	for (int i = 1; i <= N; i++) {
		dist[i] = graph[start][i];
	}

	for (int i = 1; i < N; i++) {
		int current;
		int min = 100000000;

		for (int j = 1; j <= N; j++) {
			if (!visit[j] && dist[j] < min) {
				min = dist[j];

				current = j;
			}
		}

		visit[current] = 1;

		for (int j = 1; j <= N; j++) {
			if (!visit[j] && dist[j] > dist[current] + graph[current][j]) {
				dist[j] = dist[current] + graph[current][j];
			}
		}
	}

	return dist[end];
}

int main(void) {
	int N, E, u, v, ans;

	scanf("%d %d", &N, &E);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = 100000000;
			}
		}
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);

		if (graph[a][b] > c) {
			graph[a][b] = c;
		}

		if (graph[b][a] > c) {
			graph[b][a] = c;
		}
	}

	scanf("%d %d", &u, &v);

	if (MIN(dijkstra(1, u, N) + dijkstra(u, v, N) + dijkstra(v, N, N), dijkstra(1, v, N) + dijkstra(v, u, N) + dijkstra(u, N, N)) >= 100000000) {
		ans = -1;
	}
	else {
		ans = MIN(dijkstra(1, u, N) + dijkstra(u, v, N) + dijkstra(v, N, N), dijkstra(1, v, N) + dijkstra(v, u, N) + dijkstra(u, N, N));
	}

	printf("%d", ans);

	return 0;
}