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

    int linearSearch(int a) // returns idx of a
    {
        Node *ptr = head;
        int idx = 0;
        while (ptr != NULL)
        {
            if (ptr->data == a)
                return idx;
            ptr = ptr->next;
            idx++;
        }
        return -1;
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

    void addOnIdx(int idx, int a)
    {
        // Case 1: empty linked list
        if (head == NULL && tail == NULL)
        {
            cout << "Can't update index " << idx << " in empty linked list" << endl;
            return;
        }

        // Case 2 : idx 0 ie at head
        if (idx == 0)
        {
            addOnHead(a);
            return;
        }

        // moving to ptr at idx -  1 pos while not goin out of bounds
        Node *ptr = head;
        for (int i = 0; i < idx - 1 && ptr->next != NULL; i++)
            ptr = ptr->next;

        // Case 3: idx not exist in linked list (idx >= size of linked list)
        if (ptr->next == NULL)
        {
            cout << "Can't update index " << idx << " in shorter linked list" << endl;
            return;
        }

        // Case 4: insertion is at tail (idx = size - 1 )
        if (ptr->next == tail)
        {
            addOnTail(a);
            return;
        }

        // Case 5: general case
        Node *newNode = new Node(a);
        newNode->next = ptr->next;
        ptr->next = newNode;
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

    void deleteByVal(int a)
    {
        // Case 1 : a not in linked list or empty ll
        if (linearSearch(a) == -1)
        {
            cout << a << " not found hence can not be deleted" << endl;
            return;
        }

        // Case 2 : head has value a
        if (head->data == a)
        {
            deleteHead();
            return;
        }

        // Case 3 : tail has value a
        if (tail->data == a)
        {
            deleteTail();
            return;
        }

        // Case 4 : in between
        Node *ptr = head;
        while (ptr->next->data != a)
            ptr = ptr->next;

        Node *delNode = ptr->next;
        ptr->next = delNode->next;
        delete delNode;
    }

    void deleteAtIdx(int idx)
    {
        // Case 1 : Empty linked list
        if (head == NULL && tail == NULL)
        {
            cout << "Can't remove idx from Emtpy linked list" << endl;
            return;
        }

        // Case 2 : Removal at head
        if (idx == 0)
        {
            deleteHead();
            return;
        }

        Node *ptr = head;
        for (int i = 0; i < idx - 1 && ptr->next != NULL; i++)
            ptr = ptr->next;

        // Case 3 : idx out of bounds
        if (ptr->next == NULL)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        // Case 4 : Deletion at tail
        if (ptr->next == tail)
        {
            deleteTail();
            return;
        }

        // Case 5 : General
        Node *delNode = ptr->next;
        ptr->next = delNode->next;
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

    ll.deleteAtIdx(6);
    ll.display();
    ll.deleteAtIdx(0);
    ll.display();
    ll.deleteAtIdx(4);
    ll.display();
    ll.deleteAtIdx(2);
    ll.display();
    return 0;
}