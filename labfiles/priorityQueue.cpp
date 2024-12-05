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

};




int main(int argc, char const *argv[])
{
    
    return 0;
}
