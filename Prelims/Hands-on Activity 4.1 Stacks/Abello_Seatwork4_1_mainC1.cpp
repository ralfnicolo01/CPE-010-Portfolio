#include <iostream>
#include <string>

const int maxCap = 100;
char stack[maxCap];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(char symbol) {
    top++;
    stack[top] = symbol;
}

char pop() {
    char symbol = stack[top];
    top--;
    return symbol;
}

bool MatchingDelimiters(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

int main() {
    std::string expr;
    std::cout << "Enter Expression: ";
    std::cin >> expr;

    bool balanced = true;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                balanced = false;
                break;
            }
            char opening = pop();
            if (!MatchingDelimiters(opening, ch)) {
                balanced = false;
                break;
            }
        }
    }

    if (!isEmpty()) {
        balanced = false;
    }

    if (balanced) {
        std::cout << "Balanced Expression" << std::endl;
    } else {
        std::cout << "Unbalanced Expression" << std::endl;
    }

    return 0;
}