#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define INF 1000000

int main(void) {
	int a, b, l, n, m, r, temp;
    int map[100][100] = { 0, };
    int item[100] = { 0, };
    int max_item = -1;

	scanf("%d %d %d", &n, &m, &r);

    for (int i = 0; i < n; i++) {
        scanf("%d", &item[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                map[i][j] = INF;
            }
        }
    }

	for (int i = 0; i < r; i++) {
		scanf("%d %d %d", &a, &b, &l);
        map[a - 1][b - 1] = l;
        map[b - 1][a - 1] = l;
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                map[j][k] = MIN(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int j = 0; j < n; j++) {
            if (map[i][j] <= m) {
                temp += item[j];
            }
        }
        max_item = MAX(max_item, temp);
    }

    printf("%d", max_item);

    return 0;
}