#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T, n;
	int arr[10000] = { 0, };

	for (int i = 2; i < 10000; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				arr[i] = 1;
				break;
			}
		}
	}

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);

		for (int j = n /2; j > 0; j--) {
			if (arr[j] == 0 && arr[n - j] == 0) {
				printf("%d %d\n", j, n - j);
				break;
			}
		}
	}

	return 0;
}