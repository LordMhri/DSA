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

    
string DecimalToBinary(int number)
{
    if (number == 0)
    {
        return "0";
    }

    stackLinkedList binaryStack;
    while (number > 0)
    {
        binaryStack.push(number % 2);
        number /= 2;
    }

    string binaryString;
    while (binaryStack.top != nullptr)
    {
        binaryString += to_string(binaryStack.top->data);
        binaryStack.pop();
    }

    return binaryString;
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


    return 0;
}



