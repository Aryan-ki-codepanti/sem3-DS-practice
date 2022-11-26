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

    int largestElement()
    {
        // empty LL
        if (head == NULL)
            return GARBAGE;

        Node *ptr = head;
        int largest = ptr->data;

        while (ptr != NULL)
        {
            if (largest < ptr->data)
                largest = ptr->data;
            ptr = ptr->next;
        }
        return largest;
    }

    void oddElements()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }
        cout << "Odds : ";
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data % 2 != 0)
                cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList ll;
    ll.addOnHead(3);
    ll.addOnHead(4);
    ll.addOnHead(5);
    ll.display();
    cout << "Largest : " << ll.largestElement() << endl;
    ll.oddElements();
    return 0;
}