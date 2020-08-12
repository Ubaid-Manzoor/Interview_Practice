// { Driver Code Starts
#include<bits/stdc++.h>

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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }


     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

bool inOrder(Node *root,Node *&prev, bool &deadFromLeft){
    if(not root)
        return false;

    if(not root->left and not root->right){
        if(root->data == 1 or (prev and abs(root->data - prev->data) <= 1))
            deadFromLeft = true;
        prev = root;
        return false;
    }

    bool isDeadEnd=false;
    isDeadEnd = inOrder(root->left, prev, deadFromLeft);

    if(isDeadEnd or (deadFromLeft and abs(root->data - prev->data) <= 1) )
        return true;
    else
        deadFromLeft = false;

    prev = root;
    isDeadEnd = inOrder(root->right, prev, deadFromLeft);

    return isDeadEnd;
}

bool isDeadEnd(Node *root){
    Node *prev=NULL;
    bool deadFromLeft=false;
    return inOrder(root, prev, deadFromLeft);
}
