#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of stack

class Stack
{
    int arr[MAX];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1; // Stack is empty
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == MAX - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // or throw exception
        }
        return arr[topIndex];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();                        // Stack elements: 30 20 10
    cout << "Top: " << st.top() << endl; // Top: 30

    st.pop();
    st.display();                        // Stack elements: 20 10
    cout << "Top: " << st.top() << endl; // Top: 20

    st.pop();
    st.pop();
    st.pop(); // Stack Underflow!

    return 0;
}
