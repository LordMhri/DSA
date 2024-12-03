#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque
{
private:
    Node *head;
    Node *tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    void insertNodeAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertNodeAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void removeFromFront()
    {
        if (!head)
        {
            cout << "Queue is empty\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void removeFromTail()
    {
        if (!head)
        {
            cout << "Queue is empty\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void peekRear(){
        if (tail)
        {
            cout << tail->data << endl;
        }
        cout << "Queue is empty\n";
    }

    void print()
    {
        if (!head)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *ptr = head;
        while (ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void peekFront(){
        if (head)
        {
            cout << head->data << endl;
            return;
        }

        cout << "Queue is Empty\n";
    }
};

int main(int argc, char const *argv[])
{
    Deque deque;

    for (int i = 0; i < 10; i++)
    {
        deque.insertNodeAtTail(i + 1);
    }

    for (int i = 0; i < 5; i++)
    {
        deque.removeFromTail();
    }

    deque.peekRear();



    deque.print();

    deque.peekFront();

    return 0;
}
