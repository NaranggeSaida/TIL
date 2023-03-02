#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct {
	char word[51];
}word;

int compare(const void* a, const void* b) {
	word A = *(word*)a;
	word B = *(word*)b;

	if (strlen(A.word) > strlen(B.word)) {
		return 1;
	}
	else if (strlen(A.word) < strlen(B.word)) {
		return -1;
	}
	else {
		return(strcmp(A.word, B.word));
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	word* list = (word*)malloc(sizeof(word) * (N + 1));

	for (int i = 0; i < N; i++) {
		scanf("%s", list[i].word);
	}

	qsort(list, N, sizeof(word), compare);

	for (int i = 0; i < N; i++) {
		if (strcmp(list[i].word, list[i + 1].word) != 0 || i == N - 1) {
			printf("%s\n", list[i].word);
		}
	}

	free(list);

	return 0;
}