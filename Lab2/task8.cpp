#include<iostream>
using namespace std;

int main(){
    int days;
    cout << "Enter number of days: ";
    cin >> days;
    cout << endl;
    int* size = new int[days];

    int** arr = new int*[days];

    for(int i = 0; i< days; i++){
        cout << "Enter number of times of Day" << i+1 << ": ";
        cin >> size[i];
        arr[i] = new int[size[i]];
    }
    cout << endl;

    for(int i = 0; i < days; i++){
        cout << "Enter temperatures for Day" << i+1 << ": " << endl;
        for(int j= 0; j < size[i]; j++){
            cout << "Time" << j+1 << ": ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    int* temperatures;
    temperatures = new int[days]();
    for(int i = 0; i < days; i++){
        for(int j= 0; j < size[i]; j++){
            temperatures[i]+= arr[i][j];
        }
        temperatures[i] /= size[i];
    }

    for(int i =0; i< days; i++){
        cout << "Average Temperature for Day" << i+1 << ": " << temperatures[i] << endl;
    }

    cout << endl;

    int highestAvg = temperatures[0];
    int lowestAvg = temperatures[0];
    int HighIndex = 0;
    int LowIndex = 0;
    for(int i = 0; i < days; i++){
        if(temperatures[i] > highestAvg){
            highestAvg = temperatures[i];
            HighIndex = i;
        }
        if(temperatures[i] < lowestAvg){
            lowestAvg = temperatures[i];
            LowIndex = i;
        }
    }
    cout << "Day" << HighIndex+1 << " is the hottest." << endl;
    cout << "Day" << LowIndex+1 << " is the coldest" << endl; 

    for(int i = 0; i < days; i++){
        delete[] arr[i];
    }
    delete[] arr;
}