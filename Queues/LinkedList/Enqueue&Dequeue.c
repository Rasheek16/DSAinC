#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
int isEmpty() {
    return front == NULL;
};
void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;  
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", item);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int item = front->data;
    struct Node* temp = front;
    front = front->next;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
    printf("Dequeued: %d\n", item);
    return item;
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    dequeue();
    enqueue(4);
    dequeue();
    dequeue();
    dequeue(); 
    return 0;
}
