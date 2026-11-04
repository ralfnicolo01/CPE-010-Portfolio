#include <iostream>
#include <string>

struct Node {
    char symbol;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(char symbol) {
    Node* newNode = new Node();
    newNode->symbol = symbol;
    newNode->next = top;
    top = newNode;
}

char pop() {
    char symbol = top->symbol;
    Node* temp = top;
    top = top->next;
    delete temp;
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