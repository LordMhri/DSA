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
    
    bool isPalindrome(const string &str)
    {
        stackLinkedList tempStack;
        for (char ch : str)
        {
            tempStack.push(ch);
        }

        for (char ch : str)
        {
            if (ch != tempStack.top->data)
            {
                return false;
            }
            tempStack.pop();
        }
        return true;
    }

    int binaryToDecimal(const string &binaryStr)
    {
        stackLinkedList tempStack;
        for (char ch : binaryStr)
        {
            tempStack.push(ch - '0');
        }

        int decimalValue = 0;
        int base = 1; 

        while (tempStack.top != nullptr)
        {
            decimalValue += tempStack.top->data * base;
            base *= 2;
            tempStack.pop();
        }

        return decimalValue;
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

    string testStr = "radar";
    if (ls.isPalindrome(testStr))
    {
        cout << testStr << " is a palindrome" << endl;
    }
    else
    {
        cout << testStr << " is not a palindrome" << endl;
    }

    string binaryStr = "1011";
    int decimalValue = ls.binaryToDecimal(binaryStr);
    cout << "Binary " << binaryStr << " is " << decimalValue << " in decimal" << endl;

    return 0;
}



