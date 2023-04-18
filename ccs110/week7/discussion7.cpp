// Victoria Barnett
// 04/08/2023

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

//function prototypes
void showStack(stack<int> s);

int main()
{
    //postfix expression evaluation
    // show the status of the stack after each operation
    // show the final result
    // a = 7, b=3, c=12, d=-5, e=1

    // expected input: a b c + -
    // expected input2: a b c + - d * +

    string input;
    stack<int> s;
    int a = 7, b = 3, c = 12, d = -5, e = 1;
    int result;

    /*
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'a' || input[i] == 'b' || input[i] == 'c' || input[i] == 'd' || input[i] == 'e')
        {
            //push the values of a,b,c,d,e onto the stack
            if (input[i] == 'a')
            {
                s.push(a);
                cout << "Pushed: " << a << endl;
            }
            else if (input[i] == 'b')
            {
                s.push(b);
                cout << "Pushed: " << b << endl;
            }
            else if (input[i] == 'c')
            {
                s.push(c);
                cout << "Pushed: " << c << endl;
            }
            else if (input[i] == 'd')
            {
                s.push(d);
                cout << "Pushed: " << d << endl;
            }
            else if (input[i] == 'e')
            {
                s.push(e);
                cout << "Pushed: " << e << endl;
            }
            cout << "Stack after operands: " << endl;
            showStack(s);
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            int operand1 = s.top();
            cout << "Operand1: " << operand1 << endl;
            cout << "Stack is now: " << endl;
            showStack(s);
            s.pop();
            int operand2 = s.top();
            cout << "Operand2: " << operand2 << endl;
            cout << "Stack is now: " << endl;
            showStack(s);
            s.pop();

            if (input[i] == '+')
            {
                result = operand2 + operand1;
                cout << "Result: " << result << endl;
            }
            else if (input[i] == '-')
            {
                result = operand2 - operand1;
                cout << "Result: " << result << endl;
            }
            else if (input[i] == '*')
            {
                result = operand2 * operand1;
                cout << "Result: " << result << endl;
            }
            else if (input[i] == '/')
            {
                result = operand2 / operand1;
                cout << "Result: " << result << endl;
            }
            s.push(result);
            cout << "Pushed: " << result << endl;
        }
    }
    cout << "Final result: " << result << endl;
    cout << "Stack is now: " << endl;
    showStack(s);
    */

    /*Convert the following infix expressions to postfix form by using the algorithm we 
    discussed in the videos/pdfs.  
    Show the status of the stack and postfixExp after each step of the algorithm.*/

    // expected input: a-b+c
    // expected input2: a - (b / c * d)

    string infixExp;
    string postfixExp;
    stack<int> s2;

    cout << "Enter an infix expression: ";
    getline(cin, infixExp);

    for (int i = 0; i < infixExp.length(); i++)
    {
        if (infixExp[i] == 'a' || infixExp[i] == 'b' || infixExp[i] == 'c' || infixExp[i] == 'd' || infixExp[i] == 'e')
        {
            // append the operator to the postfix expression
            postfixExp += infixExp[i];
            cout << "Postfix expression: " << postfixExp << endl;
        }
        if (infixExp[i] == '(') {
            // push the operator onto the stack
            s2.push(infixExp[i]);
            cout << "Pushed: " << infixExp[i] << endl;
            cout << "Stack is now: " << endl;
            showStack(s2);
        }
        if (infixExp[i] == '+' || infixExp[i] == '-' || infixExp[i] == '*' || infixExp[i] == '/') {
            // push the operator onto the stack if it is empty
            if (s2.empty()) {
                s2.push(infixExp[i]);
                cout << "Pushed: " << infixExp[i] << endl;
                cout << "Stack is now: " << endl;
                showStack(s2);
            }
            else {
                // if the stack is not empty, peek at the stack. If it is an operator of greater or equal precedence, pop it and append it to the postfix expression until a ( or 
                // lower of precedence operator is found, or the stack is empty. Then push the operator onto the stack.
                //if s2 is empty
                if (s2.empty()) {
                    s2.push(infixExp[i]);
                    cout << "Pushed: " << infixExp[i] << endl;
                    cout << "Stack is now: " << endl;
                    showStack(s2);
                }
                else {
                    //if s2 is not empty
                    while (!s2.empty()) {
                        //peek at the stack
                        int peek = s2.top();
                        //if the peek is an operator of greater or equal precedence
                        if (peek == '+' || peek == '-' || peek == '*' || peek == '/') {
                            //pop it and append it to the postfix expression
                            postfixExp += peek;
                            cout << "Postfix expression: " << postfixExp << endl;
                            s2.pop();
                            cout << "Stack is now: " << endl;
                            showStack(s2);
                        }
                        //if the peek is a ( or lower of precedence operator
                        else if (peek == '(') {
                            //push the operator onto the stack
                            s2.push(infixExp[i]);
                            cout << "Pushed: " << infixExp[i] << endl;
                            cout << "Stack is now: " << endl;
                            showStack(s2);
                            break;
                        }
                    }
                }
            }

        }
        if (infixExp[i] == ')') {
            // pop the stack until a ( is found and append each operator to the postfix expression
            while (!s2.empty()) {
                //peek at the stack
                int peek = s2.top();
                //if the peek is an operator
                if (peek == '+' || peek == '-' || peek == '*' || peek == '/') {
                    //pop it and append it to the postfix expression
                    postfixExp += peek;
                    cout << "Postfix expression: " << postfixExp << endl;
                    s2.pop();
                    cout << "Stack is now: " << endl;
                    showStack(s2);
                }
                //if the peek is a (
                else if (peek == '(') {
                    //pop it
                    s2.pop();
                    cout << "Stack is now: " << endl;
                    showStack(s2);
                    break;
                }
            }
        }
        //if string end
        if (i == infixExp.length() - 1) {
            //pop the stack and append each operator to the postfix expression
            while (!s2.empty()) {
                //peek at the stack
                int peek = s2.top();
                //if the peek is an operator
                if (peek == '+' || peek == '-' || peek == '*' || peek == '/') {
                    //pop it and append it to the postfix expression
                    postfixExp += peek;
                    cout << "Postfix expression: " << postfixExp << endl;
                    s2.pop();
                    cout << "Stack is now: " << endl;
                    showStack(s2);
                }
            }
        }
}
}

void showStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}