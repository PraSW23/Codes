#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct stack {
    int size;
    int top;
    char* arr;
};

struct stack* createSTK(int size) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->arr = (char*)malloc(sizeof(char) * s->size);
    s->top = -1;
    return s;
}

void traverseSTK(struct stack* s) {
    if (s->top == -1) {
        printf("Empty stack\n");
    }
    else {
        int i = s->top;
        while (i != -1)
            printf("%c\n ", s->arr[i--]);
    }
}

void push(struct stack* s, int val) {
    if (s->top < s->size - 1) {
        s->top++;
        s->arr[s->top] = val;
    }
    else
        printf("Stack overflow\n");
}

int pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    else {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

bool paren_match(struct stack* s, char* st) {
    for (int i = 0; i < s->size; i++) {
        if ((s->top == -1) && (st[i] == ')' || st[i] == ']' || st[i] == '}')) {
            return false;
        }

        if (st[i] == '(' || st[i] == '[' || st[i] == '{') {
            push(s, st[i]);
        }
        else if (st[i] == ')' || st[i] == ']' || st[i] == '}') {
            if (s->arr[s->top] == '(' && st[i] == ')') {
                pop(s);
            }
            else if (s->arr[s->top] == '[' && st[i] == ']') {
                pop(s);
            }
            else if (s->arr[s->top] == '{' && st[i] == '}') {
                pop(s);
            }
            else {
                return false;
            }
        }
        else
            continue;
    }

    if (s->top == -1) {
        return true;
    }
    else
        return false;
}

int main() {
    int size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);

    struct stack* s = createSTK(size);

    char st[size];
    printf("Enter string to validate parenthesis matching: ");
    getchar(); // Clear the newline character from the previous input
    fgets(st, size, stdin);

    if (paren_match(s, st)) {
        printf("\nParenthesis Matched\n");
    }
    else {
        printf("\nNot Matched\n");
    }

    return 0;
}
