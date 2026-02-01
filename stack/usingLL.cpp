#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Stack class
class Stack
{
    Node *topNode; // Pointer to top of stack

public:
    Stack()
    {
        topNode = nullptr; // Initially empty
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    void push(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = topNode; // Link new node to current top
        topNode = newNode;       // Update top
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next; // Move top to next node
        delete temp;             // Free memory
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // or throw exception
        }
        return topNode->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node *temp = topNode;
        cout << "Stack elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
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
