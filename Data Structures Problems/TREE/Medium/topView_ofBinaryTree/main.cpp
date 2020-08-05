// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

void topView(struct Node *root){
    queue<pair<Node*,int>> q;
    map<int,int> hash;


    q.emplace(make_pair(root,0));
    hash[0] = root->data;
    while(not q.empty()){
        Node *front = q.front().first;
        int curr_position = q.front().second;

        if(front->left){
            q.emplace(make_pair(front->left,curr_position - 1));
            if(hash.find(curr_position - 1) == hash.end())
                hash[curr_position - 1] = front->left->data;
        }

        if(front->right){
            q.emplace(make_pair(front->right,curr_position + 1));
            if(hash.find(curr_position + 1) == hash.end())
                hash[curr_position + 1] = front->right->data;
        }

        q.pop();
    }

    for(pair<int,int> p: hash){
        cout<<p.second<<" ";
    }
}











