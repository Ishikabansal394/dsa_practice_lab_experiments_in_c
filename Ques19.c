#include <stdio.h>
#include <ctype.h>
#include<string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char exp[]) {
    int i;
    for(i = 0; exp[i] != '\0'; i++) {
   
        if(isdigit(exp[i])) {
            push(exp[i] - '0');  
        }
        else {
            int val1 = pop();
            int val2 = pop();
            switch(exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

// Main function
int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%[^\n]", exp);
    printf("Result = %d", evaluatePostfix(exp));
    return 0;
}