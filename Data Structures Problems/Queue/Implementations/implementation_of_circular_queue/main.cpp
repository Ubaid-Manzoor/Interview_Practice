#include <iostream>
#include <limits>

using namespace std;

class circularQueue{
private:
    int rear;
    int front;
    int n = 5;
    int size=0;
    int arr[5];
public:
    circularQueue():rear(-1),front(-1){}

    void enQueue(int x){

        if(size >= n){
            cout<<"Queue is Full"<<endl;
        }else{
            if(rear == -1){
                rear = front = 0;
            }else{
                rear++;rear %= n;
            }
            arr[rear] = x;
            size++;
            cout<<x<<"added"<<endl;
        }
    }

    int deQueue(){
        if(front == -1){
            cout<<"QUEUE IS EMPTY"<<endl;
            return numeric_limits<int>::min();
        }else{
            int data = arr[front];
            if(rear == front){
                rear = front = -1;
            }else{
                front++;front %=n;
            }
            size--;
            return data;
        }
    }

    void displayQueue(){
        int currentFront = front;
        int currentRear = rear;

        int to_print[] = {0,0,0,0,0};

        while(currentFront != currentRear){
              to_print[currentFront] = arr[currentFront];
              currentFront++; currentFront %= n;
        }
        to_print[currentFront] = arr[currentFront];

        cout<<"==================================="<<endl;
        for(int i = 0 ; i < n ; i++)
            cout<<to_print[i]<<" ";
        cout<<endl<<"==================================="<<endl;

    }


    int getfront(){
        if(front != -1)
            return arr[front];
    }

    int getrear(){
        if(rear != -1)
            return arr[rear];
    }

};

int main()
{
    circularQueue q;

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    cout<<endl;
    printf("\nDeleted value = %d", q.deQueue());
    cout<<endl;
    q.displayQueue();


    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.deQueue();
    q.displayQueue();
    q.enQueue(44);
    q.displayQueue();
    q.enQueue(20);

    q.deQueue();
    q.displayQueue();
    q.deQueue();
    q.displayQueue();
    q.deQueue();
    q.displayQueue();
    q.deQueue();
    q.displayQueue();
    q.deQueue();
    q.displayQueue();
    q.deQueue();
    q.displayQueue();

    return 0;
}
