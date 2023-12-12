#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function for in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform in-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Perform pre-order traversal
    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Perform post-order traversal
    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory for the binary tree (you may want to do this in a more sophisticated way)
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
