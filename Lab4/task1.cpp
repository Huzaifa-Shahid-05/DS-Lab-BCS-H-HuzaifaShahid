#include<iostream>
using namespace std;

int LinearSearch(int arr[],int size, int a){
    for(int i = 0; i < size; i++){
        if(arr[i] == a){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cout << "Enter the size of arr: ";
    cin >> size;

    int* arr = new int[size];

    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "Enter element" << i+1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    int a;
    cout << "Enter element to search: ";
    cin >> a;

    cout << endl;
    if(LinearSearch(arr, size, a) == -1){
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element found at index: " << LinearSearch(arr, size, a) << endl;
    }

    delete[] arr;
}