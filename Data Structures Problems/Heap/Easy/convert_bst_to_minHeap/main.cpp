#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void insertInBinarySearchTree(Node* &head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }

    if(data < head->data)
        insertInBinarySearchTree(head->left, data);
    else
        insertInBinarySearchTree(head->right, data);
}

void printInorder(Node* head){
    if(head == NULL)
        return;

    printInorder(head->left);
    cout<<head->data<<" ";
    printInorder(head->right);
}

void printPreorder(Node* head){
    if(head == NULL)
        return;

    cout<<head->data<<" ";
    printPreorder(head->left);
    printPreorder(head->right);
}
void insertFromArray(Node* &head,vector<int> array){
    for(int data:array)
        insertInBinarySearchTree(head,data);
}

void inOrderTraversal(Node* head, vector<int> &arr){
    if(head == NULL)
        return;

    inOrderTraversal(head->left, arr);
    arr.emplace_back(head->data);
    inOrderTraversal(head->right, arr);
}

void convertToMinHeap(Node* head, vector<int> inOrderArr, int &index){
    if(head == NULL)
        return;

    head->data = inOrderArr[index++];
    convertToMinHeap(head->left, inOrderArr, index);
    convertToMinHeap(head->right, inOrderArr, index);
}


void binaryTreeToMinHeap(Node* &head){
    vector<int> inOrderArr;
    inOrderTraversal(head, inOrderArr);

    int index=0;
    convertToMinHeap(head, inOrderArr, index);
}


int main(){
    Node* head = NULL;

    vector<int> arr = {4,2,6,1,3,5,7};
    insertFromArray(head,arr);

    binaryTreeToMinHeap(head);

//    cout<<"OUTPUT"<<endl;
    cout<<"InOrder :: "<<endl;
    printInorder(head);
    cout<<endl;
    cout<<"preOrder :: "<<endl;
    printPreorder(head);
}
