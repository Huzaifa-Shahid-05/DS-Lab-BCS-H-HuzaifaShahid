#include <iostream>
using namespace std;

#define max 100

int frontIndex = -1;
int rearIndex = -1;
int queueArr[max];

bool isFull() {
    return rearIndex == max - 1;
}

bool isEmpty() {
    return frontIndex == -1 || frontIndex > rearIndex;
}

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue is full, cannot enqueue " << val << endl;
        return;
    }
    if (frontIndex == -1) {
        frontIndex = 0;
    }
    queueArr[++rearIndex] = val;
    cout << "Enqueued: " << val << endl;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, cannot dequeue" << endl;
        return -1;
    }
    int removedVal = queueArr[frontIndex++];
    if (frontIndex > rearIndex) {
        frontIndex = rearIndex = -1;
    }
    return removedVal;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue contents: ";
    for (int i = frontIndex; i <= rearIndex; ++i) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(15);
    enqueue(25);
    enqueue(35);
    enqueue(45);
    cout << endl;

    display();
    cout << endl;

    cout << "Dequeued: " << dequeue() << endl;
    cout << endl;

    display();
    cout << endl;

    enqueue(55);
    enqueue(65);
    enqueue(75);
    cout << endl;

    display();

    cout << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;

    cout << endl;
    display();
    cout << endl;

    while (!isEmpty()) {
        cout << "Dequeued: " << dequeue() << endl;
    }

    display();
    return 0;
}
