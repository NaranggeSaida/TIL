#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct stack {
    int top;
    char s[MAX_SIZE];
}stack;

void push(stack* s, char element) {
    s->top++;
    s->s[s->top] = element;
}

char pop(stack* s) {
    char temp = s->s[s->top];
    s->top--;
    return temp;
}
int is_empty(stack* s) {
    if (s->top != -1)
        return 0;
    return 1;
}

char peek(stack* s) {
    return s->s[s->top];
}

int isoperator(char op) {
    switch (op) {
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    default:
        return -1;
    }
}

void postfix(char* str) {
    int i = 0;
    stack s;
    s.top = -1;

    for (i = 0; i < strlen(str); i++) {
        if (isoperator(str[i]) == -1) {
            printf("%c", str[i]);
        }
        else if (str[i] == '(') {
            push(&s, str[i]);
        }
        else if (str[i] == ')') {
            while (peek(&s) != '(') {
                printf("%c", pop(&s));
            }

            pop(&s);
        }
        else if (isoperator(str[i]) >= 1) {
            while (!is_empty(&s) && isoperator(str[i]) <= isoperator(peek(&s))) {
                printf("%c", pop(&s));
            }

            push(&s, str[i]);
        }
    }

    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }
}

int main(void) {
    char str[100];
    int i = 0;

    scanf("%s", str);

    postfix(str);
}