// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int setHeights(Node* n)
{
    if(!n) return 0;
    n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
    return n->height;
}

Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    setHeights(root);
    return root;
}

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

struct Node* deleteNode(struct Node* root, int data);
void printTree(Node* root, string &position){
    if(root == NULL)
        return;

    cout<<"d : "<<root->data<<" h : "<<root->height<<endl;
    if(root->left){
        position += "L";
        cout<<position;
        printTree(root->left,position);
        position.pop_back();
    }
    if(root->right){
        position += "R";
        cout<<position;
        printTree(root->right, position);
        position.pop_back();
    }
}

int main()
{
    int t;
    cin>>t;
    getchar();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        int n;
        cin>> n;
        int ip[n];
        for(int i=0; i<n; i++)
            cin>> ip[i];

        for(int i=0; i<n; i++)
        {
            cout<<"to delete : "<<ip[i]<<endl;
            root = deleteNode(root, ip[i]);
            if( !isBalancedBST(root) )
                break;
        }
        if(root==NULL)
            cout<<"null";
        else
            printInorder(root);
        cout<< endl;

        getline(cin,s); // to deal with newline char
    }
    return 1;
}
// } Driver Code Ends


/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/

int heightOf(Node* root){
    return root ? root->height : 0;
}

Node * leftRotation(Node* root){
    Node *newNode = root->right;
    root->right = newNode->left;

    root->height = max(heightOf(root->left), heightOf(root->right)) + 1;

    newNode->left = root;

    newNode->height = max(heightOf(newNode->left), heightOf(newNode->right)) + 1;

    return newNode;
}

Node * rightRotation(Node* root){
    Node *newNode = root->left;
    root->left = newNode->right;
    root->height = max(heightOf(root->left), heightOf(root->right)) + 1;

    newNode->right = root;

    newNode->height = max(heightOf(newNode->left), heightOf(newNode->right)) + 1;

    return newNode;
}

int minValue(Node* root){
    Node *current = root;

    while(current->left != NULL){
        current = current->left;
    }

    return current->data;
}

Node* deleteNode(Node* root, int data){
    Node* temp = root;
    if(not root)
        return NULL;
    else if(root->data == data){
        if(not root->left and not root->right){
            free(root);
            return NULL;
        }else if(not root->left){
            temp = root->right;
            free(root);
        }else if(not root->right){
            temp = root->left;
            free(root);
        }else{
            int minData = minValue(root->right);
            root->right = deleteNode(root->right, minData);
            root->data = minData;
            temp = root;
        }
    }else if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else{
        root->right = deleteNode(root->right, data);
    }

    root = temp;

    int leftHeight = heightOf(root->left);
    int rightHeight = heightOf(root->right);
    root->height = max(leftHeight, rightHeight) + 1;

    if(leftHeight - rightHeight > 1){
        if(heightOf(root->left->left) >= heightOf(root->left->right)){
            // cout<<"RIGHT RIGHT"<<endl;
            return rightRotation(root);
        }else{
            // cout<<"LEFT RIGHT"<<endl;
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }else if(rightHeight - leftHeight > 1){
        if(heightOf(root->right->right) >= heightOf(root->right->left)){
            // cout<<"LEFT LEFT"<<endl;
            return leftRotation(root);
        }else{
            // cout<<"RIGHT LEFT"<<endl;
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }


    return temp;
}






























