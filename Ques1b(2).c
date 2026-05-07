#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    struct node* root = create(10);
    root->left = create(20);
    root->right = create(30);
    root->left->left = create(40);
    root->left->right = create(50);

    printf("%d", root->data);
}