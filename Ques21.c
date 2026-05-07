#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *front = NULL, *rear = NULL;

void insert(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL){
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void delete(){
    if(front == NULL) {
        printf("que is empty\n");
        return;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);
}

void display(){
    struct node* temp = front;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    insert(10); insert(20); insert(30);
    display();
    delete();
    display();
}