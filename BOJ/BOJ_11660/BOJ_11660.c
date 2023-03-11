#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1025][1025] = { 0, };

int main(void) {
	int N, M, temp, x1, x2, y1, y2;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &temp);

			arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
	}

	return 0;
}