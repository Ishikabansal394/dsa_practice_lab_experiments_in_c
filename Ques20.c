#include<stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void insert(int x){
    if(rear == MAX-1) {
        printf("Que is full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}
void delete(){
    if(front == -1 || front > rear) {
        printf("que is empty\n");
        return;
    }
    front++;
}
void display(){
    if(front == -1 || front > rear) {
        printf("que is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}
int main(){
    insert(10); insert(20); insert(30);
    display();
    delete();
    display();
}