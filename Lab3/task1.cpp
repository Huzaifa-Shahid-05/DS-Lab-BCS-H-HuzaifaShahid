#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v) : data(v), next(NULL) {}
};

int countNodes(Node* n) {
    int count = 0;
    while (n) {
        count++;
        n = n->next;
    }
    return count;
}

bool isPalindrome(Node* head, int count) {
    if (!head || !head->next) return true;

    Node* curr = head;
    for (int i = 0; i < count / 2; i++) {
        curr = curr->next;
    }

    if (count % 2 == 1) {
        curr = curr->next;
    }

    Node* prev = NULL;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* first = head;
    Node* second = prev;
    for (int i = 0; i < count / 2; i++) {
        if (first->data != second->data) {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(3);
    Node* n5 = new Node(2);
    Node* n6 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    int count = countNodes(n1);
    if (isPalindrome(n1, count)) {
        cout << "Linked List is Palindrome" << endl;
    } else {
        cout << "Linked List is not Palindrome" << endl;
    }

    Node* temp;
    while (n1) {
        temp = n1;
        n1 = n1->next;
        delete temp;
    }
}
