#include <iostream>
using namespace std;

// ================= NODE =================
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
// ================= HEIGHT =================
int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

// ================= MAX =================
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// ================= CREATE NODE =================
Node *createNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

// ================= RIGHT ROTATION (LL) =================
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// ================= LEFT ROTATION (RR) =================
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// ================= BALANCE FACTOR =================
int getBalance(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// ================= INSERT =================
Node *insert(Node *node, int value)
{

    // BST insertion
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Check balance
    int balance = getBalance(node);

    // LL
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// ================= INORDER =================
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ================= MAIN =================
int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "AVL Inorder Traversal: ";
    inorder(root);

    return 0;
}
