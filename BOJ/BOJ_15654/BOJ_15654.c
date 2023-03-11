#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M;
int num[10] = { 0, };
int arr[10] = { 0, };
int check[10] = { 0, };

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;

	if (A > B) {
		return 1;
	}
	else {
		return 0;
	}
}

void seq(int len) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}

		printf("\n");

		return;
	}

	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			arr[len] = num[i];

			check[i] = 1;

			seq(len + 1);

			check[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	qsort(num, N, sizeof(int), compare);

	seq(0);

	return 0;
}