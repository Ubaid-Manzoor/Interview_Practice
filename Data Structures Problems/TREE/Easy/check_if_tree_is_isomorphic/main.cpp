// { Driver Code Starts
#include<bits/stdc++.h>
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

bool isIsomorphic(Node *root1,Node *root2);

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        Node* root1 = buildTree(s1);
        Node* root2 = buildTree(s2);
        if(isIsomorphic(root1,root2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
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

// Return True if the given trees are isomotphic. Else return False.


bool isIsomorphic(Node *root1,Node *root2){
    if(not root1 and not root2)
        return true;
    else if(not root1 or not root2)
        return false;

    bool is_iso1,is_iso2;
    if(root1->data == root2->data){
        is_iso1 = isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right);
        is_iso2 = isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left);
        return is_iso1 or is_iso2;
    }else
        return false;
}





































