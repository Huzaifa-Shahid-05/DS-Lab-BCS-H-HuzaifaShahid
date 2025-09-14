#include <iostream>
#include <cstdlib> 
using namespace std;

int shellComps = 0, shellMoves = 0;
int insertComps = 0, insertMoves = 0;
int bubbleComps = 0, bubbleMoves = 0;

void ShellSort(int data[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int key = data[i];
            int j = i - gap;

            while (j >= 0 && (++shellComps && data[j] > key)) {
                data[j + gap] = data[j];
                j -= gap;
                shellMoves++;
            }
            data[j + gap] = key;
        }
    }
}

int* BubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            bubbleComps++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bubbleMoves++;
            }
        }
    }
    return arr;
}

int* InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && (++insertComps && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
            insertMoves++;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    const int SIZE = 1000;
    int arrBubble[SIZE], arrInsert[SIZE], arrShell[SIZE];

    for (int i = 0; i < SIZE; i++) {
        int num = rand() % 10000;
        arrBubble[i] = num;
        arrInsert[i] = num;
        arrShell[i] = num;
    }

    cout << "------ Original Array ------" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arrBubble[i] << " ";
    }
    cout << "\n\n";

    BubbleSort(arrBubble, SIZE);
    InsertionSort(arrInsert, SIZE);
    ShellSort(arrShell, SIZE);

    cout << "------ Sorted Array (Shell Sort Output) ------" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arrShell[i] << " ";
    }
    cout << "\n\n";

    cout << "------ Comparisons & Swaps ------" << endl;
    cout << "Bubble Sort   = " << bubbleComps  << " | " << bubbleMoves  << endl;
    cout << "Insertion Sort= " << insertComps  << " | " << insertMoves << endl;
    cout << "Shell Sort    = " << shellComps   << " | " << shellMoves  << endl;

    return 0;
}
