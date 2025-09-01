#include<iostream>
using namespace std;

int main(){
    int students;
    cout << "Enter number of students: ";
    cin >> students;
    cout << endl;
    int* size = new int[students];

    int** arr = new int*[students];

    for(int i = 0; i< students; i++){
        cout << "Enter number of courses of Student" << i+1 << ": ";
        cin >> size[i];
        arr[i] = new int[size[i]];
    }
    cout << endl;

    for(int i = 0; i < students; i++){
        cout << "Enter marks for Student" << i+1 << ": " << endl;
        for(int j= 0; j < size[i]; j++){
            cout << "Course" << j+1 << ": ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < students; i++){
        cout << "Average marks for Student" << i+1 << ": ";
        int marks = 0;
        for(int j= 0; j < size[i]; j++){
            marks+= arr[i][j];
        }
        cout << marks/size[i];
        cout << endl;
    }

    for(int i = 0; i < students; i++){
        delete[] arr[i];
    }
    delete[] arr;
}