#include <stdio.h>
#define MAX_SIZE 20
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
        printf("Pushed: %d\n", item);
    } else {
        printf("Stack is full. Cannot push.\n");
    }
}
void pop() {
    if (top >= 0) {
        int popped_item = stack[top--];
        printf("Popped: %d\n", popped_item);
    } else {
        printf("Stack is empty. Cannot pop.\n");
    }
}
void display() {
    if (top >= 0) {
        printf("Stack Contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("Stack is empty.\n");
    }
}
int main() {
    push(5);
    push(10);
    push(15);
    push(20);
    display();
    pop();
    pop();
    display();
    return 0;
}
