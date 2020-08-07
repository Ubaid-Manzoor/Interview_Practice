// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/

void pathVector(Node *root, int node, vector<int> &path, bool &seen){
    if(root == NULL or seen)
        return;

    path.emplace_back(root->data);

    if(root->data == node){
        seen = true;
        return;
    }

    pathVector(root->left, node, path, seen);
    if(not seen and root->left)
        path.pop_back();
    pathVector(root->right, node, path, seen);
    if(not seen and root->right)
        path.pop_back();
}

int findDist(Node* root, int a, int b) {
    vector<int> path_a,path_b;
    bool seen=false;
    pathVector(root, a, path_a, seen);
    seen=false;
    pathVector(root, b, path_b, seen);

    int lca_index=-1;

    int smaller_path_size = min(path_a.size(),path_b.size());
    for(int i = 0 ; i < smaller_path_size ; i++){
        if(path_a[i] != path_b[i]){
            lca_index = i-1;break;
        }
    }

    if(lca_index == -1)
        return abs(int(path_a.size()) - int(path_b.size()));

    return (path_a.size() - lca_index) + (path_b.size() - lca_index) - 2;
}


