#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;
void display()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct node* temp = top;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


void pop()
{
    if(top == NULL)
    {
        printf("stack is empty cant pop\n");
        return;
    }
    struct node* temp = top;
    top = top->next;
    free(temp);
}

void push()
{
    printf("enter the element to push :\n");
    int l;
    scanf("%d", &l);

    struct node* new = (struct node*)malloc(sizeof(struct node));
    if(new == NULL)
    {
        printf("memory full\n");
        return;
    }

    new->data = l;
    new->next = top;
    top = new;
}

void peek()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
        return;
    }

    printf("%d\n", top->data);
}

int main()
{
    int choice;

    while(1)
    {
        printf("enter 1 for pop\n");
        printf("enter 2 for push\n");
        printf("enter 3 for display\n");
        printf("enter 4 for peek\n");
        printf("enter 5 for exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: pop();
                    display();
                    break;

            case 2: push();
                    display();
                    break;

            case 3: display();
                    break;

            case 4: peek();
                    break;

            case 5: exit(0);

            default: printf("invalid choice\n");
        }
    }
}