#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] =  new int[cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = 0;
        }
    }


    for(int i = 0; i < rows; i++){
        for(int j= 0; j < cols; j++){
            cout << "Enter seat[" << i+1 << "][" << j+1 <<"]: ";
            cin >> arr[i][j];
        }
    }

    cout << endl;
    cout << "Seats in matrix form: " <<endl;
    for(int i = 0; i < rows; i++){
        for(int j= 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
}