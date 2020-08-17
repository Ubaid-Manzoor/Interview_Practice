#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
    int data;
    struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


void getMaxSumUtil(node*root, node* grandparent, int level, unordered_set<node*> set, int result){
    if(not root){

    }
}

int getMaxSum(node* root){

}

//  Driver code to test above methods
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}
