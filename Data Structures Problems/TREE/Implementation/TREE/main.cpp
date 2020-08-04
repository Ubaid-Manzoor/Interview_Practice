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

    int deepestNode(){
        Node *temp = root;
        Node *prev = NULL;

        if(temp->left == NULL and temp->right == NULL){
            int x = temp->data;
            free(temp);
            root = NULL;
            return x;
        }

        while(true){
            if(temp->right != NULL){
                prev = temp;
                temp = temp->right;
            }
            else if(temp->left != NULL){
                prev = temp;
                temp = temp->left;
            }
            else{
                int x = temp->data;

                if(temp == prev->left)
                    prev->left = NULL;
                else
                    prev->right = NULL;

                free(temp);
                return x;
            }
        }
    }

    bool deleteNode(int data){
        if(root == NULL)
            return false;
        else{
            queue<Node *> q;
            q.emplace(root);

            int deepestnode = deepestNode();

            if(data == deepestnode)
                return true;

            while(not q.empty()){
                if(q.front()->data == data){
                    q.front()->data = deepestnode;
                }else{
                    Node *front = q.front();
                    if(front->left != NULL)
                        q.emplace(front->left);
                    if(front->right != NULL)
                        q.emplace(front->right);
                    q.pop();
                }
            }
        }
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
    T.deleteNode(3);
    T.printTree();
}
