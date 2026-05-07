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
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int x)
{
    if(root == NULL)
        return create(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

struct node* search(struct node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node* findMin(struct node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
int main()
{
    struct node* root = NULL;
    int choice, x;

    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.Delete\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                if(search(root, x))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 3:
                inorder(root);
                break;

            case 4:
                preorder(root);
                break;

            case 5:
                postorder(root);
                break;

            case 6:
                printf("Enter value: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}