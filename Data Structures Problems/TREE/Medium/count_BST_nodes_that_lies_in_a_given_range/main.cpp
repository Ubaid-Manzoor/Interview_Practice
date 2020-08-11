// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);

    return root;
}



 // } Driver Code Ends


/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

void countNodesInrange(Node *root, int l, int h, bool &startCount, int &count){
    if(root == NULL)
        return;

    countNodesInrange(root->left, l, h, startCount,count);

    cout<<root->data<<endl;
    if(root->data == l)
        startCount = true;
    if(startCount)
        count++;
    if(root->data == h)
        startCount = false;

    countNodesInrange(root->right, l, h, startCount, count);
}

int getCountOfNode(Node *root, int l, int h){
    bool startCount=false;
    int count=0;
    countNodesInrange(root, l, h, startCount, count);

    return count;
}


// { Driver Code Starts.


int main() {

    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];

        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];

        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;


    }
    return 0;
}  // } Driver Code Ends
