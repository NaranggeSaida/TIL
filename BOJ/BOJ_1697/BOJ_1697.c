#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int visit[100001] = { 0, };
int queue[10000001][2] = { 0, };
int head = 0;
int tail = 0;

int main(void) {
	int N, K;
	int ans = 10000000;

	scanf("%d %d", &N, &K);

	queue[tail][0] = N;
	queue[tail][1] = 0;
	tail++;

	while (head < tail) {
		int x = queue[head][0];
		int num = queue[head][1];
		head++;

		if (x == K) {
			ans = num;
			break;
		}

		if (x - 1 >= 0 && !visit[x - 1]) {
			queue[tail][0] = x - 1;
			queue[tail][1] = num + 1;
			tail++;
			visit[x - 1] = 1;
		}

		if (x + 1 <= 100000 && !visit[x + 1]) {
			queue[tail][0] = x + 1;
			queue[tail][1] = num + 1;
			tail++;
			visit[x + 1] = 1;
		}

		if (x * 2 <= 100000 && !visit[x * 2]) {
			queue[tail][0] = x * 2;
			queue[tail][1] = num + 1;
			tail++;
			visit[x * 2] = 1;
		}
	}

	printf("%d", ans);

	return 0;
}