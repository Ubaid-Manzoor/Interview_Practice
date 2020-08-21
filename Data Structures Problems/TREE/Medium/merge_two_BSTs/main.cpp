// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



vector<int> merge(Node *root1,Node *root2);

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



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s;
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);

       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
vector<int> merge(Node *root1, Node *root2){
   vector<int> merged_bst;

   stack<Node*> s1,s2;
   s1.emplace(new Node(INT_MAX));
   s2.emplace(new Node(INT_MAX));
   Node* current1 = root1;
   Node* current2 = root2;
   bool traverse1=true,traverse2=true;

   while(current1 or current2 or (not s1.empty() and not s2.empty()) ){
       while(traverse1 and current1 != NULL){
           s1.emplace(current1);
           current1 = current1->left;
       }

       while(traverse2 and current2 != NULL){
           s2.emplace(current2);
           current2 = current2->left;
       }

       if(s1.top()->data <= s2.top()->data){
           merged_bst.emplace_back(s1.top()->data);
           current1 = s1.top()->right;
           s1.pop();
           traverse1=true;traverse2=false;
       }else{
           merged_bst.emplace_back(s2.top()->data);
           current2 = s2.top()->right;
           s2.pop();
           traverse1=false;traverse2=true;
       }
   }


   merged_bst.pop_back();
   return merged_bst;
}



































