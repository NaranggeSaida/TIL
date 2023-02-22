#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int w[101];
int v[101];
int dp[101][100001];

int main(void) {
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[N][K]);

    return 0;
}