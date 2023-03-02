#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

void merge(point list[], int left, int mid, int right, int N) {
	int a = left;
	int b = mid + 1;
	int c = left;

	point* list2 = (point*)malloc(sizeof(point) * (N + 1));

	while (a <= mid && b <= right) {
		if (list[a].x < list[b].x) {
			list2[c++] = list[a++];
		}
		else if (list[a].x == list[b].x) {
			if (list[a].y < list[b].y) {
				list2[c++] = list[a++];
			}
			else {
				list2[c++] = list[b++];
			}
		}
		else {
			list2[c++] = list[b++];
		}
	}

	if (a > mid) {
		for (int i = b; i <= right; i++) {
			list2[c++] = list[i];
		}
	}
	else {
		for (int i = a; i <= mid; i++) {
			list2[c++] = list[i];
		}
	}

	for (int i = left; i <= right; i++) {
		list[i] = list2[i];
	}

	free(list2);
}

void merge_sort(point list[], int left, int right, int N) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		merge_sort(list, left, mid, N);
		merge_sort(list, mid + 1, right, N);
		merge(list, left, mid, right, N);
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	point* list = (point*)malloc(sizeof(point) * (N + 1));

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}

	merge_sort(list, 0, N - 1, N);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}

	return 0;
}