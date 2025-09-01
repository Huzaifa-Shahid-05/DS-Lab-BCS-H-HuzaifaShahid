#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << endl;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cout << "Enter element" << i+1 << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Array elements: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    delete[] arr;
}