#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop an element from the stack
int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to insert an element into the stack at its correct position
void sortedInsert(struct StackNode** root, int data) {
    if (isEmpty(*root) || data < (*root)->data) {
        push(root, data);
        return;
    }
    int temp = pop(root);
    sortedInsert(root, data);
    push(root, temp);
}

// Function to sort the stack using recursion
void sortStack(struct StackNode** root) {
    if (!isEmpty(*root)) {
        int temp = pop(root);
        sortStack(root);
        sortedInsert(root, temp);
    }
}

// Function to print elements of stack
void printStack(struct StackNode* root) {
    if (isEmpty(root))
        return;

    int data = pop(&root);
    printStack(root);
    printf("%d ", data);
    push(&root, data);
}

int main() {
    struct StackNode* root = NULL;
    int size, num;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++) {
        printf("enter stack element %d : ",i+1);
        scanf("%d", &num);
        push(&root, num);
    }

    printf("\nOriginal Stack: ");
    printStack(root);

    // Sort the stack
    sortStack(&root);

    printf("\nSorted Stack: ");
    printStack(root);
    printf("\n");

    return 0;
}
