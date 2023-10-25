#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = -1, rear = -1;
int isFull() {
    return rear == MAX_SIZE - 1;
}
int isEmpty() {
    return front == -1;
}
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    queue[++rear] = item;
    printf("Enqueued: %d\n", item);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int item = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
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
