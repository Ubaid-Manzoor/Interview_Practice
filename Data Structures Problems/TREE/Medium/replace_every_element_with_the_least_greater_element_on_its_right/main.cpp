#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;

    return temp;
}

void insert(Node*& root, int data, int &succ){
    if(root == NULL)
        root = newNode(data);
    else if(data < root->data){
        succ = root->data;
        insert(root->left, data, succ);
    }else
        insert(root->right, data, succ);
}

/* A utility function to insert a new node with
   given data in BST and find its successor */
void replace(int arr[], int n){
    Node * root = NULL;
    for(int i = n-1; i >= 0 ; i--){
        int succ=-1;
        insert(root, arr[i], succ);

        arr[i] = succ;
    }
}

// Driver Program to test above functions
int main()
{
    int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
                  43, 3, 91, 93, 25, 80, 28 };
    int n = sizeof(arr)/ sizeof(arr[0]);

    replace(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
