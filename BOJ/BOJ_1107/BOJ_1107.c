#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int remote[1000001] = { 0, };
int broken[10] = { 0, };

int main(void) {
	int botten, N, M;
	int minimum = 1000000;

	scanf("%d", &N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &botten);
		broken[botten] = -1;
	}

	for (int i = 0; i <= MAX(2 * N, 100); i++) {
		if (i == 100) {
			remote[i] = abs(N - i);

			minimum = MIN(minimum, remote[i]);

			continue;
		}

		char temp[8];
		int check = 0;

		sprintf(temp, "%d", i);

		for (int j = 0; j < strlen(temp); j++) {
			for (int k = 0; k < 10; k++) {
				if (broken[k] == -1 && k == temp[j] - '0') {
					check = -1;
				}
			}
		}

		if (check == -1) {
			remote[i] = -1;
		}
		else {
			remote[i] = strlen(temp) + abs(N - i);

			minimum = MIN(minimum, remote[i]);
		}
	}

	printf("%d", minimum);
	
	return 0;
}