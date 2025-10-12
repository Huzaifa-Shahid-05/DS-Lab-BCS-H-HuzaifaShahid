#include <iostream>
using namespace std;

int calculateFactorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * calculateFactorial(n - 1);
}

int main() {
    int num;
    cout << "Enter num: ";
    cin >> num;
    cout << "Factorial of " << num <<" is: "<< calculateFactorial(num) << endl;    
}