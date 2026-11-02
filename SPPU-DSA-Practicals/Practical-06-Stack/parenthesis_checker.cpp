// Practical 6: Check balanced delimiters using a stack
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 1000;

bool isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool matches(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isWellParenthesized(const string& expression) {
    char stack[MAX_SIZE];
    int top = -1;

    for (char ch : expression) {
        if (isOpening(ch)) {
            if (top == MAX_SIZE - 1) return false; // Stack overflow guard
            stack[++top] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) return false; // No opening delimiter to match
            if (!matches(stack[top], ch)) return false;
            top--;
        }
    }
    return top == -1; // No unmatched opening delimiter remains
}

int main() {
    string expression;
    cout << "Parenthesis Checker\n";
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "Expression is well parenthesized.\n";
    } else {
        cout << "Expression is NOT well parenthesized.\n";
    }
    return 0;
}
