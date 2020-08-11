// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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

    return root;
}

Node* LCA(Node * root , int l , int h);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
        getline(cin,s);
        scanf("%d ",&l);
        scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}// } Driver Code Ends


/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'

// Solution with logn extra space
void pathTo(Node *root, vector<Node*> &path , int to){
    if(root == NULL)
        return;

    if(path.size() > 0 and path.back()->data == to)
        return;

    path.emplace_back(root);
    if(to < root->data)
        pathTo(root->left, path, to);
    else
        pathTo(root->right, path, to);

}
Node* LCA_(Node *root, int n1, int n2)
{
    //Your code here
    vector<Node*> path1,path2;
    pathTo(root, path1, n1);
    pathTo(root, path2, n2);

    int min_size = min(path1.size(),path2.size());

    for(int i = 0 ; i < min_size; i++){
       if(path1[i]->data != path2[i]->data){
           return path1[i];
       }
   }
    return path1.size() < path2.size() ? path1.back() : path2.back();
}


// better Solution
Node* LCA(Node *root, int n1, int n2)
{
    //Your code here
    Node* current = root;

    while(true){
        if(min(n1,n2) <= current->data and current->data <= max(n1,n2))
            return current;

        if(n1 < current->data){
            current = current->left;
        else
            current = current->right;
    }
}







