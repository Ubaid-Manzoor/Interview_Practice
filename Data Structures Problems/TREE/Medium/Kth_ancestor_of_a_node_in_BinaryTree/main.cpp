#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// recursive function to calculate Kth ancestor

Node * kthAncestorDFSUtil(Node* root, int node, int &k){
//    cout<<"kthAncestorDFS("<<root->data<<","<<node<<","<<k<<")"<<endl;
    if(root == NULL)
        return NULL;

    if(root->data == node){
        return root;
    }

    Node * result=NULL;
    result = kthAncestorDFSUtil(root->left, node, k);
    if(not result)
        result = kthAncestorDFSUtil(root->right, node, k);

    if(result)
        k--;
    if(k == 0)
        return root;

    return result;
}

Node *kthAncestorDFS(Node* root, int node, int k){
    Node *result = kthAncestorDFSUtil(root, node, k);
    if(result and k <= 0)
        return result;
    else
        return NULL;
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
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node* parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;

    cout<<"===================================="<<endl;
    k = 1;
    node = 5;


    // print kth ancestor of given node
    parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;
    cout<<"===================================="<<endl;

    k = 2;
    node = 4;

    // print kth ancestor of given node
    parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;
    cout<<"===================================="<<endl;

    k = 1;
    node = 4;

    // print kth ancestor of given node
    parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;
    cout<<"===================================="<<endl;

    k = 1;
    node = 3;

    // print kth ancestor of given node
    parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;

    cout<<"===================================="<<endl;

    k = 2;
    node = 3;

    // print kth ancestor of given node
    parent = kthAncestorDFS(root,node,k);
    if (parent)
        cout << parent->data << endl;
    else
        cout<<"-1"<<endl;


    return 0;
}
