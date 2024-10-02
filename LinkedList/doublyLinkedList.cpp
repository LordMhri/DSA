#include <iostream>

using namespace std;

template<typename T>
struct ListNode
{
    T data;
    ListNode* prev;
    ListNode* next;
    
    //automatically initializes data with the passed val
    //and next with nullptr when a node is created
    ListNode(T val) : data(val) ,prev(nullptr), next(nullptr) {};
};

template<typename T>
class doublyLinkedList
{
private:
    ListNode<T> *head;
public:

    doublyLinkedList() : head(nullptr) {};//constructor 

    void insertNodeAtTail(T data) {
        ListNode<T> *newNode = new ListNode<T>(data);
        ListNode<T> *ptr = head;
        if (!head ) //if list is empty
        {
           head = newNode;
        } else {
        while (ptr->next) //find the last element
        {
            ptr = ptr->next;
        }
        newNode->prev = ptr; //link the newNode with the previous one ,backwards link
        ptr->next = newNode; //link the head with the currentnode, forward link
        
        }
    }


    void insertNodeAtHead(T data){
        ListNode<T> *newNode = new ListNode<T>(data);


        if (!head)
        {
            newNode = head;
        } else {
            head->prev = newNode;
            newNode->next = head;
            

            head = newNode;
        }   
    }

    void deleteFromTail(){
        if (!head || !head->next) //doesn't delete if the list is empty or only has one element
        {
            return;
        }

        ListNode<T> *ptr = head;
        while (ptr->next && ptr->next->next) //go to the second before last element of the list
        {
            //1<->2<->3<->4<->5<->6
            //stops at 5 because ptr->next->next doesn't exist
            //so ptr is now 5<->6
            //ptr->next is 6
            ptr = ptr->next;
        }

        delete ptr->next; // remove the last node
        ptr->next = nullptr; //set ptr.next to nullptr to avoid unexpected problems    
    }

    //removes node from the front of the list if the list is not empty 
    void deleteFromFront(){
        
        if (!head)
        {
            return;
        }

        ListNode<T> *ptr = head;
        head = ptr->next;
        delete ptr; // ptr is no longer needed
        
    }
    

    void printList(){
        ListNode<T>* ptr = head;
        while (ptr)
        {
            cout << ptr->data << "\n";
            ptr = ptr->next;
        }   
    }
};


int main(int argc, char const *argv[])
{
    doublyLinkedList<int> list;

    list.insertNodeAtTail(1);
    list.insertNodeAtTail(2);
    list.insertNodeAtTail(3);
    list.deleteFromFront();
    list.insertNodeAtTail(4);
    list.insertNodeAtHead(9);
    list.insertNodeAtHead(6);
    list.deleteFromTail();
    

    list.printList();
    return 0;
}

