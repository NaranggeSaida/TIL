#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char N[10];
	int list[10] = { 0, };

	scanf("%s", &N);

	for (int i = 0; i < strlen(N); i++) {
		list[N[i] - '0']++;
	}

	for (int i = 9; i > -1; i--) {
		for (; list[i] != 0;) {
			printf("%d", i);
			list[i]--;
		}
	}

	return 0;
}