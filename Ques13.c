/*Write a menu driven program for the addition, subtrac
tion, and multiplication of two polynomials using singly linked lists.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *create(struct node *head)
{
    int n, c, e;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient: ");
        scanf("%d", &c);

       printf("Enter exponent: ");
        scanf("%d", &e);

        newnode->coef = c;
        newnode->exp = e;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct node *temp = head;
             while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    return head;
}


void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
         printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}


struct node *add(struct node *p1, struct node *p2)
{
    struct node *p3 = NULL, *h = p3;

    while(p1 != NULL && p2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        if(p1->exp == p2->exp)
        {
            newnode->coef = p1->coef + p2->coef;
            newnode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp)
        {
            newnode->coef = p1->coef;
            newnode->exp = p1->exp;
            p1 = p1->next;
        }
        else
        {
            newnode->coef = p2->coef;
            newnode->exp = p2->exp;
            p2 = p2->next;
        }

        newnode->next = NULL;

        if(p3 == NULL)
        {
            h = newnode;
            h=p3;
        }
        else
        {
            while(h->next != NULL)
            {
                h = h->next;
            }
            h->next = newnode;
            h = newnode;
        }
    }
    while(p1!=NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coef = p1->coef;
        newnode->exp = p1->exp;
        newnode->next = NULL;

        if(p3 == NULL)
        {
            p3 = newnode;
            h = p3;
        }
        else
        {
            h->next = newnode;
            h = newnode;
        }
        p1=p1->next;

    }
    while(p2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coef = -p2->coef;
        newnode->exp = p2->exp;
        newnode->next = NULL;

        if(p3 == NULL)
        {
            p3 = newnode;
            h = p3;
        }
        else
        {
            h->next = newnode;
            h = newnode;
        }

        p2 = p2->next;
    }

    return p3;
}


struct node *subtract(struct node *p1, struct node *p2)
{
    struct node *p3 = NULL, *h = p3;

    while(p1 != NULL && p2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        if(p1->exp == p2->exp)
        {
            newnode->coef = p1->coef - p2->coef;
            newnode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exp > p2->exp)
        {
            newnode->coef = p1->coef;
            newnode->exp = p1->exp;
            p1 = p1->next;
        }
        else
        {
            newnode->coef = -p2->coef;
            newnode->exp = p2->exp;
            p2 = p2->next;
        }

        newnode->next = NULL;

        if(p3 == NULL)
        {
            p3 = newnode;
            h = newnode;

        }
        else
        {
            h->next = newnode;
            h = newnode;
        }
    }
    while(p2 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coef = -p2->coef;
        newnode->exp = p2->exp;
        newnode->next = NULL;

        if(p3 == NULL)
        {
            p3 = newnode;
            h = newnode;
        }
        else
        {
            h->next = newnode;
            h = newnode;
        }

        p2 = p2->next;
    }
    while(p1 != NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coef = p1->coef;
        newnode->exp = p1->exp;
        newnode->next = NULL;

        if(p3 == NULL)
        {
            p3 = newnode;
            h = newnode;
        }
        else
        {
            h->next = newnode;
            h = newnode;
        }

        p1 = p1->next;
    }

    return p3;
}


struct node *multiply(struct node *p1, struct node *p2)
{
    struct node *p3 = NULL;
    struct node *h = p3;
    struct node *t2;

    while(p1 != NULL)
    {
        t2 = p2;
        while(t2 != NULL)
        {
            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            newnode->coef = p1->coef * t2->coef;
            newnode->exp = p1->exp + t2->exp;
            newnode->next = NULL;

            if(p3 == NULL)
            {
                p3 = newnode;
                h = p3;
            }
            else
            {
                h->next = newnode;
                h = newnode;
            }

            t2 = t2->next;
        }
        p1 = p1->next;
    }

    return p3;
}



int main()
{
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    struct node *p3 = NULL;

    int ch;

    printf("Create Polynomial 1\n");
    p1 = create(p1);

    printf("Create Polynomial 2\n");
    p2 = create(p2);

    while(1)
    {
        printf("\n1.Add");
        printf("\n2.Subtract");
        printf("\n3.Multiply");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                p3 = add(p1, p2);
                display(p3);
                break;

            case 2:
                p3 = subtract(p1, p2);
                display(p3);
                break;

            case 3:
                p3 = multiply(p1, p2);
                display(p3);
                break;

            case 4:
                printf("\nPoly1: ");
                display(p1);
                printf("\nPoly2: ");
                display(p2);
                break;

            case 5:
                exit(0);
        }
    }
} 