#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int arr[4];
    int top;
};

struct Stack* initStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

struct Stack* pushStack(struct Stack* stack) {
    int data;
    if (stack->top == 4) {
        printf("Stack Overflow\n");
        return stack;
    }
    printf("Enter data for insertion: ");
    scanf("%d", &data);
    stack->top++;
    stack->arr[stack->top] = data;
    return stack;
}

struct Stack* popStack(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return stack;
    }
    printf("Popped element: %d\n", stack->arr[stack->top]);
    stack->top--;
    return stack;
}

int main() {
    struct Stack* stack = initStack();
    for (int i = 0; i <4; i++) {
        pushStack(stack);
    }

    popStack(stack);

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d, ", stack->arr[i]);
    }
    printf("\n");

    free(stack);
    return 0;
}
