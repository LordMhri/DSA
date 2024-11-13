#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data) : data(data), next(nullptr) {};
};

class CircularLinkedList
{
private:
    ListNode *head;

public:
    CircularLinkedList() : head(nullptr){};
    
    void insertAtHead(int val){
        ListNode *newNode = new ListNode(val);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head; // Point to itself to make it circular
        } else {
            ListNode *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val){
        ListNode *newNode = new ListNode(val);

        if(head == nullptr){
            head = newNode;
            newNode->next = head; // Point to itself to make it circular
        } else {
            ListNode *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Complete the circle
        }
    }

    void insertAtPosition(int pos, int val){
        ListNode *newNode = new ListNode(val);

        if (pos == 0)
        {
            insertAtHead(val);
        } else {
            ListNode *current = head;
            int currpos = 0;
            while (current->next != head && currpos < pos - 1)
            {
                current = current->next;
                currpos++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteFromFront() {
        if (head == nullptr)
        {
            return;
        }

        //if head points to itself
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            ListNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            ListNode* ptr = head;
            head = head->next;
            temp->next = head;
            delete ptr;
        }
    }

    void deleteFromPos(int pos){
        if (head == nullptr)
        {
            return;
        }

        // If the list has only one node
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        ListNode *ptr = head;
        // If the node to be deleted is the head node
        if (pos == 0)
        {
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ListNode *temp = head;
            head = head->next;
            ptr->next = head;
            delete temp;
            return;
        }

        int currPos = 0;
        // go to the node just before the node to be deleted
        while (currPos < pos - 1 && ptr->next != head)
        {
            ptr = ptr->next;
            currPos++;
        }

        // if the node is out of bounds
        if (ptr->next == head || ptr->next->next == head)
        {
            return;
        }

        ListNode *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
        
        
    void deleteFromBack(){
        if (head == nullptr)
        {
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            ListNode *ptr = head;
            while (ptr->next->next != head)
            {
                ptr = ptr->next;
            }
            delete ptr->next;
            ptr->next = head;
        }
    }

    void display() {
        if (head == nullptr)
        {
            cout << "List is empty";
        }

        ListNode *ptr = head;
        do
        {
            cout << "Elements are " << ptr->data << "\n";
            ptr = ptr->next;
        } while (ptr!=head);
        
        
    }
};


int main(int argc, char const *argv[])
{
    CircularLinkedList circle;
    for (int i = 1; i <= 5; i++)
    {
        circle.insertAtHead(i * i);
    }

    circle.display();

    return 0;
}

