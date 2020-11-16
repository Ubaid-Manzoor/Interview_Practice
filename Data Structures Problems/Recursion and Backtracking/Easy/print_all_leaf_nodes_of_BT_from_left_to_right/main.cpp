#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// function to print leaf
// nodes from left to right
void printLeafNodes(Node *root) {
    if(not root)
        return;
    if(root->left == NULL and root->right == NULL){
        cout<<root->data<<" ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}


// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in
    // above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    // print leaf nodes of the given tree
    printLeafNodes(root);

    return 0;
}
