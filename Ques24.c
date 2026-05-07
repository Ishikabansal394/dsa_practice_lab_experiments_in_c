#include<stdio.h>


int q1[100], q2[100];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;



void push(int x)
{
    q2[++r2] = x;

    while(f1 <= r1)
    {
        q2[++r2] = q1[f1];
        f1++;
    }
    f1 = 0;

    r1 = r2;
    for(int i = 0; i <= r1; i++)
    {
        q1[i] = q2[i];
    }
    r2 = -1;
}

void pop()
{
    if(f1 <= r1)
    {
        f1++;
    }
}
void display()
{
    for(int i = f1; i <= r1; i++)
    {
        printf("%d ", q1[i]);
    }
}
int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();
}