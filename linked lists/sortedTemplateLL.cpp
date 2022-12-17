#include <iostream>
using namespace std;

template <typename T>
class Node
{

public:
    T data;
    Node<T> *next;

    Node(T a)
    {
        data = a;
        next = NULL;
    }
};

template <typename T>
class SortedLL
{
    Node<T> *head, *tail;

public:
    SortedLL()
    {
        head = tail = NULL;
    }

    void insert_val(T a)
    {
        Node<T> *newNode = new Node<T>(a);

        // Empty LL
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
            return;
        }

        // at head
        if (a < head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T> *ptr = head;
        while (ptr->next && a > ptr->next->data)
            ptr = ptr->next;

        // at tail
        if (ptr == tail)
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }

        // general
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void display()
    {
        Node<T> *ptr = head;
        while (ptr)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SortedLL<char> l;
    l.insert_val('g');
    l.insert_val('f');
    l.insert_val('c');
    l.insert_val('b');
    l.display();
    return 0;
}