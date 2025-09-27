#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0){
        return total;
    }
    return sumTail(n - 1, total + n);
}

int sumNonTail(int n) {
    if (n == 0){
        return 0;
    }
    return n + sumNonTail(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    cout << "---- Tail Recursion ----" << endl;
    cout << "Sum of numbers upto " << n << ": " << sumTail(n) << endl;
    cout << endl;
    
    cout << "---- Non-Tail Recursion ----" << endl;
    cout << "Sum of numbers upto " << n << ": " << sumNonTail(n) << endl;

    return 0;
}
