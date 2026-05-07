#include<stdio.h>
#include<string.h>
char queue[100];
int front = 0, rear = -1;

void enqueue(char x){
    queue[++rear] = x;
}

char dequeue(){
    return queue[front++];
}
int main(){
    char str[100];
    int temp = 1;
    scanf("%s", str);

    for(int i = 0; str[i]; i++)
        enqueue(str[i]);

    for(int i = 0; str[i]; i++){
        if(str[i] != dequeue()){
            temp = 0;
            break;
        }
    }
    if(temp) printf("Palindrome");
    else printf("Not Palindrome");
}