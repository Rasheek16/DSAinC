#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};


struct Node* insertionAtRandomPosition(struct Node* head){
    printf("Enter data for insertion: ");
    int data;
    scanf("%d",&data);
    struct Node* newNode=createNode(data);
    printf("Enter position of new node: ");
    int position;
    scanf("%d",&position);
    struct Node* current = head;
    int count=0;
    while(current != NULL){
        current=current->next;
        count++;
    }
    current=head;
     if(position>count){
        printf("Error not enough elements\n");
        }else{
            int x;
            for (x=1; x<position; x++)
            current = current->next;
            x++;
            }
    newNode->next=current->next;
    current->next=newNode;
        
 
    return head;
}


int main(){
    printf("Enter number of nodes :");
    int numOfNodes;
    int data;
    struct Node* head=NULL;
    scanf("%d",&numOfNodes);
    for(int i=0; i<numOfNodes; i++){
        printf("Enter data for node %d :",i+1);
        scanf("%d",&data);
        if(head==NULL){
            head=createNode(data);
            }else{
                struct Node* current = head;
                while(current->next!=NULL){
                    current = current->next;
                }
                current->next=createNode(data);
            }
    }

    struct Node* atPosition=insertionAtRandomPosition(head);


    struct Node* currentNew=atPosition;

    while (currentNew!= NULL) {
        printf("%d -> ", currentNew->data);
        currentNew = currentNew->next;
    }
    printf("NULL\n");
    
    return 0;
}





