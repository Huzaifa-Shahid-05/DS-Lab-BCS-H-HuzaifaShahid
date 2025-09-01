#include<iostream>
using namespace std;

int* Resize(int newSize, int oldSize, int* arr){
    if(newSize == oldSize){
        return arr;
    }
    int* newArr = new int[newSize];

    int limit;
    if(oldSize > newSize){
        limit = newSize;
    }
    else{
        limit = oldSize;
    }

    for(int i=0; i < limit; i++){
        newArr[i] = arr[i];
    }

    delete[] arr;

    return newArr;
}

int main(){
    int n;
    cout << "Enter the number of months: ";
    cin >> n;
    cout << endl;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cout << "Enter expense of month" << i+1 << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Array elements: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "-----Resizing array-----" << endl << endl;

    int m;
    cout << "Enter new number of months: ";
    cin >> m;

    Resize(m,n,arr);

    cout << endl;

    for(int i = n; i < m; i++){
        cout << "Enter expense of month" << i+1 <<": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Array elements: " << endl;

    int sum = 0;
    for(int i = 0; i < m; i++){
        sum+= arr[i];
        cout << arr[i] << " ";
    }

    cout << endl << endl;
    cout << "Average Expense: " << sum/m << endl;



    delete[] arr;
}