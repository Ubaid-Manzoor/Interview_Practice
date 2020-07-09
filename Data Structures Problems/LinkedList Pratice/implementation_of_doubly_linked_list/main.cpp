#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data):data{data},next{NULL},prev{NULL}{}
};

class doubly_ll{
    Node * head;
public:
    doubly_ll():head{NULL}{}
    void append(int data){
        if(head == NULL){
            head = new Node(data);
            return;
        }

        Node * current = head;
        while(current->next != NULL)
            current = current->next;

        Node *node = new Node(data);
        node->prev = current;
        current->next = node;
    }

    void prepend(int data){
        if(head == NULL){
            head = new Node(data);
            return;
        }

        Node *node = new Node(data);
        head->prev = node;
        node->next = head;
        head = node;
    }

    void insertAt(int data,int position){
        if(head == NULL or position < 1)
            return;

        if(position == 1){
            Node *node = new Node(data);
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        int current_position=1;
        Node *current=head;

        while(current != NULL and current_position != position - 1){
            current = current->next;
            current_position++;
        }

        if(current == NULL)
            return;

        Node *node = new Node(data);

        node->next = current->next;
        node->prev = current;

        if(current->next != NULL)
            current->next->prev = node;
        current->next = node;
    }
    void deleteNode(int data){
        if(head == NULL)
            return;

        Node *current = head;
        Node * prev=NULL;

        while(current != NULL and current->data != data){
            prev = current;
            current = current->next;
        }

        if(current == NULL)
            return;

        if(prev == NULL)
            head = current->next;
        else
            prev->next = current->next;

        if(current->next != NULL)
            current->next->prev = prev;

        free(current);
    }

    void deleteAt(int position){
        if(head == NULL or position < 1)
            return;

        Node * current = head;
        int current_position=1;
        while(current != NULL and current_position != position){
            current = current->next;
            current_position++;
        }

        if(position == 1){
            current->next->prev = NULL;
            head = current->next;
            free(current);
            return;
        }

        if(current == NULL)
            return;

        if(current->next != NULL)
            current->next->prev = current->prev;
        current->prev->next = current->next;

        free(current);
    }

    void printList(){
        Node *current = head;
        while(current != NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

};

int main(){
    doubly_ll dl;
    dl.append(4);
//    dl.prepend(1);
//    dl.prepend(0);
//    dl.append(5);
//    dl.append(6);
    dl.printList();
    dl.deleteNode(4);
//    dl.insertAt(22,8);
//    dl.deleteAt(5);
    dl.printList();
}
