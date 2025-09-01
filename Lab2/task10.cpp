#include<iostream>
using namespace std;

void Search(int** arr,int arrSize, int * size, int id){
    bool found = false;
    for(int i = 0; i< arrSize; i++){
        for(int j= 0; j < size[i]; j++){
            if(arr[i][j] == id){
                found = true;
                cout << "Book Found at Cat" << i+1 << " at number" << j+1 << endl;
            }
        }
    }
    if(found == false){
        cout << "Book not found." << endl;
    }
}

int main(){
    int c;
    cout << "Enter the number of Catogaries of Books: ";
    cin >> c;
    cout << endl;

    int** arr = new int*[c];
    int* size = new int[c];
    for(int i = 0; i < c; i++){
        cout << "Enter number of books for Cat" << i+1 << ": ";
        cin >> size[i];
        arr[i] = new int[size[i]];
    }

    cout << endl;
    for(int i = 0; i< c; i++){
        cout << "Enter book id for Cat" << i+1 <<  ": " << endl;
        for(int j= 0; j < size[i]; j++){
            cout << "Enter Book ID " << j+1 << ": ";
            cin >> arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    char c1 = 'y';
    while(c1 != 'n'){
        cout << "Do you want to search for a book?(y for yes & n for no): ";
        cin >> c1;
        if(c1 == 'y'){
            int id;
            cout << "Enter book id: ";
            cin >> id;
            Search(arr,c,size,id);
        }

    };
}