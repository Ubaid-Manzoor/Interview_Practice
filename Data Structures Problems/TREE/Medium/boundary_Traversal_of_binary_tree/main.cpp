// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


//struct newNode{
//    int data;
//    int left,right;
//    newNode(int data, int left, int right){
//        this->data = data;
//        this->left = left;
//        this->right = right;
//    }
//};


//void printBoundaryUtil(Node *root, vector<int> &vec, int left, int right){
//    if(root == NULL)
//        return;

//    if(left == 0 or right == 0){
//        vec.emplace_back(root->data);
//    }else if(root->left == NULL and root->right == NULL){
//        vec.emplace_back(root->data);
//    }

//    if(root->left)
//        printBoundaryUtil(root->left, vec, left + 1, right);
//    if(root->right)
//        printBoundaryUtil(root->right, vec, left, right + 1);
//}

void printLeftPart(Node *root, vector<int> &vec){
    if(root->left == NULL and root->right == NULL)
        return;

    vec.emplace_back(root->data);
    if(root->left)
        printLeftPart(root->left, vec);
    else if(root->right)
        printLeftPart(root->right, vec);
}

void printLeafs(Node *root, vector<int> &vec){
    if(not root->left and not root->right){
        vec.emplace_back(root->data);return;
    }

    if(root->left)
        printLeafs(root->left, vec);
    if(root->right)
        printLeafs(root->right, vec);
}

void printRightPart(Node * root, vector<int> &vec){
    if(root->left == NULL and root->right == NULL)
        return;

    if(root->right)
        printRightPart(root->right, vec);
    else if(root->left)
        printRightPart(root->left, vec);
    vec.emplace_back(root->data);
}


vector <int> printBoundary(Node *root){
    vector<int> vec;
    if(root == NULL)
        return vec;

    if(root->left)
        printLeftPart(root, vec);
    else
        vec.emplace_back(root->data);

    printLeafs(root,vec);

    if(root->right)
        printRightPart(root->right, vec);
    return vec;
}


















// 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8


// 6 4 9 N 10 4 5 N 10 1 9 N 8 6 1 N 5 9 3 N 6 8 7 N 4 4
















