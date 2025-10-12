#include <iostream>
using namespace std;

class Stack {
    int top;
public:
    int* array;
    int size;

    Stack(int n) {
        size = n;
        array = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void push(int n) {
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        } 
        else {
            top++;
            array[top] = n;
            cout << "Element " << n << " added successfully" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow. Stack is empty" << endl;
            return;
        } 
        else {
            cout << "Top element " << array[top] << " removed successfully" << endl;
            top--;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        } 
        else {
            return array[top];
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(3);

    stack.push(20);
    stack.push(40);
    stack.push(60);
    cout << endl;

    stack.display();
    cout << endl;

    cout << "Top element: " << stack.peek() << endl;
    cout << endl;

    stack.pop();
    cout << endl;

    stack.display();
    cout << endl;

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
