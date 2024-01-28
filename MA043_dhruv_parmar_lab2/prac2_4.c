#include <stdio.h>

int incrementBy2(int num);
int decrementBy2(int num);
void applyOperation(int num, int (*operation)(int));

int main() {
   int num, choice;

   printf("Enter a number: ");
   scanf("%d", &num);

   printf("Choose operation:\n");
   printf("1. Increment\n");
   printf("2. Decrement\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch (choice) {
       case 1:
           applyOperation(num, incrementBy2);  
           break;
       case 2:
           applyOperation(num, decrementBy2);  
           break;
       default:
           printf("Invalid choice!\n");
   }

   return 0;
}
int incrementBy2(int num) {
   return num + 2;
}

int decrementBy2(int num) {
   return num - 2;
}
void applyOperation(int num, int (*operation)(int)) {
   int result = operation(num);  
   printf("Result: %d\n", result);
}
