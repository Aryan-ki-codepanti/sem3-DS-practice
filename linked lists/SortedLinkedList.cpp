#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

class SortedLinkedList
{

    Node *head, *tail;

public:
    SortedLinkedList()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insert_node(int n)
    {
        Node *newNode = new Node(n);
        // first insertion
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }

        // at head
        if (n < head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *prev, *curr;
        prev = curr = head;

        while (curr != NULL && curr->data < n)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;
        newNode->next = curr;

        // if at tail
        if (curr == NULL)
            tail = newNode;
    }

    void delete_node(int n)
    {

        if (isEmpty())
        {
            cout << "Deletion not possible from empty ll" << endl;
            return;
        }

        Node *delNode, *prev, *curr;
        // delete head
        if (head->data == n)
        {
            delNode = head;
            if (head == tail) // last deletion
                head = tail = NULL;
            else
                head = head->next;
            delete delNode;
            return;
        }

        prev = curr = head;

        while (curr != NULL && curr->data < n)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr->data != n)
        {
            cout << n << " not found" << endl;
            return;
        }

        // tail deletion
        if (curr == tail)
            tail = prev;
        prev->next = curr->next;
        delete curr;
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SortedLinkedList l;
    l.insert_node(3);
    l.insert_node(1);
    l.insert_node(2);
    l.insert_node(0);
    l.insert_node(9);
    l.display();
    l.delete_node(5);
    l.delete_node(9);
    l.display();
    l.delete_node(1);
    l.display();
    return 0;
}