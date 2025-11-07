#include<iostream>
using namespace std;

#define SIZE 5

class Dequeue {
    int arr[SIZE];
    int front, rear;

public:
    Dequeue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Dequeue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = SIZE - 1;
        }
        else {
            front--;
        }

        arr[front] = value;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Dequeue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == SIZE - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == SIZE - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = SIZE - 1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }

        cout << "Dequeue Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Dequeue dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();

    dq.deleteRear();
    dq.display();

    dq.deleteFront();
    dq.display();

    return 0;
}
