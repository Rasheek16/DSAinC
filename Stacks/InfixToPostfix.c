#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
void push(char item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
    } else {
        printf("Stack is full. Cannot push.\n");
        exit(1);
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
}
char peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        printf("Stack is empty. Cannot peek.\n");
        exit(1);
    }
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}
void infixToPostfix(char infix[]) {
    char postfix[MAX_SIZE];
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top >= 0 && peek() == '(') {
                pop();
            }
        } else if (isOperator(infix[i])) {
            while (top >= 0 && getPrecedence(peek()) >= getPrecedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}
int main() {
    char infixExpression[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);
    infixToPostfix(infixExpression);
    return 0;
}
