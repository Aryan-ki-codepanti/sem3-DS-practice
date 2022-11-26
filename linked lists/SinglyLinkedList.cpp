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
            head = tail = NULL;
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
    return 0;
}