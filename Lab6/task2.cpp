#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* topNode = nullptr;

void push(int val) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Heap Overflow!" << endl;
        exit(1);
    }
    newNode->value = val;
    newNode->next = topNode;
    topNode = newNode;
    cout << "Pushed " << val << " onto the stack." << endl;
}

void display() {
    if (topNode == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* current = topNode;
    cout << "Stack elements: ";
    while (current != nullptr){
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    cout << endl;
    display();
    return 0;
}
