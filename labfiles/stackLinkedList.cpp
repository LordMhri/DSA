#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *prev;

    Node(int data) : data(data), prev(nullptr){};
};

class stackLinkedList{
private:
    Node *top;

public:
    stackLinkedList() : top(nullptr) {}

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->prev = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->prev;
        delete temp;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    
};

int main(int argc, char const *argv[])
{
    stackLinkedList ls;
    for (int i = 1; i <= 5; i++)
    {
        ls.push(i * 2);
    }
    ls.display();

    return 0;
}



