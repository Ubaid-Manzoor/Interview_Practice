// C program for  nth nodes of  inorder traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node =
          (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Given a binary tree, print its nth nodes of inorder*/
void NthInorder(Node *root , int &k){
    if(root == NULL)
        return;

    NthInorder(root->left,k);

    if(k==1){
        cout<<root->data<<" ";
    }

    k--;

    NthInorder(root->right,k);
}

/* Driver program to test above functions*/
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    int n = 1;
    NthInorder(root, n);
    n = 2;
    NthInorder(root, n);
    n = 3;
    NthInorder(root, n);
    n = 4;
    NthInorder(root, n);
    n = 5;
    NthInorder(root, n);
    return 0;
}
