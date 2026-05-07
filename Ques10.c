/*Create a structure named date that has day, month, and year as its members. 
Include this structure as a member in another structure named employee which has name, 
id and salary as other members. 
Use this structure to read and display employee’s name, id, data of birth and salary.*/
#include <stdio.h>
#include<string.h>
struct date
{
    int day;
    int month;
    int year;
};

struct employee
{
    char name[50];
    int id;
    float salary;
    struct date dob;
};
int main()
{
    struct employee emp;
    printf("enter employee name: ");
    scanf(" %[^\n]",emp.name);
    printf("enter employee id: ");
    scanf("%d",&emp.id);
    printf("enter salary: ");
    scanf("%f",&emp.salary);
    printf("enter birth day: ");
    scanf("%d",&emp.dob.day);
    printf("enter birth month: ");
    scanf("%d",&emp.dob.month);
    printf("enter birth year: ");
    scanf("%d",&emp.dob.year);
    printf("Employee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Salary: %.2f\n", emp.salary);
    printf("Date of Birth: %d/%d/%d\n", emp.dob.day, emp.dob.month, emp.dob.year);
    return 0;
}
