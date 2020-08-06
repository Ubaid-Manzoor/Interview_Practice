// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int inorder[n], preorder[n];
        for(int i=0; i<n; i++)
            cin>> inorder[i];
        for(int i=0; i<n; i++)
            cin>> preorder[i];

        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout<< endl;
    }
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

Node* buildTreeUtil(int in[], int pre[],int l, int r, int &r_index,unordered_map<int,int> &hash){
    cout<<l<<" "<<r<<" root ::"<<pre[r_index]<<endl;
    if(r-l <= 0){
        r_index--;
        return NULL;
    }

    int root = pre[r_index]; // r_index is index in preOrder array
    int root_index = hash[root]; // gives index of root in inOrder array

    Node *current_root_node = new Node(root);
    current_root_node->left = buildTreeUtil(in, pre, l, root_index, ++r_index, hash);
    current_root_node->right = buildTreeUtil(in, pre, root_index+1, r, ++r_index, hash);

    return current_root_node;
}


Node* buildTree(int in[],int pre[], int n){
    unordered_map<int,int> hash;

    for(int i = 0 ; i < n ; i++){
        hash[in[i]] = i;
    }

    int r_index=0;
    return buildTreeUtil(in, pre, 0, n, r_index, hash);
}







