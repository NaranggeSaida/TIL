#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size_x 1005
#define size_y 1005

int x, y;
int map[size_x][size_y];
int check[size_x][size_y];
int q[1000050][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int head = 0;
int tail = 0;

int main(void) {
    int M, N;

    scanf("%d %d", &M, &N);

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            map[i][j] = -1;
            check[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 1) {
                q[tail][0] = i;
                q[tail][1] = j;
                tail++;
            }
        }
    }

    while (head < tail) {
        x = q[head][0];
        y = q[head][1];
        head++;

        for (int i = 0; i < 4; i++) {
            if (x + dx[i] <= N && y + dy[i] <= M && x + dx[i] >= 1 && y + dy[i] >= 1 && map[x + dx[i]][y + dy[i]] == 0) {
                map[x + dx[i]][y + dy[i]] = 1;
                check[x + dx[i]][y + dy[i]] = check[x][y] + 1;
                q[tail][0] = x + dx[i];
                q[tail][1] = y + dy[i];
                tail++;
            }
        }
    }

    int days = 0;
    int count = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (days < check[i][j]) {
                days = check[i][j];
            }
            if (map[i][j] == 0)
                count = 1;
        }
    }

    if (count == 1)
        printf("-1\n");
    else
        printf("%d\n", days);

    return 0;
}