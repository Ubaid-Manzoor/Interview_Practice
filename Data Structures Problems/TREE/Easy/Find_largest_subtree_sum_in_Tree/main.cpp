#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};

// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int findLargestSubtreeSumUtil(Node* root, int &maxSum){
    if(not root){
        return 0;
    }

    int leftSum = findLargestSubtreeSumUtil(root->left, maxSum);
    int rightSum = findLargestSubtreeSumUtil(root->right, maxSum);

    int currentSum = leftSum + rightSum + root->key;
    if(maxSum < currentSum)
        maxSum = currentSum;

    return currentSum;
}

int findLargestSubtreeSum(Node* root){
    if(not root)
        return 0;

    int maxSum=numeric_limits<int>::min();
    findLargestSubtreeSumUtil(root, maxSum);
    return maxSum;
}

// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */

    Node* root = newNode(-100);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(100);

    cout << findLargestSubtreeSum(root)<<endl;
    return 0;
}
