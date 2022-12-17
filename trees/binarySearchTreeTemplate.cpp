#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left, *right;
    Node(T a)
    {
        data = a;
        left = right = NULL;
    }
};

template <typename T>
class BinarySearchTree
{

public:
    Node<T> *root;
    BinarySearchTree() { root = NULL; }

    Node<T> *insert_recursive(Node<T> *r, T a)
    {
        if (r == NULL)
            return new Node<T>(a);

        else if (r->data < a)
            r->right = insert_recursive(r->right, a);

        else if (r->data > a)
            r->left = insert_recursive(r->left, a);

        return r;
    }

    void inorder_recursive(Node<T> *r)
    {
        if (r == NULL)
            return;
        inorder_recursive(r->left);
        cout << r->data << " ";
        inorder_recursive(r->right);
    }

    void insert(T a)
    {
        root = insert_recursive(root, a);
    }

    void inorder()
    {
        inorder_recursive(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree<char> t;
    t.insert('b');
    t.insert('v');
    t.insert('a');
    t.insert('c');
    t.inorder();
    return 0;
}