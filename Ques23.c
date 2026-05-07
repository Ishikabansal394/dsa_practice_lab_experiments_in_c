#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void insert(int x){
    if((front == (rear + 1) % MAX))
    {
        printf("Queue is full\n");
        return;
    }
    if(front == -1 && rear == -1){
        front = rear = 0;
    } else {
        rear = (rear+1)%MAX;
    }
    queue[rear] = x;
}
void delete(){
    if(front == -1) return;
    if(front == rear){
        front = rear = -1;
    } else {
        front = (front+1)%MAX;
    }
}
void display(){
    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i+1)%MAX;
    }
}
int main(){
    insert(1); insert(2); insert(3);
    display();
    delete();
    display();
}