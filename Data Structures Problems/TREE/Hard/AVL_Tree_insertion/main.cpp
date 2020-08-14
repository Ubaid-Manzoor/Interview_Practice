// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if(!n) return 1;
    if( n->data <= lower || n->data >= upper ) return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
    if(!n) return pair<int,bool> (0,1);

    pair<int,bool> l = isBalanced(n->left);
    pair<int,bool> r = isBalanced(n->right);

    if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

    return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
    if( !isBST(root, INT_MIN, INT_MAX) )
        cout<< "BST voilated, inorder traversal : ";

    else if ( ! isBalanced(root).second )
        cout<< "Unbalanced BST, inorder traversal : ";

    else return 1;
    return 0;
}

void printInorder(Node* n)
{
    if(!n) return;
    printInorder(n->left);
    cout<< n->data << " ";
    printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
    int ip[MAXN];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0; i<n; i++)
            cin>> ip[i];

        Node* root = NULL;

        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            if ( ! isBalancedBST(root) )
                break;
        }

        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

/*You are required to complete this method */

int heightOf(Node* root){
    return root ? root->height : 0;
}

Node* leftRotate(Node* root){
    Node *newRoot = root->right;
    root->right = newRoot->left;

    root->height = max(heightOf(root->left), heightOf(root->right)) + 1;

    newRoot->left = root;

    newRoot->height = max(heightOf(newRoot->left),heightOf(newRoot->right)) + 1;

    return newRoot;
}


Node* rightRotate(Node* root){
    Node *newRoot = root->left;
    root->left = newRoot->right;

    root->height = max(heightOf(root->left), heightOf(root->right)) + 1;

    newRoot->right = root;

    newRoot->height = max(heightOf(newRoot->left),heightOf(newRoot->right)) + 1;
    return  newRoot;
}

Node* insertToAVL(Node* root, int data){
    if(root == NULL){
        Node* node = new Node(data);
        return node;
    }

    if(root->data == data)
        return root;

    if(data < root->data){
        root->left = insertToAVL(root->left, data);
    }else{
        root->right = insertToAVL(root->right, data);
    }

    int leftHeight = heightOf(root->left);
    int rightHeight = heightOf(root->right);
    root->height = max(leftHeight, rightHeight) + 1;

    if(leftHeight - rightHeight > 1){ // RIGHT Rotation
        if(data < root->left->data) // RIGHT ROTATION
            return rightRotate(root);
        else{
            root->left = leftRotate(root->left); // LR ROTATION
            return rightRotate(root);
        }
    }else if(rightHeight - leftHeight > 1){ // LEFT Rotation
        if(data > root->right->data) // LEFT ROTATION
            return leftRotate(root);
        else{
            root->right = rightRotate(root->right); // RIGHT LEFT ROTATION
            return leftRotate(root);
        }
    }


    return root;
}



































