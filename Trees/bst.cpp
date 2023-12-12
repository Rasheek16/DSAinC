#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//function to create new node in heap
Node* NewNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

//function to insert a new node with given key in BST
Node* Insert(Node* node, int data) {
    if(node == nullptr)
        return NewNode(data);

    if(data < node->data)
        node->left = Insert(node->left, data);
    else if(data > node->data)
        node->right = Insert(node->right, data);

    return node;
}

//function to search a key in BST
bool Search(Node* root, int key) {
    while(root != nullptr) {
        if(key < root->data)
            root = root->left;
        else if(key > root->data)
            root = root->right;
        else
            return true;
    }
    return false;
}

int main() {
    Node* root = nullptr;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    int key = 60;
    if(Search(root, key))
        cout << "Key " << key << " is found in the BST" << endl;
    else
        cout << "Key " << key << " is not found in the BST" << endl;

    return 0;
}