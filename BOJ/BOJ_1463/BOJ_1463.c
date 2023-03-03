#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int list[1000000] = { 0, };

int main(void) {
	int N;
	
	scanf("%d", &N);

	list[1] = 0;

	for (int i = 2; i <= N; i++) {
		list[i] = list[i - 1] + 1;

		if (i % 3 == 0) {
			list[i] = MIN(list[i], list[i / 3] + 1);
		}

		if (i % 2 == 0) {
			list[i] = MIN(list[i], list[i / 2] + 1);
		}
	}

	printf("%d", list[N]);

	return 0;
}