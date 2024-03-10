#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack with given capacity
struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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
void push(struct Stack *stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to insert an element at the bottom of a stack
void insertAtBottom(struct Stack *stack, int item) {
    if (isEmpty(stack)) {
        push(stack, item);
    } else {
        int temp = pop(stack);
        insertAtBottom(stack, item);
        push(stack, temp);
    }
}

// Function to reverse a stack using recursion
void reverseStack(struct Stack *stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

int main() {
    int capacity, num;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    struct Stack *stack = createStack(capacity);

    printf("Enter %d elements to push onto the stack: \n", capacity);
    for (int i = 0; i < capacity; i++) {
        printf("enter stack element %d : ",i+1);
        scanf("%d", &num);
        push(stack, num);
    }

    printf("\nOriginal Stack: ");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", stack->array[i]);
    }

    reverseStack(stack);

    printf("\nReversed Stack: ");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", stack->array[i]);
    }

    free(stack->array);
    free(stack);

    return 0;
}
