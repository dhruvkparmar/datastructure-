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

// Function to remove adjacent duplicates from the string
char *removeDuplicates(char *s) {
    int len = strlen(s);
    struct Stack *stack = createStack(len);
    
    // Iterate through each character in the string
    for (int i = 0; i < len; i++) {
        // If stack is not empty and top of stack is equal to current character, pop the character
        if (!isEmpty(stack) && stack->array[stack->top] == s[i]) {
            pop(stack);
        } else {
            // Otherwise, push the current character onto the stack
            push(stack, s[i]);
        }
    }
    
    // Create a new string to store the result
    char *result = (char *)malloc((stack->top + 2) * sizeof(char));
    int index = 0;
    
    // Pop characters from stack to form the final string
    while (!isEmpty(stack)) {
        result[index++] = pop(stack);
    }
    result[index] = '\0';
    
    // Reverse the final string to get the correct order
    int i = 0, j = index - 1;
    while (i < j) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }
    
    // Free memory allocated for the stack
    free(stack->array);
    free(stack);
    
    return result;
}

int main() {
    char s[100];
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    
    // Remove the newline character from fgets
    s[strcspn(s, "\n")] = '\0';

    char *result = removeDuplicates(s);
    printf("Output: %s\n", result);

    // Free memory allocated for the result
    free(result);
    
    return 0;
}
