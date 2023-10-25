#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10 
int deque[MAX_SIZE];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}
void insertFront(int item) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque[front] = item;
    printf("Inserted at front: %d\n", item);
}
void insertRear(int item) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    deque[rear] = item;
    printf("Inserted at rear: %d\n", item);
}
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
        return -1; 
    }
    int item = deque[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Deleted from front: %d\n", item);
    return item;
}
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return -1; 
    }
    int item = deque[rear];
    if (front == rear) {
        front = rear = -1; 
    } else {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    printf("Deleted from rear: %d\n", item);
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    int tempFront = front;
    printf("Deque Contents: ");
    while (tempFront != rear) {
        printf("%d ", deque[tempFront]);
        tempFront = (tempFront + 1) % MAX_SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    insertFront(1);
    insertRear(2);
    insertFront(3);
    insertRear(4);
    display();
    deleteFront();
    deleteRear();
    display();
    insertFront(5);
    insertRear(6);
    display();
    return 0;
}
