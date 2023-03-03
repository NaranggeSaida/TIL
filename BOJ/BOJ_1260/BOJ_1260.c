#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int matrix[1001][1001] = { 0, };
int visit_DFS[1001] = { 0, };
int visit_BFS[1001] = { 0, };
int queue[1000001];
int front = 0;
int rear = 0;

void DFS(int N, int V) {
	if (visit_DFS[V] == 0) {
		printf("%d ", V);

		visit_DFS[V] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (matrix[V][i] == 1 && visit_DFS[i] == 0) {
			DFS(N, i);
		}
	}

	return;
}
int is_empty() {
	if (rear == front) {
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(int n) {
	queue[rear++] = n;

	return;
}

int dequeue() {
	return(queue[front++]);
}

void BFS(int N, int V) {
	enqueue(V);

	while (!is_empty()) {
		int v = dequeue();

		if (visit_BFS[v] == 0) {
			printf("%d ", v);

			visit_BFS[v] = 1;
		}

		for (int i = 1; i <= N; i++) {
			if (matrix[v][i] == 1 && visit_BFS[i] == 0) {
				enqueue(i);
			}
		}
	}

	return;
}

int main(void) {
	int N, M, V, a, b;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		matrix[b][a] = 1;
		matrix[a][b] = 1;
	}

	DFS(N, V);
	printf("\n");
	BFS(N, V);
	
	return 0;
} 