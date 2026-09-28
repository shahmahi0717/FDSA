#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
        {
        char ch = infix[i];
        // Ignore spaces
        if (ch == ' ')
            continue;
        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
            postfix += ' ';
        }
        // If opening bracket
        else if (ch == '(')
            {
            s.push(ch);
            }
        // If closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
                   {
                postfix += s.top();
                postfix += ' ';
                s.pop();
                    }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        // If operator
        else
        {
            while (!s.empty() && s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch))
                   {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(ch);
        }
    }
    // Move remaining operators from stack
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
