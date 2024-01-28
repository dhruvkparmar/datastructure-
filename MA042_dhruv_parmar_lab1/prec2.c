#include <stdio.h>

struct student
{
     int roll;
     char name[20];
     int marks[5];
     int total;
     float per;
};

void collectingData(struct student *s, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("enter a new student  data\n");
          printf("Enter a Roll number : ");
          scanf("%d", &s[i].roll);
          printf("Enter a Name : ");
          scanf("%s", s[i].name);
          printf("Enter a 5 Subject Marks : ");

          for (int j = 0; j < 5; j++)
          {
               scanf("%d", &s[i].marks[j]);
          }
     }
}

void computing(struct student *s)
{ 
     for (int i = 0; i < 3; i++)
     {
          s[i].total = 0;
          for (int j = 0; j < 5; j++)
          {
               s[i].total = s[i].marks[j] + s[i].total;
          }

          s[i].per = s[i].total / 5.0;
     }
}

void displayingData(struct student *s, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("\n---------------------------------------------------------------\n");
          printf("\nStudent %d data", i + 1);
          printf("\nStudent roll number is : %d", s[i].roll);
          printf("\nStudent name is : %s", s[i].name);
          printf("\nStudent Marks : ");
          for (int j = 0; j < 5; j++)
          {
               printf("%d ", s[i].marks[j]);
          }
          printf("\nStudent marks total  is : %d", s[i].total);
          printf("\nStudent percentage is  : %.2f", s[i].per);
     }
}

int main(int argc, char const *argv[])
{

     int n;
     printf("how many student enter data : ");
     scanf("%d", &n);

     struct student s[n];
     struct student *ptr = s;

     collectingData(ptr, n);
     computing(ptr);
     displayingData(ptr, n);

     return 0;
}