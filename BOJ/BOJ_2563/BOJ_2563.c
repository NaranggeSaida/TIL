#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

int main() {
    int white[100][100] = { 0, };
    int N, left, down;
    int count = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &left, &down);

        for (int j = 100 - (down + 10); j < 100 - down; j++) {
                for (int k = left; k < left + 10; k++) {
                    white[j][k] = 1;
                }
        }
    }

    for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (white[i][j] == 1)
                    count++;
            }
    }

    printf("%d", count);

    return 0;
}