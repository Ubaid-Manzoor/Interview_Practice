#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left,  *right;
};



/* Recursive function to construct binary tree */


// This functions converts an unbalanced BST to
// a balanced BST

// Utility function to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


void preOrder(Node* node, string side=""){
    if (node == NULL)
        return;

    cout<<side<<""<<node->data<<endl;
//    printf("%d ", node->data);
    preOrder(node->left, side+"L");
    preOrder(node->right, side+"R");
}

void fillVecOfNodes(Node* root, vector<int> &nodes){
    if(root == NULL)
        return;


    fillVecOfNodes(root->left, nodes);
    nodes.emplace_back(root->data);
    fillVecOfNodes(root->right, nodes);
}


Node* createBalancedBST(vector<int> nodes, int l, int r){
    if(l > r)
        return NULL;

    int middle = (l + (r + 1)) / 2;

    Node *root = newNode(nodes[middle]);

    root->left = createBalancedBST(nodes, l, middle-1);
    root->right = createBalancedBST(nodes, middle+1, r);

    return root;
}

Node *buildTree(Node* root){
    vector<int> nodes;

    fillVecOfNodes(root, nodes);

    return createBalancedBST(nodes,  0, nodes.size()-1);
}

// Driver program
int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */

    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    root = buildTree(root);

    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);

    return 0;
}
