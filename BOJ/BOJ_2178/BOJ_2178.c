#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int queue[10000][2] = { 0, };
int visit[100][100] = { 0, };
int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };
int head = 0;
int tail = 0;
char map[101][101];

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	visit[0][0] = 1;
	queue[tail][0] = 0;
	queue[tail++][1] = 0;

	while (head < tail) {
		int x = queue[head][0];
		int y = queue[head++][1];

		for (int i = 0; i < 4; i++) {
			if (x + xx[i] >= 0 && x + xx[i] < N && y + yy[i] >= 0 && y + yy[i] < M && map[x + xx[i]][y + yy[i]] == '1' && visit[x + xx[i]][y + yy[i]] == 0) {
				visit[x + xx[i]][y + yy[i]] = visit[x][y] + 1;
				queue[tail][0] = x + xx[i];
				queue[tail++][1] = y + yy[i];
			}
		}
	}

	printf("%d", visit[N - 1][M - 1]);

	return 0;
}