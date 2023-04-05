#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};


class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }


bool isEmpty() {
    return (front == NULL && rear == NULL);
}

void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    } else if (front == rear) {
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void display() 
{
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    } else {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
};


int main() 
{
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(11);
    q.display();
    q.dequeue();
    q.display();


return 0;
}