#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int size;
    char *arr;
    int top;
};

void CreateSTK(struct stack *s) {
    s->arr = (char *)malloc(sizeof(char) * s->size);
    s->top = -1;
}

void STKtraversal(struct stack *s) {
    int index = s->top;
    while (index > -1) {
        printf("%c\n", s->arr[index--]);
    }
}

void pop(struct stack *s) {
    if (s->top == -1) {
        // printf("\nStack is empty! unable to pop\n");
        return;
    } else {
        printf(" %c", s->arr[s->top]);
        s->top--;
    }
    return;
}

void push(struct stack *s, char data) {
    if (s->size == s->top + 1) {
        // printf("Stack Overflow! unable to push %d\n",data);
        return;
    } else {
        s->arr[++s->top] = data;
        // printf("\n->%c",s->arr[s->top]);
    }
}

void in_to_post(struct stack *s, char *str) {

    for (int i = 0; i < 100; i++) {
        char k = str[i], temp = (s->top != -1) ? s->arr[s->top] : '\0';

        if (k=='\0')
        {
            break;
        }
        

        if (k == '/' || k == '*') {
            if (temp == '/' || temp == '*') {
                while (s->top != -1) {
                    pop(s);
                }
                push(s, k);
            } else if (s->top == -1 || temp == '+' || temp == '-') {
                push(s, k);
            }
        } else if (k == '+' || k == '-') {
            if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                while (s->top != -1) {
                    pop(s);
                }
                push(s, k);
            } else if (s->top == -1) {
                push(s, k);
            }
        } else {
            printf(" %c", str[i]);
        }
    }
    while (s->top!=-1)
    {
        pop(s);
    }
    printf("\n");

}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    char str[s->size];

    printf("Enter a string(without space) : ");
    scanf("%s", str);

    CreateSTK(s);

    in_to_post(s, str);

    return 0;
}
