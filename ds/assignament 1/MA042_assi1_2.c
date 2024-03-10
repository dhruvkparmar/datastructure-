#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int capacity;
    int top;
    int *array;
};

// Function to create a stack
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    if (!stack->array)
        return NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function to sort the stack in ascending order using a temporary stack
void sortStack(struct Stack *stack) {
    struct Stack *tempStack = createStack(stack->capacity);
    while (!isEmpty(stack)) {
        int temp = pop(stack);
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(stack, pop(tempStack));
        }
        push(tempStack, temp);
    }
    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }
    free(tempStack);
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

    sortStack(stack);

    printf("\nSorted Stack: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }

    free(stack->array);
    free(stack);

    return 0;
}
