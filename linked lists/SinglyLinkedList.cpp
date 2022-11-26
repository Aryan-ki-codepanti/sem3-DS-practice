#include <iostream>
#define GARBAGE -6969
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

class SinglyLinkedList
{
    Node *head, *tail;

public:
    SinglyLinkedList()
    {
        head = tail = NULL;
    }

    void addOnTail(int a)
    {
        Node *newNode = new Node(a);
        // case 1 : first insertion
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
            return;
        }

        // case 2 : other
        tail->next = newNode;
        tail = newNode;
    }

    void addOnHead(int a)
    {
        Node *newNode = new Node(a);

        // Case 1 : Empty list
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        // Case 2 : 1 or more nodes present already

        newNode->next = head;
        head = newNode;
    }

    void deleteHead()
    {
        // Case 1 : Empty Linked List
        if (head == NULL && tail == NULL)
        {
            cout << "Can't delete head from empty list" << endl;
            return;
        }

        Node *delNode;
        // Case 2 : one node in  linked list
        delNode = head;
        if (head == tail)
        {
            head = tail = NULL;
            delete delNode;
            return;
        }

        // Case 3 : Other
        head = head->next;
        delete delNode;
    }

    void deleteTail()
    {
        // Case 1 : Empty Linked List
        if (head == NULL && tail == NULL)
        {
            cout << "Can't delete tail from empty list" << endl;
            return;
        }

        Node *delNode;
        // Case 2 : one node in  linked list
        delNode = tail;
        if (head == tail)
        {
            head = tail = NULL;
            delete delNode;
            return;
        }

        // Case 3 : Other
        Node *current = head;
        while (current->next != tail)
            current = current->next;

        current->next = NULL;
        tail = current;
        delete delNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }

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
    SinglyLinkedList ll;
    ll.addOnHead(3);
    ll.addOnHead(4);
    ll.addOnHead(5);
    ll.addOnTail(6);
    ll.addOnTail(7);
    ll.display();

    ll.deleteTail();
    ll.display();
    ll.deleteTail();
    ll.display();
    ll.deleteTail();
    ll.display();
    ll.deleteTail();
    ll.deleteTail();
    ll.display();
    return 0;
}