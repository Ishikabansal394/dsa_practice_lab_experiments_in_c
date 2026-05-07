#include<stdio.h>
#include<stdio.h>
int main()
{
    typedef struct student { char name[50]; int roll; int marks ; } stud;
    stud one;
    printf("enter name : ");
    scanf(" %[^\n]",one.name);
    printf("enter roll no. : ");
    scanf("%d",& one.roll);
    printf("enter marks : ");
    scanf("%d",& one.marks);
    stud two = {"Natasha",2,98};
    printf("%s %d %d\n",one.name,one.marks,one.roll);
    printf("%s %d %d",two.name,two.marks,two.roll);
    
}