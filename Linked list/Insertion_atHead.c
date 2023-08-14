#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtHead(struct Node** head, int data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));

    if(new_node==NULL){
        fprintf(stderr,"Memory allocation Failed\n");
    }

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

}

void display(struct Node* head){
    struct Node* current=head;

    while(current!=NULL){
        printf("%d-> ",current->data);
        current=current->next;    
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;

    insertAtHead(&head,1);
    insertAtHead(&head,2);
    insertAtHead(&head,3);

    display(head);

    while(head!=NULL){
        struct Node *temp=head;
        head=head->next;
        free(head);
    }
}