#include<iostream>
using namespace std;

int* BubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

void Display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
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

    cout << endl;
    cout << "Sorted Array: ";
    Display(BubbleSort(arr,size), size);

    delete[] arr;

    
}