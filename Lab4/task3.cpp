#include<iostream>
using namespace std;

int* SelectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}

void Display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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

    cout << "Unsorted array: ";
    Display(arr, size);

    cout << "Sorted Array: ";
    Display(SelectionSort(arr,size), size);

    delete[] arr;
}
