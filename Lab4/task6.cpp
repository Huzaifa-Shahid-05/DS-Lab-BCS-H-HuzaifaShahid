#include<iostream>
using namespace std;

int* CombSort(int arr[], int size, int &comparisons, int &swaps) {
    float shrink = 1.3;  
    int gap = size;      
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1){
            gap = 1;
        }
        swapped = false;

        for (int i = 0; i + gap < size; ++i) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
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
    int comparisons = 0, swaps = 0;
    cout << "Sorted Array: ";
    Display(CombSort(arr,size,comparisons,swaps), size);

    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    delete[] arr;
}
