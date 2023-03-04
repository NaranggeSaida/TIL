#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void) {
	int N;
	int stair[301] = { 0, };
	int data[301] = { 0, };

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}

	data[1] = stair[1];
	data[2] = stair[1] + stair[2];
	data[3] = MAX(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++) {
		data[i] = MAX(data[i - 2] + stair[i], data[i - 3] + stair[i] + stair[i - 1]);
	}

	printf("%d", data[N]);

	return 0;
}