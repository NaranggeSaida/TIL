#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, quotient, remainder;
	int answer = -1;

	scanf("%d", &N);

	quotient = N / 5;

	for (int i = quotient; i > -1; i--) {
		remainder = N - (i * 5);

		if (remainder % 3 == 0) {
			answer = i + (remainder / 3);
			break;
		}
	}

	printf("%d", answer);
}