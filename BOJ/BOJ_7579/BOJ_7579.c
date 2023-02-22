#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int memory[101];
int cost[101];
int dp[10001];

int main() {
	int N, M;

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 10000; j >= 0; j--) {
			if (j < cost[i]) {
				break;
			}
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}

	for (int i = 0; i <= 10000; i++)
		if (dp[i] >= M) {
			printf("%d", i);
			break;
		}

	return 0;
}