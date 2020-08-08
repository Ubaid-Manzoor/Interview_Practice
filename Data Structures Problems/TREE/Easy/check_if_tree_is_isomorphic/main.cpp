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
    cout<<root1->data<<" "<<root2->data<<endl;
    if(root1 == NULL and root2 == NULL)
        return true;
    if(not root1->left and not root1->right and not root2->left and not root2->right)
        return true;

    // cout<<root1->data<<" "<<root2->data<<endl;

    bool is_isomorphic;
    if(root1->left and root2->left and root1->left->data == root2->left->data){
        is_isomorphic = isIsomorphic(root1->left, root2->left);
        cout<<"is_ : "<<is_isomorphic<<endl;
    }
    else if(root1->left and root2->right and root1->left->data == root2->right->data){
        is_isomorphic = isIsomorphic(root1->left, root2->right);
        cout<<root1->data<<" "<<root2->data;
        cout<<"is_ : "<<is_isomorphic<<endl;
    }
    else
        return false;

//    cout<<root1->data<<" "<<root2->data<<endl;
//    cout<<is_isomorphic<<endl;
//    cout<<"==="<<endl;
    if(not is_isomorphic)
        return false;

    if(not root1->right and not root2->right)
        return true;
    if(not root1->right and not root2->left)
        return true;

    if(root1->right->data == root2->right->data)
        is_isomorphic = isIsomorphic(root1->right,root2->right);
    else if(root1->right->data == root2->left->data)
        is_isomorphic = isIsomorphic(root1->right,root2->left);
    else
        return false;

    return is_isomorphic;
}





































