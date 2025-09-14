#include<iostream>
using namespace std;

int* InsertionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
    return arr;
}

void Display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int BinarySearch(int arr[],int val, int low, int high){
    int mid = low + (high - low)/2;
    if(low > high){
        return -1;
    }
    if(arr[mid] == val){
        return mid;
    }
    else if(arr[mid] > val){
        return BinarySearch(arr, val, low, mid-1);
    }
    else{
        return BinarySearch(arr, val, mid+1, high);
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
    Display(InsertionSort(arr,size), size);

    cout << endl << endl;

    int val;
    cout << "Enter the element to search: ";
    cin >> val;
    if(BinarySearch(arr,val,0,size) == -1){
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element found at: ";
        cout << BinarySearch(arr,val,0,size-1);
    }

    delete[] arr;
}