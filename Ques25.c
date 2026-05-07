#include<stdio.h>

int s1[100], s2[100];
int top1 = -1, top2 = -1;

void enqueue(int x){
    s1[++top1] = x;
}
void dequeue(){
    if(top2 == -1){
        while(top1 != -1)
            s2[++top2] = s1[top1--];
    }
    if(top2 != -1)
        top2--;
}
void display(){
    for(int i = top2; i >= 0; i--)
        printf("%d ", s2[i]);
    for(int i = 0; i <= top1; i++)
        printf("%d ", s1[i]);
}
int main(){
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
}