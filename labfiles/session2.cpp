#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {};
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr){}; //constructor

    void insertAtHead(int data){
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int data){
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
        } else {
            Node *ptr = head;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            newNode->prev = ptr;
            ptr->next = newNode;
            }
        
    }

    void insertAtIndex(int index,int data){
        Node *newNode = new Node(data);
        int currPos = 0;

        if (index == 0)
        {
            insertAtHead(data);
            return;
        }
        

        if (!head)
        {
            head = newNode;
        } else {
            Node *ptr = head;
            while (ptr)
            {
                ptr = ptr->next;
            }
            
        }
        
    }
    void display() {
        Node *ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void deleteAtHead() {
        if (head == nullptr) return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtTail() {
        if (head == nullptr) return;
        Node *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        if (ptr->prev != nullptr) {
            ptr->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete ptr;
    }

    void reverse() {
        Node *current = head;
        Node *temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void deleteAtIndex(int index) {
        if (head == nullptr || index < 0) return;
        if (index == 0) {
            deleteAtHead();
            return;
        }
        Node *ptr = head;
        for (int i = 0; i < index && ptr != nullptr; i++) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) return;
        if (ptr->prev != nullptr) {
            ptr->prev->next = ptr->next;
        }
        if (ptr->next != nullptr) {
            ptr->next->prev = ptr->prev;
        }
        delete ptr;
    }
};

int main(int argc, char const *argv[])
{
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtIndex(2, 25);

    cout << "List after insertions: ";
    list.display();

    list.deleteAtHead();
    cout << "List after deleting head: ";
    list.display();

    list.deleteAtTail();
    cout << "List after deleting tail: ";
    list.display();

    list.deleteAtIndex(1);
    cout << "List after deleting at index 1: ";
    list.display();
    return 0;
}



