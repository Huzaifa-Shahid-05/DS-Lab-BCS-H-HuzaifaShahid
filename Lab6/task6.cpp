#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } 
    else if (op == '*' || op == '/') {
        return 2;
    } 
    else if (op == '^') {
        return 3;
    } 
    else {
        return 0;
    }
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return true;
    } 
    else {
        return false;
    }
}

bool isRightAssociative(char op) {
    if (op == '^') {
        return true;
    } 
    else {
        return false;
    }
}

bool isDigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    } 
    else {
        return false;
    }
}

string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

string infixToPrefix(string infixExp) {
    string rev = "";
    for (int i = infixExp.length() - 1; i >= 0; i--) {
        if (infixExp[i] == '(') {
            rev += ')';
        } 
        else if (infixExp[i] == ')') {
            rev += '(';
        } 
        else {
            rev += infixExp[i];
        }
    }

    stack<char> stk;
    string prefixExp = "";

    for (char ch : rev) {
        if (isDigit(ch)) {
            prefixExp += ch;
        } 
        else if (ch == '(') {
            stk.push(ch);
        } 
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                prefixExp += stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.pop();
            }
        } 
        else if (isOperator(ch)) {
            while (!stk.empty() && isOperator(stk.top())) {
                char topOp = stk.top();
                int precTop = getPrecedence(topOp);
                int precCurr = getPrecedence(ch);
                if (precTop > precCurr || (precTop == precCurr && !isRightAssociative(ch))) {
                    prefixExp += topOp;
                    stk.pop();
                } 
                else {
                    break;
                }
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        prefixExp += stk.top();
        stk.pop();
    }

    return reverseString(prefixExp);
}

int evaluatePrefix(string prefixExp) {
    stack<int> stk;
    for (int i = prefixExp.length() - 1; i >= 0; i--) {
        char ch = prefixExp[i];
        if (isDigit(ch)) {
            stk.push(ch - '0');
        } 
        else if (isOperator(ch)) {
            int val1 = stk.top();
            stk.pop();
            int val2 = stk.top();
            stk.pop();
            int res = 0;
            if (ch == '+') {
                res = val1 + val2;
            } 
            else if (ch == '-') {
                res = val1 - val2;
            } 
            else if (ch == '*') {
                res = val1 * val2;
            } 
            else if (ch == '/') {
                res = val1 / val2;
            } 
            else if (ch == '^') {
                res = 1;
                for (int j = 0; j < val2; j++) {
                    res *= val1;
                }
            }
            stk.push(res);
        }
    }
    return stk.top();
}

int main() {
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);

    string prefixExp = infixToPrefix(infixExp);
    cout << "Prefix expression: " << prefixExp << endl;

    int result = evaluatePrefix(prefixExp);
    cout << "Evaluated result: " << result << endl;

    return 0;
}
