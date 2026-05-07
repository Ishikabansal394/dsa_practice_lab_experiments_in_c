#include<stdio.h>
#include<stdlib.h>

void display(int * arr, int top)
{
    if(top==-1)
    {
        printf("stack is empty:\n");
        return;
    }
    for(int i=top; i>=0; i--)
    {
        printf("%d\n",arr[i]);
    }
}
int pop(int *arr, int top)
{
    if(top==-1)
    {
        printf("stack is empty cant pop\n");
        return top;
    }
    top--;
    return top;
}
int push(int *arr, int top, int max)
{
    printf("enter the element to push :\n");
    int l;
    scanf("%d",&l);
    if(top==max-1)
    {
        printf("stack overflow\n");
        return top;
    }
    top++;
    arr[top]=l;
    return top;

}
void peek(int *arr, int top)
{
    printf("%d",arr[top]);
}
int main()
{
    int max;
    printf("enter the number of terms in stack : ");
    scanf("%d",&max);
    int top=-1;
    int stack[max];
    printf("enter elements for stack : \n");
    for(int i=0; i<max; i++)
    {
        scanf("%d",&stack[i]);
        top=i;

    }
    while(1)
    {
        printf("enter 1 for pop\n");
        printf("enter 2 for push\n");
        printf("enter 3 for display\n");
        printf("enter 4 for peek\n");
        printf("enter 5 for exist\n");
        int choice;
        
        scanf("%d",&choice);
    
        switch (choice)
        {
            case 1: top=pop(stack,top);
                    display(stack,top);
                    break;
            case 2: top=push(stack,top,max);
                    display(stack,top);
                    break;
            case 3: display(stack,top);
                    break;
            case 4: peek(stack,top);
                    break;
            
            case 5: exit(0);

        }

    }

}