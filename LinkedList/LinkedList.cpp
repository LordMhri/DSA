#include <iostream>

using namespace std;

template<typename T>
struct ListNode
{
    T data; 

    ListNode* next;

    // automatically intializes data member with the value passed 
    // and the next ptr with nullptr when a node is created
    ListNode(T val) : data(val), next(nullptr) {} 

};

template<typename T>
class LinkedList
{
private:
    ListNode<T>* head;
public:
    LinkedList() : head(nullptr){}; //initializes new linked list head with nullptr

    ListNode<T>* getHead(){
        return head;
    }

    void insertNodeAtTail(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);

        if (head == nullptr) //if no previous node exists
        {
            head = newNode;//the head is now the node we just created
            return;
        }

        //hold the previous node in current
        ListNode<T>* current = head;
        while (current->next != nullptr) //if the next head of the current node exists
        {
            current = current->next; //just move current until we stop finding a node i.e we've reached the last node before the end
        }
        //we know the next node after the one we have is empty or null
        //so assign the next of the current head to the node created i.e newNode
        current->next = newNode; 
        
    }

    void insertNodeAtHead(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);

        if (head == nullptr) //if no head exists,our newNode is the new head
        {
            head = newNode;
            return;
        }

        //if head exists
        //our newNode' next ptr will point to head
        //newNode -> head | 
        newNode->next = head;
        //head then will be assigned to newNode itself
        head = newNode;
        
    }

    //only deletes the tail if List has more than 1 element
    void deleteFromTheTail() {

        if (!head  || !head->next) //the head is empty or the has only one element
        {
            return;
        }
        
        ListNode<T>* ptr = head;
        while (ptr->next && ptr->next->next) //if the next ptr and the next ptrs next exist
        {
            //1->2->3->4->5
            //goes out of the loop one 4 so ptr will be
            //4->5 
            ptr = ptr->next;

        }
        delete ptr->next; //free the memory used by the last node
        ptr->next =nullptr; // set the last node to null
        
    }   


    void deleteFromTheFront(){ 
        if (!head)
        {
            return;
        }
        ListNode<T>* ptr = head;
        head = ptr->next;
        delete ptr;
        
    }


    void printList(){
        if (!head)
        {
            std::cout << "Empty list";
        }

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
    LinkedList<int> list;
    
    list.insertNodeAtTail(13);
    list.insertNodeAtTail(15);
    list.deleteFromTheFront();
    list.deleteFromTheTail();

    list.printList();
    
    return 0;
}



