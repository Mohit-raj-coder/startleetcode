#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Use a stack to store our numbers dynamically
        stack<int> store;

        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            // Check if the current token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the two numbers to operate on. 
                // Note: The second popped number was pushed first (left operand).
                int num2 = store.top(); store.pop();
                int num1 = store.top(); store.pop();
                
                int result = 0;
                char op = token[0]; // Extract the character for the switch statement

                switch (op) {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2; // C++ truncates towards zero automatically
                        break;
                }
                // Push the calculated result back onto the stack
                store.push(result);
            } 
            else {
                // If it's a number string, convert it to an integer and push it
                store.push(stoi(token));
            }
        }

        // The final remaining element on the stack is our total result
        return store.top();
    }
};
