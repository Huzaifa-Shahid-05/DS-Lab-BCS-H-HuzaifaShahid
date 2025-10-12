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
    else {
        return 0;
    }
}

bool isOp(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return true;
    } 
    else {
        return false;
    }
}

string toPostfix(string infixExp) {
    stack<char> stk;
    string postfixExp = "";

    for (char ch : infixExp) {
        if (ch == ' ') {
            continue;
        } 
        else if (isdigit(ch)) {
            postfixExp += ch;
        } 
        else if (ch == '(') {
            stk.push(ch);
        } 
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfixExp += stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.pop();
            }
        } 
        else if (isOp(ch)) {
            while (!stk.empty() && getPrecedence(stk.top()) >= getPrecedence(ch)) {
                postfixExp += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        postfixExp += stk.top();
        stk.pop();
    }

    return postfixExp;
}

int evalPostfix(string postfixExp) {
    stack<int> stk;

    for (char ch : postfixExp) {
        if (isdigit(ch)) {
            stk.push(ch - '0');
        } 
        else {
            int val2 = stk.top();
            stk.pop();
            int val1 = stk.top();
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

            stk.push(res);
        }
    }

    return stk.top();
}

int main() {
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);

    string postfixExp = toPostfix(infixExp);
    cout << "Postfix form: " << postfixExp << endl;

    int result = evalPostfix(postfixExp);
    cout << "Result: " << result << endl;

    return 0;
}
