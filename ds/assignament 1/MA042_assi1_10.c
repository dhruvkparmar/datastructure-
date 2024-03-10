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
    printf("%d pushed onto the stack\n", item);
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

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to save the stack to a file
void saveToFile(struct Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    for (int i = 0; i <= stack->top; ++i) {
        fprintf(file, "%d\n", stack->array[i]);
    }

    fclose(file);
    printf("Stack saved to file successfully\n");
}

// Function to load the stack from a file
void loadFromFile(struct Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or error opening file for reading\n");
        return;
    }

    int item;
    while (fscanf(file, "%d", &item) != EOF) {
        push(stack, item);
    }

    fclose(file);
    printf("Stack loaded from file successfully\n");
}

// Function to free memory allocated for the stack
void freeStack(struct Stack* stack) {
    free(stack);
}

int main(int argc, char* argv[]) {
    struct Stack* stack;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    stack = createStack();
    loadFromFile(stack, argv[1]);

    int choice, data;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Save to File\n");
        printf("6. Is Full?\n");
        printf("7. Is Empty?\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1)
                    printf("Popped element: %d\n", data);
                break;
            case 3:
                data = peek(stack);
                if (data != -1)
                    printf("Top element: %d\n", data);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                saveToFile(stack, argv[1]);
                break;
            case 6:
                if (isFull(stack))
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 7:
                if (isEmpty(stack))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 8);

    freeStack(stack);

    return 0;
}
