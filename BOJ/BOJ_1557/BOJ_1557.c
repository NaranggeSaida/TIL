#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50000

long long int mobius[MAX] = { 0 };

long long int count(long long int k) {
    long long int count = 0;

    for (long long int i = 1; i * i <= k; i++) {
        count += mobius[i] * k / (i * i);
    }

    return count;
}

int main() {
    long long int K, first, last;

    scanf("%lld", &K);

    mobius[1] = 1;

    for (int i = 1; i <= MAX; i++) {
        for (int j = 2 * i; j <= MAX; j += i) {
            mobius[j] -= mobius[i];
        }
    }

    first = 0;
    last = K * 2;

    while (first < last - 1) {
        long long int mid = (first + last) / 2;

        if (count(mid) < K) {
            first = mid;
        }
        else {
            last = mid;
        }
    }

    printf("%lld", last);
}