#include <iostream>
using namespace std;

const int MAXSIZE = 20; // maximum size of the queue

class Queue {
    private:
        int items[MAXSIZE];
        int front, rear;
    
    public:
        Queue() {
            front = rear = -1; // initially empty
        }
        
        bool isEmpty() {
            return front == -1 && rear == -1;
        }
        
        bool isFull() {
            return rear == MAXSIZE-1;
        }
        
        void enQueue(int data) {
            if (isFull()) {
                cout << "Error: Queue is full." << endl;
                return;
            }
            else if (isEmpty()) {
                front = rear = 0;
            }
            else {
                rear++;           }
            
            items[rear] = data;
            cout << data << " enqueued to the queue." << endl;
        }
        
        void deQueue() {
            if (isEmpty()) {
                cout <<"Error: Queue is empty." << endl;
                return;
            }
            else if (front == rear) {            
                front = rear = -1;
            }
            else {
                front++;
            }
        }
        
        int peek() {
            if (isEmpty()) {
                cout << "Error: Queue is empty." << endl;
                return -1;
            }
            return items[front];
        }
        
        void display() {
            if (isEmpty()) {
                cout << "Error: Queue is empty." << endl;
                return;
            }
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.display();
    
    
    q.deQueue();
    
     cout << "Front element is " << q.peek() << endl;

    cout << "Front element is " << q.peek() << endl;
    
    q.display();
    
    return 0;
}
