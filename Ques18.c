#include<stdio.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    return stack[top--];
}
int prec(char c)
{
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}
int main()
{
    char infix[100],postfix[100];
    int j=0;

    printf("enter infix: ");
    scanf("%s",infix);

    for(int i=0; infix[i]!='\0'; i++)
    {
        char ch=infix[i];

        if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
              postfix[j++]=pop();
            }
            pop();
        }
        else
        {
       while(top!=-1 && prec(stack[top])>=prec(ch))
            {
                postfix[j++]=pop();
            }
            push(ch);
        }
    }

    while(top!=-1)
    {
        postfix[j++]=pop();
    }

    postfix[j]='\0';

    printf("postfix: %s",postfix);
}