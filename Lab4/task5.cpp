#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int x){
    int low = 0;
    int high = size -1;

    while(low <= high && x >= arr[low] && x <= arr[high]){
        if(low <= high){
            if(arr[low] == x){
                return low;
            }
        }
        int pos = low + ((x- arr[low])*(high - low)/(arr[high] - arr[low]));
        if(arr[pos] == x){
            return pos;
        }
        if(arr[pos] < x){
            low = pos + 1;
        }
        else{
            high = pos -1;
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

    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    int y = interpolationSearch(arr, size, x);
    if(y == -1){
        cout << "Element not found." << endl;
    }
    else{
        cout << "Element found at index: " << y << endl;
    }


    delete[] arr;
}