#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int T, N;
    int fibo[40][2] = { 0, };

    scanf("%d", &T);

    fibo[0][0] = 1; 
    fibo[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }

    while (T--) {
        scanf("%d", &N);
        printf("%d %d\n", fibo[N][0], fibo[N][1]);
    }

    return 0;
}
