#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

void infix_to_prefix(string infix)
{
    stack<char> st;
    string expression = "";

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];

        if (isalnum(c))
            expression += c;
        else if (c == ')')
            st.push(c);
        else if (c == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                expression += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else if (is_operator(c))
        {
            while (!st.empty() && is_operator(st.top()) &&
                   precedence(st.top()) > precedence(c))
            {
                expression += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        expression += st.top();
        st.pop();
    }

    reverse(expression.begin(), expression.end());
    cout << "Infix_to_prefix: " << expression << endl;
}

void infix_to_postfix(string infix)
{
    stack<char> st;
    string expression = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
            expression += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                expression += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else if (is_operator(c))
        {
            while (!st.empty() && is_operator(st.top()) &&
                   precedence(st.top()) >= precedence(c))
            {
                expression += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty())
    {
        expression += st.top();
        st.pop();
    }

    cout << "infix_to_postfix: " << expression << endl;
}

void prefix_to_infix(string prefix)
{
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (is_operator(prefix[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string expression = "(" + op1 + prefix[i] + op2 + ")";
            st.push(expression);
        }
        else
        {
            st.push(string(1, prefix[i]));
        }
    }

    cout << "prefix_to_infix: " << st.top() << endl;
}

void postfix_to_infix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (is_operator(postfix[i]))
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string expression = "(" + op1 + postfix[i] + op2 + ")";
            st.push(expression);
        }
        else
        {
            st.push(string(1, postfix[i]));
        }
    }

    cout << "postfix_to_infix: " << st.top() << endl;
}

void evaluate_prefix(string prefix)
{
    vector<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (c == ' ')
            continue;

        if (isdigit(c))
            st.push_back(c - '0');

        else if (is_operator(c))
        {
            int op1 = st.back();
            st.pop_back();

            int op2 = st.back();
            st.pop_back();

            int result = applyOperation(op1, op2, c);
            st.push_back(result);
        }
    }
    cout << "evaluate_prefix: " << st.back() << endl;
}

void solve()
{
    string str = "((A-(B/C))*((A/K)-L))";

    infix_to_prefix(str);
    infix_to_postfix(str);
    prefix_to_infix("*+23-54");
    postfix_to_infix("ABC/-AK/L-*");
    evaluate_prefix("*+23-54");
}

int main()
{

    solve();

    return 0;
}