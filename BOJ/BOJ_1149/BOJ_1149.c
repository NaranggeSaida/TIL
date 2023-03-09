#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int house[1000][3] = { 0, };

int main(void) {
	int N, r, g, b;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &r, &g, &b);

		house[i][0] = MIN(house[i - 1][1], house[i - 1][2]) + r;
		house[i][1] = MIN(house[i - 1][0], house[i - 1][2]) + b;
		house[i][2] = MIN(house[i - 1][0], house[i - 1][1]) + g;
	}

	printf("%d", MIN(house[N][0], MIN(house[N][1], house[N][2])));

	return 0;
}