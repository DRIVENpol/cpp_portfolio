//  Last In, First Out (LIFO) structure

// Reverse Polish Notation (RPN) - a mathematical notation in which every operator follows all of its operands.
// 3 4 + is equivalent to 3 + 4

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Function to evaluate a postfix expression

// The function evaluatePostfix takes a string containing a postfix expression.
// It iterates over each token (number or operator) in the expression.
// If the token is a number, it pushes it onto the stack.
// If the token is an operator, it pops the two top numbers from the stack, applies the operation, and pushes the result back onto the stack.
// After processing the entire expression, the remaining element in the stack is the result of the expression.

// The & means that the function takes the argument by reference rather than by value. This is done to avoid unnecessary 
// copying of data, which can be inefficient, especially for large objects like strings.
int evaluatePostfix(const string& expression) {
    stack<int> stack;
    istringstream iss(expression);
    string token;

    // the extraction operator >> reads from the iss stream and stores the read data into token.
    while (iss >> token) {
        if (isdigit(token[0])) {
            // If the token is a number, push it onto the stack
            stack.push(stoi(token));
        } else {
            // If the token is an operator, pop the top two elements from the stack,
            // apply the operator, and push the result back onto the stack

            int operand2 = stack.top(); // Get the last element from the stack
            stack.pop(); // Remove the last element from the stack

            int operand1 = stack.top(); 
            stack.pop();

            switch (token[0]) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
            }
        }
    }
    // The result is the last element left in the stack
    return stack.top();
}

int main() {
    // For "3 4 + 2 * 7 /", the result is 2;
    string expression ;

    cout << "Input expression: ";
    getline(cin, expression);
    cout << "Result of '" << expression << "' is: " << evaluatePostfix(expression) << endl;

    return 0;
}