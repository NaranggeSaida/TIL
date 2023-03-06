#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int list[100000] = { 0, };
int stack[200000] = { 0, };
int bottom = 0;
int top = 0;
int op = 0;
char operator[200000];

void push(int N) {
	stack[top++] = N;

	operator[op++] = '+';
}

void pop() {
	top--;

	operator[op++] = '-';
}

int main(void) {
	int N;
	int temp = 0;
	int index = 0;
	int number = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}

	while (index < N) {
		if (number < list[index]) {
			push(number++);
		}
		else if (number == list[index]) {
			push(number++);

			pop();

			index++;
		}
		else {
			if (stack[top - 1] == list[index]) {
				pop();

				index++;
			}
			else {
				temp = -1;

				break;
			}
		}
	}

	if (temp == -1) {
		printf("NO");
	}
	else {
		for (int i = 0; i < op; i++) {
			printf("%c\n", operator[i]);
		}
	}

	return 0;
}