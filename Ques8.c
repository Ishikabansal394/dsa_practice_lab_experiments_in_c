#include<stdio.h>
#include<string.h>

int main()
{
    int n; 
    printf("enter n : \n");
    scanf("%d",&n);
    typedef struct employee { char name[50];char address[50]; int age; int salary;} emp;
    emp det[n];
    int temp=1;
    for(int i=0; i<n; i++)
    { 
        printf("enter details for employee %d : \n",temp);
        printf("enter name : ");
        scanf(" %[^\n]",det[i].name);
        printf("enter address : ");
        scanf(" %[^\n]",det[i].address);
        printf("enter age : ");
        scanf("%d",&det[i].age);
        printf("enter salary : ");
        scanf("%d",&det[i].salary);
        temp++;
    }
    int sum_sal=0;
    for(int i=0; i<n; i++)
    {
       sum_sal=sum_sal+det[i].salary;
    }
    int avg_sal=sum_sal/n;
    printf("average salary = %d",avg_sal);
    
   
    
}