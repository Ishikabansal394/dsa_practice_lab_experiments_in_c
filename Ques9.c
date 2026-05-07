/*Write a program to read the name, address, and salary of 5 employees using array of structure. 
Display information of each employee in alphabetical order of their name.
*/
#include<stdio.h>
#include<string.h>

int main()
{
    
    typedef struct employee { char name[50]; char address[50]; int salary;} emp;
    emp det[5];
    int temp=1;
    for(int i=0; i<5; i++)
    { 
        printf("enter details for employee %d : \n",temp);
        printf("enter name : ");
        scanf(" %[^\n]",det[i].name);
        printf("enter address : ");
        scanf(" %[^\n]",det[i].address);
        printf("enter salary : ");
        scanf("%d",&det[i].salary);
        temp++;
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5-1-i; j++)
        {
            if(strcmp(det[j].name,det[j+1].name)>0)
            {
                emp temp=det[j];
                det[j]=det[j+1];
                det[j+1]=temp;
            }
        }
    }
    for(int i=0; i<5; i++)
    { 
        printf("name : ");
        printf(" %s\n",det[i].name);
        printf("address : ");
        printf(" %s\n",det[i].address);
        printf("salary : ");
        printf("%d\n",det[i].salary);
    }
    return 0;
}
