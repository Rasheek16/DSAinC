#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int arr[4];
    int top;
};

struct Postfix {
    struct Stack Stack;
    char s;
};

struct Postfix* initPostfix() {
    struct Postfix* postfix = (struct Postfix*)malloc(sizeof(struct Postfix));
    postfix->Stack.top = -1;
    return postfix;
}

struct Postfix* pushPostfix(struct Postfix* postfix) {
    int data;
    if (postfix->Stack.top == 3) {
        printf("Stack Overflow\n");
        return postfix;
    }
    printf("Enter data for insertion: ");
    scanf("%d", &data);
    postfix->Stack.top++;
    postfix->Stack.arr[postfix->Stack.top] = data;
    return postfix;
}

void popPostfix(struct Postfix* postfix) {
    if (postfix->Stack.top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", postfix->Stack.arr[postfix->Stack.top]);
    postfix->Stack.top--;
}

void processCharacter(struct Postfix* postfix) {
    printf("Enter character: ");
    scanf(" %c", &postfix->s);
    int a, b, result;
    switch (postfix->s) {
        case '+':
            if (postfix->Stack.top < 1) {
                printf("Not enough operands for +\n");
                break;
            }
            a = postfix->Stack.arr[postfix->Stack.top];
            postfix->Stack.top--;
            b = postfix->Stack.arr[postfix->Stack.top];
            postfix->Stack.top--;
            result = b + a;
            postfix->Stack.top++;
            postfix->Stack.arr[postfix->Stack.top] = result;
            break;
        default:
            printf("Invalid character\n");
            break;
    }
}

int main() {
    struct Postfix* postfix = initPostfix();
    
    for (int i = 0; i < 4; i++) {
        postfix = pushPostfix(postfix);
    }

    processCharacter(postfix);

    printf("Stack elements: ");
    for (int i = 0; i <= postfix->Stack.top; i++) {
        printf("%d, ", postfix->Stack.arr[i]);
    }
    printf("\n");

    free(postfix);
    return 0;
}
