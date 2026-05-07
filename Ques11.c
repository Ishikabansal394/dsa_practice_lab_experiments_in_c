#include<stdio.h>
#include<stdlib.h>
struct node {
     int info;
     struct node* next;

};
struct node* createlinkedlist(struct node* head){
    printf("enter the number of elements you want to have : ");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        struct node* ptr= (struct node*)malloc(sizeof(struct node));
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the info the node :- ");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
        if(head==NULL)
        {
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;

        }

    }
    return head;
}
void display(struct node* head)
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
        if(head==NULL)
        {
            head=ptr;
        }
        else
        {
           struct node* temp=(struct node*)malloc(sizeof(struct node));
           temp=head;
           ptr->next=temp;
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
        if(head==NULL)
        {
            head=ptr;
        }
        else
        {
           struct node* temp=(struct node*)malloc(sizeof(struct node));
           temp=head;
           while(temp->next!=NULL)
           {temp=temp->next;}
           temp->next=ptr;
        }
        return head;
}
struct node* insertAtPosition(struct node* head)
{
     struct node* ptr= (struct node*)malloc(sizeof(struct node));
        printf("enter the info the new node :- ");
        scanf("%d",&ptr->info);
        ptr->next=NULL;
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
    struct node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* deleteFromEnd(struct node *head)
{
     if(head==NULL)
        {
            printf("cant be deleted list is empty");
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
           temp->next=temp->next->next;
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
struct node* reverseLinkedList(struct node* head)
{
    struct node* temp=head;
    struct node*prev=NULL;
    struct node* front=temp->next;
    while(temp!=NULL)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;


    }
    return prev;
}
struct node* mergeTwoLinkedLists(struct node* head)
{
     struct node* head2=NULL;
     head2=createlinkedlist(head2);
     struct node* temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=head2;

     return head;
}
void detectLoop(struct node* head)
{
   struct node* slow = head;
   struct node* fast = head;
   while (fast != NULL && fast->next != NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
       if (slow == fast)
       {
           printf("Loop detected\n");
           return;
       }
   }
   printf("No loop detected\n");
}
int main()
{
    struct node* head=NULL;
   head=createlinkedlist(head);
   display(head);
   while(1){
        printf("1 for Insert at the beginning of the linked list\n");
	    printf("2 for Insert at the end of the linked list\n");
	    printf("3 for Insert at the given position of the linked list\n");
	    printf("4 for Delete from the beginning of the linked list\n");
	    printf("5 for Delete from the end of the linked list\n");
	    printf("6 for Delete from the given position of the linked list\n");
	    printf("7 for Search an element in a given linked list\n");
	    printf("8 for Reversing a linked list\n");
	    printf("9 for Merging two linked list\n");
	    printf("10 for Traversing/ Display of linked list\n");
	    printf("11 for Detect loop in a linked list\n");
        printf("12 for exiting the program\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head= insertAtBegining(head);
                    display(head);
                    break;
            case 2: head= insertAtEnd(head);
                    display(head);
                    break;
           case 3: head= insertAtPosition(head);
                    display(head);
                    break;
           case 4: head= deleteFromBeginning(head);
                    display(head);
                    break;
           case 5: head= deleteFromEnd(head);
                    display(head);
                    break;
           case 6: head= deleteFromPosition(head);
                    display(head);
                    break;
           case 7: searchElement(head);
                    break;
           case 8: head= reverseLinkedList(head);
                    display(head);
                    break;
           case 9: head= mergeTwoLinkedLists(head);
                    display(head);
                    break;
           case 10: display(head);
                     break;
           case 11: detectLoop(head);
                     break;
           case 12: exit(0);
                     printf("exiting the program\n");
                     break;
            default: printf("Invalid choice\n");
        }

   }
}