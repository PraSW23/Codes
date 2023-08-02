#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size;
};

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Warning: Stack is empty.\n");
        return -1; // Or some other appropriate error value
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

void destroyStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    struct Stack* stack = initializeStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped value: %d\n", pop(stack));
    printf("Popped value: %d\n", pop(stack));
    printf("Popped value: %d\n", pop(stack));

    destroyStack(stack);

    return 0;
}
