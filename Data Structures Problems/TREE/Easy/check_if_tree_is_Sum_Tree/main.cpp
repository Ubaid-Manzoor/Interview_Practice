// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

bool isSumTree(struct Node* node);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout <<isSumTree(root) << endl;
    }
    return 1;
}// } Driver Code Ends


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
int isSumTreeUtil(Node *root, bool &is_sum_tree){
    if(not is_sum_tree)
        return 0;

    int left=0,right=0;
    if(root->left)
        left = isSumTreeUtil(root->left, is_sum_tree);
    if(root->right)
        right = isSumTreeUtil(root->right, is_sum_tree);


    if(root->left == NULL and root->right== NULL) // DONT COMPARE WHEN NODE IS LEAF AND RETURN SIMPLY THE VALUE
        return root->data;

    if(left + right != root->data)
        is_sum_tree = false;

    return left + right + root->data;

}

bool isSumTree(Node* root){
    if(root == NULL)
        return 0;

    bool is_sum_tree = true;
    isSumTreeUtil(root, is_sum_tree);
    return is_sum_tree;
}





































