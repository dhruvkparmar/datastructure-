#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a deque
struct Deque {
    int array[MAX_SIZE];
    int front;
    int rear;
};            

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    } else if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front = (deque->front - 1) % MAX_SIZE;
    }
    deque->array[deque->front] = data;
    printf("%d inserted at the front.\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    } else if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->array[deque->rear] = data;
    printf("%d inserted at the rear.\n", data);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    } else if (deque->front == deque->rear) {
        printf("%d deleted from the front.\n", deque->array[deque->front]);
        deque->front = -1;
        deque->rear = -1;
    } else {
        printf("%d deleted from the front.\n", deque->array[deque->front]);
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    } else if (deque->front == deque->rear) {
        printf("%d deleted from the rear.\n", deque->array[deque->rear]);
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        printf("%d deleted from the rear.\n", deque->array[deque->rear]);
        deque->rear = MAX_SIZE - 1;
    } else {
        printf("%d deleted from the rear.\n", deque->array[deque->rear]);
        deque->rear = (deque->rear - 1) % MAX_SIZE;
    }
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d ", deque->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->array[i]);
}

int main() {
    struct Deque* deque = createDeque();
    int choice, data;

    do {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(deque, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(deque, data);
                break;
            case 3:
                deleteFront(deque);
                break;
            case 4:
                deleteRear(deque);
                break;
            case 5:
                display(deque);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    free(deque);

    return 0;
}
