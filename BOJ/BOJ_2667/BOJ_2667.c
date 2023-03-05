#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[25][25] = { 0 };
int apart[25 * 25] = { 0 };
int sum = 0;
int xx[4] = { -1, 1, 0, 0 };
int yy[4] = { 0, 0, -1, 1 };
int n, count;

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return 0;
    }

    if (graph[x][y] == 1) {
        graph[x][y] = 0;
        count++;

        for (int i = 0; i < 4; i++) {
            dfs(x + xx[i], y + yy[i]);
        }

        return 1;

    }

    return 0;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j) == 1) {
                apart[count]++;
                count = 0;
                sum++;
            }
        }
    }

    printf("%d\n", sum);

    for (int i = 0; i < 26 * 26; i++) {
        if (apart[i] != 0) {
            int k = apart[i];

            for (int j = 0; j < k; j++) {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}