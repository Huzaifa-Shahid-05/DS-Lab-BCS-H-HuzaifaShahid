#include<iostream>
using namespace std;

int** Add(int** arr1, int** arr2, int r1, int r2, int c1, int c2){
    if(r1 != r2 || c1 != c2){
        cout << "Different size of arrays." << endl;
        return nullptr;
    }

    int** result = new int*[r1];
    for(int i = 0; i < r1; i++){
        result[i] = new int[c1];
        for(int j = 0; j < c1; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}

int** Subtract(int** arr1, int** arr2, int r1, int r2, int c1, int c2){
    if(r1 != r2 || c1 != c2){
        cout << "Different size of arrays." << endl;
        return nullptr;
    }

    int** result = new int*[r1];
    for(int i = 0; i < r1; i++){
        result[i] = new int[c1];
        for(int j = 0; j < c1; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}

int main(){
    cout << "----FOR MATRIX 1----" << endl << endl;
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
        for(int j= 0; j < cols; j++){
            cout << "Enter element[" << i+1 << "][" << j+1 <<"]: ";
            cin >> arr[i][j];
        }
    }
    cout << endl;

    cout << "----FOR MATRIX 2----" << endl << endl;
    int rows2, cols2;
    cout << "Enter rows: ";
    cin >> rows2;
    cout << "Enter cols: ";
    cin >> cols2;

    int** arr2 = new int*[rows2];
    for(int i = 0; i < rows2; i++){
        arr2[i] =  new int[cols2];
    }

    for(int i = 0; i < rows2; i++){
        for(int j= 0; j < cols2; j++){
            cout << "Enter element[" << i+1 << "][" << j+1 <<"]: ";
            cin >> arr2[i][j];
        }
    }

    cout << endl;
    cout << "After Addition: " << endl;
    Add(arr,arr2,rows,rows2,cols,cols2);

    cout << endl;
    cout << "After Subtraction: " << endl;
    Subtract(arr,arr2,rows,rows2,cols,cols2);
    



    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;

    for(int i = 0; i < rows2; i++){
        delete[] arr2[i];
    }
    delete[] arr2;
}