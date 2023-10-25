#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 20
int stack[MAX_SIZE];
int top = -1;
void push(int item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
    } else {
        printf("Stack is full. Cannot push.\n");
        exit(1);
    }
}
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
}
int evaluatePostfixExpression(char postfix[]) {
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();

            switch (postfix[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid character in postfix expression\n");
                    exit(1);
            }
        }
    }
    if (top == 0) {
        return stack[top];
    } else {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfixExpression[] = "23*5+";
    int result = evaluatePostfixExpression(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}
