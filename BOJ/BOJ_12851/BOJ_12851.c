#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int visit[100001] = { 0, };
int queue[10000001][2] = { 0, };
int head = 0;
int tail = 0;

int main(void) {
	int N, K;
	int ans1 = 10000000;
	int ans2 = 0;

	scanf("%d %d", &N, &K);

	queue[tail][0] = N;
	queue[tail][1] = 0;
	tail++;

	while (head < tail) {
		int x = queue[head][0];
		int num = queue[head][1];
		head++;

		visit[x] = 1;

		if (ans1 < num) {
			break;
		}

		if (x == K) {
			ans1 = num;
			ans2++;
			continue;
		}

		if (x - 1 >= 0 && !visit[x - 1]) {
			queue[tail][0] = x - 1;
			queue[tail][1] = num + 1;
			tail++;
		}

		if (x + 1 <= 100000 && !visit[x + 1]) {
			queue[tail][0] = x + 1;
			queue[tail][1] = num + 1;
			tail++;
		}

		if (x * 2 <= 100000 && !visit[x * 2]) {
			queue[tail][0] = x * 2;
			queue[tail][1] = num + 1;
			tail++;
		}
	}

	printf("%d\n%d", ans1, ans2);

	return 0;
}