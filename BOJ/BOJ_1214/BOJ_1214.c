#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b) {int temp = a; a = b; b = temp;}
#define MIN(a,b) (((a) < (b)) ? (a) : (b))


int main(void) {
    int D, P, Q, ans, a;

    scanf("%d %d %d", &D, &P, &Q);

    if (D % P == 0 || D % Q == 0) {
        printf("%d", D);
        return 0;
    }
    else {
        if (P < Q) {
            SWAP(P, Q);
        }

        ans = (D / P) * P + P;
        a = ans;
    }

    for (int i = 1; i <= a / P; i++) {
        int temp = a - P * i;
        if ((D - temp) % Q == 0) {
            printf("%d", D);
            return 0;
        }
        else {
            temp += ((D - temp) / Q) * Q + Q;
        }

        if (ans == temp) {
            break;
        }

        ans = MIN(temp, ans);
    }

    printf("%d", ans);

    return 0;
}