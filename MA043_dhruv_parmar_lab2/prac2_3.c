#include <stdio.h>
int checkEvenOdd(int num) {
   if (num % 2 == 0) {
       printf("%d is even\n", num);
   } else {
       printf("%d is odd\n", num);
   }
   return 0;  
}
int main() {
   int num; 
   printf("enter number : ");
   scanf("%d",&num);
   int (*ptr)(int) = checkEvenOdd;
   (*ptr)(num);
   return 0;
}
