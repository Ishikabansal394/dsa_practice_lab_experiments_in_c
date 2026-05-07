#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* next;
};
struct node* createCircularLinkedList(struct node* head)
{
    printf("enter the number of nodes u want : ");
    int n;
    scanf("%d",&n);
   
    struct node* temp=NULL;
    for(int i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter the data %d : ",i+1);
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
           temp=ptr;
        

    }
    
}
temp->next=head;
    return head;
}
void displayCircularLinkedList(struct node* head){
    struct node* temp=head;
    if (head==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        do{
            printf("%d\n",temp->info);
            temp=temp->next;

        }while(temp!=head);
    }
}
struct node* insertAtBegining(struct node* head)
{
     struct node* temp=head;
    
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter info for new node : ");
    scanf("%d",&ptr->info);
    ptr->next=head;
    head=ptr;
   
    temp->next=head;
    return head;
}
struct node* insertAtEnd(struct node* head)
{
     struct node* temp=head;
    
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter info for new node : ");
    scanf("%d",&ptr->info);
    temp->next=ptr;
    ptr->next=head;
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
struct node* deleteFromBeginning(struct node* head)
{
    struct node* temp=head;
    struct node* ptr=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
   head=head->next;
    free(ptr);
    return head;
}
struct node* deleteFromEnd(struct node* head)
{
    struct node* temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    struct node* ptr=temp->next;
    temp->next=head;
    free(ptr);
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
     printf("enter the element u want to search");
        int m;
        scanf("%d",&m);
        int count=0;
        int f=0;
        if(head==NULL)
        {
            printf("can't find");
        
        }
        else
        {
            struct node*temp=head;
            if(temp->info==m)
            {
               f++;
            }
            else
            {
                temp=temp->next;
                count=1;
            while(temp!=head)
            {
                if(temp->info==m)
                {
                    f++;
                    break;
                }
                else{
                    count++;
                    temp=temp->next;
                }
            }
        }
        }
        printf("%d",count);
}
struct node* reverseLinkedList(struct node* head)
{

    if(head == NULL)
        return NULL;

    struct node* temp = head;
    struct node* prev = NULL;
    struct node* front;

    do
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;

    } while(temp != head);

    head->next = prev;

    head = prev;

    return head;

}
int main()
{
    struct node* head=NULL;
    head=createCircularLinkedList(head);
    displayCircularLinkedList(head);
     while(1){
        printf("1 for Insert at the beginning of the linked list\n");
	    printf("2 for Insert at the end of the linked list\n");
	    printf("3 for Insert at the given position of the linked list\n");
	    printf("4 for Delete from the beginning of the linked list\n");
	    printf("5 for Delete from the end of the linked list\n");
	    printf("6 for Delete from the given position of the linked list\n");
	    printf("7 for Search an element in a given linked list\n");
	    printf("8 for Reversing a linked list\n");
	    printf("9 for Traversing/ Display of linked list\n");
        printf("10 for exiting the program\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head= insertAtBegining(head);
                    displayCircularLinkedList(head);
                    break;
            case 2: head= insertAtEnd(head);
                    displayCircularLinkedList(head);
                    break;
            case 3: head= insertAtPosition(head);
                    displayCircularLinkedList(head);
                    break;
            case 4: head= deleteFromBeginning(head);
                    displayCircularLinkedList(head);
                    break;
            case 5: head= deleteFromEnd(head);
                    displayCircularLinkedList(head);
                    break;
            case 6: head= deleteFromPosition(head);
                    displayCircularLinkedList(head);
                    break;
            case 7: searchElement(head);
                    break;
            case 8: head= reverseLinkedList(head);
                    displayCircularLinkedList(head);
                    break;
           case 9: displayCircularLinkedList(head);
                     break;
           case 10: exit(0);
                     printf("exiting the program\n");
                     break;
            default: printf("Invalid choice\n");
        }

   }

}