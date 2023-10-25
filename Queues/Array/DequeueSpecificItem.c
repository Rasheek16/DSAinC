#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 
int queue[MAX_SIZE];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}
void insert(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = item;
    printf("Inserted: %d\n", item);
}
void delete(int item) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    int found = 0;
    int tempFront = front;
    int tempRear = rear;
    while (tempFront != tempRear) {
        if (queue[tempFront] == item) {
            found = 1;
            break;
        }
        tempFront = (tempFront + 1) % MAX_SIZE;
    }
    if (queue[tempRear] == item) {
        found = 1;
    }
    if (found) {
        if (front == rear) {
            front = rear = -1;
        } else {
            while (queue[front] != item) {
                front = (front + 1) % MAX_SIZE;
            }
        }
        printf("Deleted: %d\n", item);
    } else {
        printf("Element not found in the queue.\n");
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int tempFront = front;
    printf("Queue Contents: ");
    while (tempFront != rear) {
        printf("%d ", queue[tempFront]);
        tempFront = (tempFront + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    delete(2);
    delete(5); 
    display();
    insert(5);
    display();
    return 0;
}
