#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int triangle[500][500] = { 0, };
int dp[500][500] = { 0, };

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		dp[N - 1][i] = triangle[N - 1][i];
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = MAX(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}

	printf("%d", dp[0][0]);

	return 0;
}