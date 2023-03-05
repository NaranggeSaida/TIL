#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[101];
}chart;

void merge(chart list[], int left, int mid, int right, int N) {
	int a = left;
	int b = mid + 1;
	int c = left;

	chart* list2 = (chart*)malloc(sizeof(chart) * (N + 1));

	while (a <= mid && b <= right) {
		if (list[a].age <= list[b].age) {
			list2[c] = list[a];
			a++;
			c++;
		}
		else {
			list2[c] = list[b];
			b++;
			c++;
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

void merge_sort(chart list[], int left, int right, int N) {
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

	chart* list = (chart*)malloc(sizeof(chart) * (N + 1));

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &list[i].age, &list[i].name);
	}

	merge_sort(list, 0, N - 1, N);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", list[i].age, list[i].name);
	}

	return 0;
}