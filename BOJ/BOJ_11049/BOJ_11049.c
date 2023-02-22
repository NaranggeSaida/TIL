#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int N, a, b;
	int p[500][2];
	int m[500][500];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i][0], &p[i][1]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			a = j;
			b = i + j;
			if (a == b) {
				m[a][b] = 0;
			}
			else {
				m[a][b] = 1000000000;
				for (int k = a; k < b; k++) {
					m[a][b] = min(m[a][b], m[a][k] + m[k + 1][b] + (p[a][0] * p[k][1] * p[b][1]));
				}
			}
		}
	}

	printf("%d", m[0][N - 1]);

	return 0;
}