/* Write a menu driven program for all the operations in case of doubly linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Traversing/ Display of linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* next;
    struct node* prev;
};
struct node * createDoublyLinkedList(struct node* head)
{
    int n;
    printf("enter no of terms u want :");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
   {
       struct node* newnode=(struct node *)malloc(sizeof(struct node));
       printf("enter info for new node");
       scanf("%d",&newnode->info);
       newnode->next=NULL;
       newnode->prev=NULL;
       if(head==NULL)
       {
        head=newnode;
       }
       else
       {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        temp->next->prev=temp;

       }
   }
   return head;
}
void displayDoublyLinkedList(struct node* head)
{
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }

}
struct node* insertAtBegining(struct node* head)
{
        struct node* ptr= (struct node*)malloc(sizeof(struct node));
        printf("enter the info the new node :- ");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        ptr->prev=NULL;
        if(head==NULL)
        {
            head=ptr;
        }
        else if(head->next==NULL)
        {
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
        else
        {
           head->prev=ptr;
           ptr->next=head;
           head=ptr;
        }
        return head;
}
struct node* insertAtEnd(struct node* head)
{
        struct node* ptr= (struct node*)malloc(sizeof(struct node));
        printf("enter the info the new node :- ");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        ptr->prev=NULL;
        if(head==NULL)
        {
            head=ptr;
        }
        else if(head->next==NULL)
        {
            head->next=ptr;
            ptr->prev=head;
        }
        else
        {
           struct node* temp=(struct node*)malloc(sizeof(struct node));
           temp=head;
           while(temp->next!=NULL)
           {temp=temp->next;}
           temp->next=ptr;
           ptr->prev=temp;
        }
        return head;
}
struct node* insertAtPosition(struct node* head)
{
     struct node* ptr= (struct node*)malloc(sizeof(struct node));
        printf("enter the info the new node :- ");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        ptr->prev=NULL;
        printf("enter the position where u want to insert");
        int m;
        scanf("%d",&m);
        int count=0;
        if(head==NULL)
        {
            printf("can be inserted at head only");
            head=ptr;
        }
        else
        {
           
           struct node* temp;
           temp=head;
           while(count!=m-2)
           {count++;
            temp=temp->next;}
           struct node* temp2;
           temp2=temp->next;
           temp->next=ptr;
           ptr->next=temp2;
           temp2->prev=ptr;
           ptr->prev=temp;

           
        }
     return head;
}
struct node* deleteFromBeginning(struct node *head)
{
   if(head==NULL)
        {
            printf("cant be deleted list is empty");
            return head;
        }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node*temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
struct node* deleteFromEnd(struct node *head)
{
     if(head==NULL)
        {
            printf("cant be deleted list is empty");
        }
        else if(head->next==NULL)
        {
            free(head);
            head=NULL;
        }
        else
        {
           struct node* temp;
           temp=head;
           while(temp->next->next!=NULL)
           {temp=temp->next;}
           struct node*temp2=temp->next;
           temp->next=NULL;

           free(temp2);
           
        }
        return head;
}
struct node* deleteFromPosition(struct node* head)
{
        printf("enter the position where u want to delete");
        int m;
        scanf("%d",&m);
        int count=0;
        if(head==NULL)
        {
            printf("can't be deleted");
        
        }
        else
        {
           struct node* temp;
           temp=head;
           while(count!=m-2)
           {count++;
            temp=temp->next;}
           struct node*temp2=temp->next;
           temp->next=temp2->next;
           if(temp2->next!=NULL)
           {
               temp2->next->prev=temp;
           }
           free(temp2);
        }
     return head;
    }
    void searchElement(struct node* head)
{
    printf("enter the element to want to search");
    int m;
    scanf("%d",&m);
    struct node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count=count+1;
        if(temp->info==m)
        {
            printf("found at position %d\n",count);
            return;
        }
        else
        {
            temp=temp->next;
        }
    }

}
int main()
{
    struct node* head=NULL;
    head=createDoublyLinkedList(head);
    displayDoublyLinkedList(head);
     while(1){
        printf("1 for Insert at the beginning of the linked list\n");
	    printf("2 for Insert at the end of the linked list\n");
	    printf("3 for Insert at the given position of the linked list\n");
	    printf("4 for Delete from the beginning of the linked list\n");
	    printf("5 for Delete from the end of the linked list\n");
	    printf("6 for Delete from the given position of the linked list\n");
	    printf("7 for Search an element in a given linked list\n");
	    printf("8 for Traversing/ Display of linked list\n");
        printf("9 for exiting the program\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head= insertAtBegining(head);
                    displayDoublyLinkedList(head);
                    break;
            case 2: head= insertAtEnd(head);
                    displayDoublyLinkedList(head);
                    break;
            case 3: head= insertAtPosition(head);
                    displayDoublyLinkedList(head);
                    break;
            case 4: head= deleteFromBeginning(head);
                    displayDoublyLinkedList(head);
                    break;
            case 5: head= deleteFromEnd(head);
                    displayDoublyLinkedList(head);
                    break;
            case 6: head= deleteFromPosition(head);
                    displayDoublyLinkedList(head);
                    break;
            case 7: searchElement(head);
                    break;
           case 8: displayDoublyLinkedList(head);
                     break;
           case 9: exit(0);
                     printf("exiting the program\n");
                     break;
            default: printf("Invalid choice\n");
        }

   }

}
