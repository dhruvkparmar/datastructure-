#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

void collectData(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter a new student  data\n");
        printf("Enter a Roll number : ");
        scanf("%d", &s[i].roll);
        printf("Enter a Name : ");
        scanf("%s", s[i].name);
        printf("Enter a Marks : ");
        scanf("%d", &s[i].marks);
    }
}
void displayData(struct student *s, int n)
{
    printf("\n----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nstudent roll number is : %d", s[i].roll);
        printf("\nstudent name is : %s", s[i].name);
        printf("\nstudent marks : %d", s[i].marks);
    }
}
void filter(struct student *s, int n, int m)
{
    printf("\nfilter %d below marks student", m);
    for (int i = 0; i < n; i++)
    {
        if (s[i].marks < m)
        {
            displayData(s, 1);
        }
    }
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    struct student s[n];
    struct student *ptr = s;
    collectData(ptr, n);
    displayData(ptr, n);
    filter(ptr, n, m);

    return 0;
}