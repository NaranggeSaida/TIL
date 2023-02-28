#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 100000000

int main(void) {
    int a, b, c, n, m;
    int map[100][100] = { 0, };

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                map[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        map[a - 1][b - 1] = MIN(c, map[a - 1][b - 1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                map[j][k] = MIN(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == INF) {
                printf("0 ");
                continue;
            }
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}