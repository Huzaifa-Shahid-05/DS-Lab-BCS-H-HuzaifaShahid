#include<iostream>
using namespace std;

void PrintFact(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    PrintFact(n-1);
}

void functionB(int n);
void functionA(int n) {
    if (n <= 0){  
        return;
    }
    cout << n << " ";
    functionB(n - 1);   
}

void functionB(int n) {
    if (n <= 0){   
        return;
    }
    cout << n << " ";
    functionA(n - 1);   
}

int main(){
    int n; 
    cout << "Enter num to print backwards: ";
    cin >> n;
    cout << endl;

    cout << "----Direct Recursion---- " << endl;
    PrintFact(n);
    cout << endl;

    cout << "----Indirect recursion----" << endl;
    functionA(n);

}