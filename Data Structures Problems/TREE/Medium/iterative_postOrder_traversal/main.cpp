#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node {

    int data;
    Node *left, *right;
};

// Function to create a new node with the given data
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// An iterative function to do post order
// traversal of a given binary tree
void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> s1,s2;
    s1.emplace(root);
    Node* node;

    while(not s1.empty()){
        node = s1.top();
        s1.pop();
        s2.emplace(node);

        if(node->left)
            s1.emplace(node->left);
        if(node->right)
            s1.emplace(node->right);
    }


    while(not s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

// Driver code
int main()
{
    // Let us construct the tree
    // shown in above figure
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}
