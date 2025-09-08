#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v) : data(v), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void InsertAtStart(int v) {
        Node* node = new Node(v);
        node->next = head;
        head = node;
    }

    void Display() {
        cout << "Displaying Elements: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

LinkedList MergeSorted(LinkedList l1, LinkedList l2) {
    LinkedList l3;
    Node* dummy = new Node(0);  
    Node* tail = dummy;

    Node* p1 = l1.head;
    Node* p2 = l2.head;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            tail->next = new Node(p1->data);
            p1 = p1->next;
        } else {
            tail->next = new Node(p2->data);
            p2 = p2->next;
        }
        tail = tail->next;
    }

    while (p1) {
        tail->next = new Node(p1->data);
        tail = tail->next;
        p1 = p1->next;
    }
    while (p2) {
        tail->next = new Node(p2->data);
        tail = tail->next;
        p2 = p2->next;
    }

    l3.head = dummy->next;
    delete dummy; 
    return l3;
}

int main() {
    LinkedList l1;
    l1.InsertAtStart(10);
    l1.InsertAtStart(8);
    l1.InsertAtStart(6);
    l1.InsertAtStart(5);
    l1.InsertAtStart(3);
    cout << "List 1: "; 
    l1.Display();

    LinkedList l2;
    l2.InsertAtStart(9);
    l2.InsertAtStart(7);
    l2.InsertAtStart(5);
    l2.InsertAtStart(4);
    l2.InsertAtStart(2);
    cout << "List 2: ";
    l2.Display();

    LinkedList l3 = MergeSorted(l1, l2);
    cout << "Merged List: ";
    l3.Display();

    return 0;
}
