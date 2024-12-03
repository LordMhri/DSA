#include <iostream>

using namespace std;

struct Node {
    Node *next;
    int data;
    Node(int data) : data(data), next(nullptr) {};
};

class Queue {
    private:
        Node *head;
        Node *tail;

    public:
        Queue() : head(nullptr), tail(nullptr) {};

        void enqueue(int data){
            Node *newNode = new Node(data);
            if (!tail)
            {
                head = tail = newNode;
            } else{
                tail->next = newNode;
                tail = newNode;
            }
                }

        void dequeue(){
           if (!head)
           {
               cout << "Queue is Empty.\n";
           } else if(head && !(head->next)) {
               delete head;
               head = nullptr;
               return;
           } else {
               Node *ptr = head->next;
               delete head;
               head = ptr;
           }
        }

        void peek(){
            if (!head)
            {
                cout << "Queue is empty\n";
            } else {
                cout << head->data << endl;
            }
        }

        bool isEmpty(){
            return !head;
        }

        void printQueue(){
            if (!head)
            {
                cout << "Empty Queue";
                return;
            }

            Node *ptr = head;

            while (ptr)
            {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
        }


};

int main(int argc, char const *argv[])
{
    Queue check;
    for (int i = 0; i < 5; i++)
    {
        check.enqueue(i + 1);
    }

    
    // if (check.isEmpty())
    // {
    //     cout << "Queue is empty\n";
    // }
    // else
    // {
    //     cout << "Queue is not empty\n";
    // }

    check.peek();
    for (int i = 0; i < 3; i++)
    {
        check.dequeue();
    }

    check.printQueue();
    
    return 0;

}
