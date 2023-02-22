#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int N, a, b;
	int matrix[500][2];
	int dp[500][500];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &matrix[i][0], &matrix[i][1]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			a = j;
			b = i + j;
			if (a == b) {
				dp[a][b] = 0;
			}
			else {
				dp[a][b] = 1000000000;
				for (int k = a; k < b; k++) {
					dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
				}
			}
		}
	}

	printf("%d", dp[0][N - 1]);

	return 0;
}