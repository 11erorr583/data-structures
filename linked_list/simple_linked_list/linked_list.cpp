#include<iostream>
using namespace std;

void output(int data) {
    cout << data <<endl;
    return;
}

struct Node {
    int data;
    Node* next;
};

int main() {
    // Make the linked list of 5 elements
    Node* head = new Node;
    head->data = 7;

    Node* second = new Node;
    second->data = 11;

    Node* third = new Node;
    third->data = 1122;

    Node* fourth = new Node;
    fourth->data = 88;

    Node* fifth = new Node;
    fifth->data = 333;

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    // Traversing the linked list
    cout << "Original Linked List:" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        output(temp->data);
        cout << endl;
        temp = temp->next;
    }

    // Deleting the head
    Node* newHead = head->next;
    delete head;
    head = newHead;

    cout << "After deleting the head:" << endl;
    temp = head;
    while (temp != nullptr) {
        output(temp->data);
        temp = temp->next;
    }

    // Deleting the last node
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    Node* last = current->next;
    current->next = nullptr;
    delete last;

    cout << "After deleting the last node:" << endl;
    temp = head;
    while (temp != nullptr) {
        output(temp->data);
        cout << endl;
        temp = temp->next;
    }

    // Free all remaining nodes
    current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;

    return 0;
}
