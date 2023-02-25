#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int chess[15] = { 0, };
int ans = 0;

int promise(int N) {
	for (int i = 0; i < N; i++) {
		if (chess[N] == chess[i] || abs(chess[N] - chess[i]) == abs(N - i)) {
			return 0;
		}
	}
	return 1;
}

void n_queen(int x, int N) {
	if (x == N) {
		ans++;
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[x] = i;
			if (promise(x)) {
				n_queen(x + 1, N);
			}
		}
	}
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	n_queen(0, N);
	printf("%d", ans);

	return 0;
}