#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char* array[MAX_SIZE];
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push a folder onto the stack
void push(struct Stack* stack, char* folder) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = strdup(folder);
}

// Function to pop a folder from the stack
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->array[stack->top--];
}

// Function to get the top folder from the stack without removing it
char* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

// Function to free memory allocated for the stack
void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        free(pop(stack));
    }
    free(stack);
}

int main() {
    struct Stack* stack = createStack();
    char operation[10];

    printf("Welcome to File System Crawler\n");
    printf("Supported Operations:\n");
    printf("- '../': Move to the parent folder\n");
    printf("- './': Remain in the same folder\n");
    printf("- 'x/': Move to the child folder named x\n");
    printf("- 'exit': Exit the program\n\n");

    printf("Current Folder: /\n");
    printf("Enter file system operations:\n");

    while (1) {
        scanf("%s", operation);
        if (strcmp(operation, "exit") == 0)
            break;

        if (strcmp(operation, "../") == 0) {
            if (!isEmpty(stack))
                pop(stack);
        } else if (strcmp(operation, "./") != 0) {
            push(stack, operation);
        }

        printf("Current Folder: ");
        if (isEmpty(stack))
            printf("/");
        else {
            for (int i = 0; i <= stack->top; ++i) {
                printf("%s/", stack->array[i]);
            }
        }
        printf("\n");
    }

    freeStack(stack);
    printf("Exiting File System Crawler. Goodbye!\n");

    return 0;
}
