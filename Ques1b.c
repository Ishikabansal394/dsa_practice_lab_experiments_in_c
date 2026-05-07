#include<stdio.h>

int tree[100];

void insert(int value, int index)
{
    tree[index] = value;
}

void display(int n)
{
    for(int i = 0; i < n; i++)
    {
        if(tree[i] != 0)
            printf("%d ", tree[i]);
    }
}

int main()
{
    insert(10, 0);
    insert(20, 1);
    insert(30, 2);
    insert(40, 3);
    insert(50, 4);

    display(5);
}