#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int table[1001][1001] = { 0, };

int main(void) {
	char string1[1001];
	char string2[1001];

	scanf("%s", &string1);
	scanf("%s", &string2);

	for (int i = 1; i <= strlen(string1); i++) {
		for (int j = 1; j <= strlen(string2); j++) {
			if (string1[i - 1] == string2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = MAX(table[i - 1][j], table[i][j - 1]);
			}
		}
	}

	printf("%d", table[strlen(string1)][strlen(string2)]);

	return 0;
}