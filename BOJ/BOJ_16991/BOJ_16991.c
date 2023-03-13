#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 1000000000

int N;
double dp[16][1 << 16];
double map[16][2] = { 0, };
double weight[16][16] = { 0, };

double dfs(int cur, int visit) {
	if (visit == (1 << N) - 1) { 
		return weight[cur][0];
	}

	if (dp[cur][visit] != 0) {
		return dp[cur][visit];
	}
	else {
		dp[cur][visit] = INF;
	}

	for (int i = 0; i < N; i++) {
		if ((visit & (1 << i)) == (1 << i)) {
			continue;
		}
		else {
			dp[cur][visit] = MIN(dp[cur][visit], weight[cur][i] + dfs(i, visit | 1 << i));
		}
	}

	return dp[cur][visit];
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &map[i][0], &map[i][1]);
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				weight[i][j] = 0;
			}
			else {
				weight[i][j] = sqrt(pow(map[i][0] - map[j][0], 2) + pow(map[i][1] - map[j][1], 2));
			}
		}
	}

	printf("%lf", dfs(0, 1));

	return 0;
}