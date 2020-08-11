// { Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);


}

int main ()
{
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

    printInorder(root);
    printf("\n");
}
    return 0;
}
// } Driver Code Ends


/*struct Node
{
    int data;
    Node *left, *right;
};*/

int findIndex(int post[], int left, int right, int root){
    for(int i = left; i <= right ; i++){
        if(post[i] > root)
            return i;
    }

    return right+1;
}


// THIS METHOD IS O(NLOGN)
Node *constructTreeUtil(int post[], int left, int right){
    if(left > right){
        return NULL;
    }

    Node* root = new Node(post[right]);
    int newIndex = findIndex(post, left, right-1, root->data);

    root->left = constructTreeUtil(post, left, newIndex-1);
    root->right = constructTreeUtil(post, newIndex, right-1);

    return root;
}


Node *constructTree (int post[], int size){
    return constructTreeUtil(post, 0, size-1);
}






















