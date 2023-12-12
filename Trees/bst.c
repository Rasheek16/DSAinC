#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    // Base case: if the tree is empty, create a new node
    if (root == NULL) {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to find the node with the minimum key value in a BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return root;
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest
        // in the right subtree) and copy its key to this node
        struct Node* temp = findMin(root->right);
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert keys into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print in-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a key from the BST
    int keyToDelete = 20;
    root = deleteNode(root, keyToDelete);
    printf("After deleting %d, in-order traversal: ", keyToDelete);
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory for the BST (you may want to do this in a more sophisticated way)
    free(root);

    return 0;
}
