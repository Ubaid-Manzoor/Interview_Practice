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
bool checkIfBalanced(Node* root){
    int leftHeight = root->left ? root->left->height : 0;
    int rightHeight = root->right ? root->right->height : 0;

    if(leftHeight - rightHeight > 1 or rightHeight - leftHeight > 1)
        return false;
    return true;
}


Node* insertToAVLUtil(Node* root, int data, Node* parent){
    if(root == NULL){
        Node* node = new Node(data);
        return node;
    }

    if(root->data == data)
        return root;

    if(data < root->data){
        root->left = insertToAVLUtil(root->left, data, parent);
    }else{
        root->right = insertToAVLUtil(root->right, data, parent);
    }

    int leftHeight = heightOf(root->left);
    int rightHeight = heightOf(root->right);
    root->height = max(leftHeight, rightHeight) + 1;

    if(leftHeight - rightHeight > 1){ // RIGHT Rotation
        if(data < root->left->data){
            // cout<<"RIGHT RIGHT"<<endl;
            return rightRotate(root);
        }else{
            // cout<<"LEFT RIGHT"<<endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }else if(rightHeight - leftHeight > 1){ // LEFT Rotation
        if(data > root->right->data){
            // cout<<"LEFT LEFT"<<endl;
            return leftRotate(root);
        }else{
            // cout<<"RIGHT LEFT"<<endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }


    return root;
}

Node* insertToAVL(Node* node, int data){
    // cout<<"data to add :: "<<data<<endl;
    Node* parent=NULL;
    Node *root = insertToAVLUtil(node, data, parent);
    return root;
}



































