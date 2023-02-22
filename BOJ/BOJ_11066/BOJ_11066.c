#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int T, K, a, b;
	int file[500];
	int sum[500];
	int dp[500][500];
	int result[500];
	int c = 0;

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &K);

		for (int i = 0; i < K; i++) {
			scanf("%d", &file[i]);
		}

		sum[0] = file[0];
		for (int i = 1; i < K; i++) {
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K - i; j++) {
				a = j;
				b = i + j;

				if (a == b) {
					dp[a][b] = 0;
				}
				else {
					dp[a][b] = 1000000000;

					for (int k = a; k < b; k++) {
						if (a == 0) {
							dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + sum[b]);
						}
						else {
							dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + sum[b] - sum[a - 1]);
						}
					}
				}
			}
		}
		result[c++] = dp[0][K - 1];
	}

	for (int i = 0; i < c; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}