// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){

    if(n == 0){
        return NULL;
    }

    int root = levelOrder[0];

    int root_index;
    unordered_set<int> s;
    for(int i = iStart ; i < iEnd ; i++){
        if(inorder[i] == root){
            root_index = i;break;
        }
        else
            s.emplace(inorder[i]);
    }

    int lLevel[s.size()],rLevel[n - s.size()];
    int lSize=0,rSize=0;
    for(int i = 1; i < n ; i++){
        if(s.find(levelOrder[i]) != s.end()){
            lLevel[lSize] = levelOrder[i];lSize++;
        }else{
            rLevel[rSize] = levelOrder[i];rSize++;
        }
    }

    Node* current_root_node = new Node(root);
    current_root_node->left = buildTree(inorder, lLevel, iStart, root_index-1, lSize);
    current_root_node->right =  buildTree(inorder, rLevel, root_index+1, iEnd, rSize);

    return current_root_node;
}


































