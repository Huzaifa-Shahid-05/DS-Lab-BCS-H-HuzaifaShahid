#include<iostream>
using namespace std;

int main(){
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;
    cout << endl;
    int* size = new int[departments];

    int** arr = new int*[departments];

    for(int i = 0; i< departments; i++){
        cout << "Enter number of employees of Department" << i+1 << ": ";
        cin >> size[i];
        arr[i] = new int[size[i]];
    }
    cout << endl;

    for(int i = 0; i < departments; i++){
        cout << "Enter salaries for Department" << i+1 << ": " << endl;
        for(int j= 0; j < size[i]; j++){
            cout << "Employee" << j+1 << ": ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < departments; i++){
        int highest = 0;
        for(int j= 0; j < size[i]; j++){
            if(arr[i][j] > highest){
                highest = arr[i][j];
            }
        }
        cout << "Highest Salary in Department" << i+1 << " : " << highest << endl;
        cout << endl;
    }

    int* salaries;
    salaries = new int[departments]();
    for(int i = 0; i < departments; i++){
        for(int j= 0; j < size[i]; j++){
            salaries[i]+= arr[i][j];
        }
        salaries[i] /= size[i];
    }
    int highestAvg = 0;
    int HighestIndex = 0;
    for(int i = 0; i < departments; i++){
        if(salaries[i] > highestAvg){
            highestAvg = salaries[i];
            HighestIndex = i+1;
        }
    }
    cout << "Department " << HighestIndex << " has the highest average salary." << endl;

    for(int i = 0; i < departments; i++){
        delete[] arr[i];
    }
    delete[] arr;
}