#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int array[MAX_SIZE];
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

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(struct Stack* stack, int data) {
    if (isEmpty(stack)) {
        push(stack, data);
    } else {
        int temp = pop(stack);
        insertAtBottom(stack, data);
        push(stack, temp);
    }
}

// Function to reverse the stack
void reverseStack(struct Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

// Structure to represent a queue using one stack
struct Queue {
    struct Stack* stack;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack = createStack();
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    // Reverse the stack to simulate enqueue operation
    reverseStack(queue->stack);
    // Push the data into the stack
    push(queue->stack, data);
    // Reverse the stack back to its original state
    reverseStack(queue->stack);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack)) {
        printf("Queue is empty\n");
        return -1;
    }
    // Pop the top element from the stack
    return pop(queue->stack);
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue->stack)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    // Temporary stack to hold elements while displaying
    struct Stack* tempStack = createStack();
    while (!isEmpty(queue->stack)) {
        int data = pop(queue->stack);
        printf("%d ", data);
        // Push the popped element into the temporary stack
        push(tempStack, data);
    }
    // Restore the original order of elements in the queue
    while (!isEmpty(tempStack)) {
        push(queue->stack, pop(tempStack));
    }
    printf("\n");
    free(tempStack);
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                printf("%d enqueued to the queue.\n", data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1)
                    printf("%d dequeued from the queue.\n", data);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free memory allocated for the queue and stack
    free(queue->stack);
    free(queue);

    return 0;
}
