#include<stdio.h>
#include<string.h>

int top=-1;
char stack[100];

void push(char x)
{
    top++;
    stack[top]=x;
}

char pop()
{
    char x=stack[top];
    top--;
    return x;
}

int main()
{
    char str[100];
    printf("enter string: ");
    scanf("%s",str);

    int n=strlen(str);

    for(int i=0;i<n;i++)
    {
        push(str[i]);
    }

    for(int i=0;i<n;i++)
    {
        str[i]=pop();
    }

    printf("reverse: %s",str);
}