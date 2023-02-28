#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char number[5];

	while (1) {
		int check = 1;
		scanf("%s", &number);

		if (number[0] == '0') {
			break;
		}

		for (int i = 0; i < strlen(number) / 2; i++) {
			if (number[i] != number[strlen(number) - (i + 1)]) {
				check = 0;
			}
		}

		if (check == 0) {
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
	}

	return 0;
}