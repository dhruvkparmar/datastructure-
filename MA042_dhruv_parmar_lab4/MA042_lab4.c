#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define MAX 100

// Define a structure for the stack
typedef struct {
    char items[MAX];
    int top;
    int capacity;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow.\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        return '\0';
    }
    return s->items[s->top--];
}

// Function to peep at the top element of the stack
char peep(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->items[s->top];
}

// Function to display the elements of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%c ", s->items[i]);
    }
    printf("\n");
}

// Function to change an element at a specific position in the stack
void change(Stack *s, int position, char newValue) {
    if (position < 0 || position > s->top) {
        printf("Invalid position.\n");
        return;
    }
    s->items[position] = newValue;
}
// Function to create a new character stack
Stack* createCharStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
// Function to reverse a string using stack
char* reverseString(char* str) {
    int length = strlen(str);
    Stack* stack = createCharStack(length);
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversed[i] = pop(stack);
    }
    reversed[length] = '\0';
    free(stack->items);
    free(stack);
    return reversed;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// Function to get precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
char* infixToPostfix(char* infix) {
    int length = strlen(infix);
    Stack* stack = createCharStack(length);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < length; i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(stack) && stack->items[stack->top] != '(' && precedence(stack->items[stack->top]) >= precedence(ch)) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && stack->items[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Discard '('
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    free(stack->items);
    free(stack);
    return postfix;
}
// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int length = strlen(postfix);
    printf("%d",length);
    Stack* stack = createCharStack(length);
    for (int i = 0; i < length; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(stack, ch - '0');
        } else if (isOperator(ch)) {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (ch) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
    }
    int result = pop(stack);
    free(stack->items);
    free(stack);
    return result;
}



int main() {
    Stack s;
    initialize(&s);
    char str[MAX];
    char infix[MAX];
    char postfix[MAX];
    char choice;
    do {
        printf("\nSelect operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. reversed\n");
        printf("7. infix to post fix\n");
        printf("8. postfix evaluction \n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter character to push onto the stack: ");
                char value;
                scanf(" %c", &value);
                push(&s, value);
                break;
            case '2':
                printf("Popped element: %c\n", pop(&s));
                break;
            case '3':
                printf("Top element: %c\n", peep(&s));
                break;
            case '4':
                printf("Enter position to change: ");
                int position;
                scanf("%d", &position);
                printf("Enter new value: ");
                char newValue;
                scanf(" %c", &newValue);
                change(&s, position, newValue);
                break;
            case '5':
                display(&s);
                break;
            case '6':{
                
                printf("Enter a string to reverse: ");
                scanf(" %[^\n]", str);
                char* reversed = reverseString(str);
                printf("Reversed string: %s\n", reversed);
                free(reversed);
                break;}
            case '7' : 
                
                printf("Enter an infix expression: ");
                scanf(" %[^\n]", infix);
                char* postfix = infixToPostfix(infix);
                printf("Postfix expression: %s\n", postfix);
                free(postfix);
                break;
            case '8':
                
                printf("Enter a postfix expression: ");
                scanf(" %[^\n]", postfix);
                int result = evaluatePostfix(postfix);
                printf("Result of postfix expression: %d\n", result);
                break;
            case '9':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '9');
    return 0;
}