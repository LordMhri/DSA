#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *next;
    Node *prev;
    int priority;

    Node(int data, int priority) : data(data), priority(priority), next(nullptr), prev(nullptr) {};
};

class priorityQueue
{
private:
    Node *head;

public:
    priorityQueue(): head(nullptr){};

    void insert(int data,int priority){
        Node *newNode = new Node(data,priority);
        if (!head || head->priority > priority)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *ptr = head;
        while (ptr->next && ptr->next->priority <= priority)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void peekMax(){
        if (!head)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        cout << head->data << endl;
    }

    void display(){
        Node *ptr = head;
        while (ptr)
        {

            cout << ptr->data << "," << ptr->priority << endl;
        }

        cout << endl;
    }
};




int main(int argc, char const *argv[])
{

    priorityQueue pq;
    pq.insert(10, 2);
    pq.insert(20, 1);
    pq.insert(30, 3);

    pq.display();

    cout << "Element with highest priority: ";
    pq.peekMax();
    
    return 0;
}
