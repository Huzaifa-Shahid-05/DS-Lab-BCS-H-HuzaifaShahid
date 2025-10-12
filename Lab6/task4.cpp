#include <iostream>
using namespace std;

#define max 5

int frontIndex = -1;
int rearIndex = -1;
int queueArr[max];

bool isFull(){
    return frontIndex == (rearIndex + 1) % max;
}

bool isEmpty(){
    return frontIndex == -1;
}

void enqueue(int val){
    if (isFull()) {
        cout << "Queue is full, cannot enqueue " << val << endl;
        return;
    }
    if (isEmpty()) {
        frontIndex = rearIndex = 0;
    } 
    else{
        rearIndex = (rearIndex + 1) % max;
    }
    queueArr[rearIndex] = val;
    cout << "Enqueued: " << val << endl;
}

int dequeue() {
    if (isEmpty()){
        cout << "Queue is empty, cannot dequeue" << endl;
        return -1;
    }
    int removedVal = queueArr[frontIndex];
    if (frontIndex == rearIndex){
        frontIndex = rearIndex = -1;
    } 
    else{
        frontIndex = (frontIndex + 1) % max;
    }
    return removedVal;
}

void display() {
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue contents: ";
    int i = frontIndex;
    while (true){
        cout << queueArr[i] << " ";
        if (i == rearIndex) break;
        i = (i + 1) % max;
    }
    cout << endl;
}

int main() {
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    enqueue(55);
    cout << endl;

    display();
    cout << endl;

    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;

    cout << endl;
    display();
    cout << endl;

    enqueue(66);
    enqueue(77);

    cout << endl;
    display();
    cout << endl;

    enqueue(88);

    cout << endl;
    while (!isEmpty()) {
        cout << "Dequeued: " << dequeue() << endl;
    }

    display();
    return 0;
}
