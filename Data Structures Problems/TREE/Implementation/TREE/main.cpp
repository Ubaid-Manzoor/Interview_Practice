#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left=NULL;
    Node *right=NULL;

    Node(int data){
        this->data = data;
    }
};

class Tree {
private:
    Node *root=NULL;
public:
    void insert(int data){
        Node *node = new Node(data);
        if(root == NULL){
            root = node;
        }else{
            queue<Node*> q;
            q.emplace(root);

            while(true){
                Node *front = q.front();
                if(front->left == NULL){
                    front->left = node;
                    return;
                }else{
                    q.emplace(front->left);
                }

                if(front->right == NULL){
                    front->right = node;
                    return;
                }else{
                    q.emplace(front->right);
                }

                q.pop();
            }
        }
    }

    int deleteNode(int data){

    }

    void printHelper(Node * root){
        if(root == NULL)
            return;

        if(root->left != NULL)
            printHelper(root->left);
        if(root->right != NULL)
            printHelper(root->right);
        cout<<root->data<<" ";
    }

    void printTree(){
        printHelper(root);
        cout<<endl;
    }
};

int main(){
    Tree T;
    T.insert(5);
    T.insert(1);
    T.insert(3);
    T.insert(4);
    T.insert(6);
    T.printTree();
}
