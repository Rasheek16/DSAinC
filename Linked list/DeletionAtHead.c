#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }
            
            free(current);
            return;
        }
        current = current->next;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    printf("Doubly Linked List: ");
    printList(head);
    deleteNode(&head, 2);
    printf("Doubly Linked List after deleting 2: ");
    printList(head);
    return 0;
}
