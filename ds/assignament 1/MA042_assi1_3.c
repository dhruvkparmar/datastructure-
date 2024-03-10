#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char *array;
};

// Function to create a stack with given capacity
struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push element onto the stack
void push(struct Stack *stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to print the stack contents
void printStack(struct Stack *stack) {
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
}

// Function to sort the characters of the string in ascending order
void sortString(char *str) {
    int len = strlen(str);
    struct Stack *mainStack = createStack(len);
    struct Stack *auxStack = createStack(len);

    push(mainStack, str[0]);

    for (int i = 1; i < len; i++) {
        char current = str[i];
        while (!isEmpty(mainStack) && current > mainStack->array[mainStack->top]) {
            push(auxStack, pop(mainStack));
        }
        push(mainStack, current);
        while (!isEmpty(auxStack)) {
            push(mainStack, pop(auxStack));
        }
    }

    printf("Output: ");
    printStack(mainStack);

    free(mainStack->array);
    free(mainStack);
    free(auxStack->array);
    free(auxStack);
}

int main() {
    char str[100];
    printf("Input: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    sortString(str);

    return 0;
}
