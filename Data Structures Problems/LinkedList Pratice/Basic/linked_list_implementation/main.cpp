#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node *address=NULL){
        this->data = data;
        this->next = address;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList(){
        head = NULL;
    }

    // INSERTING FUNCTIONS...

    void append(int data){
        if(head == NULL){
            head = new Node(data);
            return;
        }

        Node *current = head;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = new Node(data);
    }

    void prepend(int data){
        Node *newHead = new Node(data);
        newHead->next = head;
        head = newHead;
    }

    void insertAfter(int after, int data){
        if(head != NULL){
            Node *current = head;
            while(current->data != after){
                current = current->next;
            }
            Node *node = new Node(data, current->next);
            current->next = node;
        }else{
            cout<<"LIST IS EMPTY!!"<<endl;
        }
    }

    // DELETING FUNCTION...
    void deleteNode(int key){
        if(head == NULL){
            cout<<"LIST IS EMPTY!!";
            return;
        }
        if(head->data == key){
            Node *newHead = head->next;
            free(head);
            head = newHead;
            return;
        }

        Node *prev,*current=head;
        while(current != NULL and current->data != key){
            prev = current;
            current = current->next;
        }

        if(current == NULL){
            cout<<"NOT PRESENT"<<endl;
            return;
        }

        prev->next = current->next;
        free(current);
    }

    void deleteAt(int position=0){

        if(head == NULL){
            cout<<"LIST IS EMPTY!!";
            return;
        }

        Node *prev=NULL,*current=head;
        int current_position = 0;
        while(current_position != position){
            prev = current;
            current = current->next;
            position++;
        }

        if(current == head){
            head = head->next;
            free(current);
            return;
        }

        prev->next = current->next;
        free(current);
    }


    void printList(){
        Node *current = head;
        while(current->next != NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<current->data<<endl;
    }

};


int main(){
    LinkedList list;
    list.append(2);
    list.append(2);
    list.append(2);
    list.append(2);
    list.append(6);
    list.append(5);
    list.insertAfter(6,7);
//    list.deleteNode(2);
//    list.deleteNode(5);
//    list.deleteNode(6);
//    list.deleteNode(10);
    list.deleteAt(0);
    list.printList();
}
