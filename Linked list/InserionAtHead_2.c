#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertionAtHead(struct Node *head){
    int data;
    printf("Enter data for insertion at head: ");
    scanf("%d",&data);
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

int main() {
    struct Node* head = NULL;
    struct Node* atHead = NULL;
    int numOfNodes;
    printf("Enter  number of nodes :");
    scanf("%d", &numOfNodes);
    for (int i = 1; i <= numOfNodes; i++) {
        int data;
        printf("Enter data for node: ");
        scanf("%d", &data);
        if (head == NULL) {
            head = createNode(data);
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = createNode(data);
        }
    }
    atHead=insertionAtHead(head);
    struct Node* current = atHead;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
