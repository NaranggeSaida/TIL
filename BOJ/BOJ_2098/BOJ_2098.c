#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 1000000000

int N;
int dp[16][1 << 16];
int map[16][16] = { 0, };

int dfs(int cur, int visit) {
	if (visit == (1 << N) - 1) {
		if (map[cur][0] == 0) {
			return INF;
		}
		else {
			return map[cur][0];
		}
	}

	if (dp[cur][visit] != -1) {
		return dp[cur][visit];
	}
	else {
		dp[cur][visit] = INF;
	}

	for (int i = 0; i < N; i++) {
		if (map[cur][i] == 0 || (visit & (1 << i)) == (1 << i)) {
			continue;
		}
		else {
			dp[cur][visit] = MIN(dp[cur][visit], map[cur][i] + dfs(i, visit | 1 << i));
		}
	}

	return dp[cur][visit];
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));

	printf("%d", dfs(0, 1));

	return 0;
}