#include <vector>
#include <iostream>

using namespace std;

struct ArrayBasedLinkedList
{
    int size;
    vector<int> data;
    ArrayBasedLinkedList(int s) : size(0), data(s, 0) {}
};


void insertAtHead(ArrayBasedLinkedList &list, int value) {
    if (list.size == list.data.size()) {

        return;
    }

    for (int i = list.size - 1; i >= 0; --i) {
        list.data[i + 1] = list.data[i];
    }

    list.data[0] = value;
    ++list.size;
}

void deleteFromHead(ArrayBasedLinkedList &list){
    if (list.size == 0) {
        return;
    }

    for (int i = 0; i < list.size - 1; ++i) {
        list.data[i] = list.data[i + 1];
    }

    --list.size;
}

void deleteFromTail(ArrayBasedLinkedList &list){
    list.data.pop_back();

    --list.size;
}

void insertAtTail(ArrayBasedLinkedList &list, int value) {
    if (list.size == list.data.size()) {
        return;
    }

    list.data[list.size] = value;
    list.size += 1;
}


int main(int argc, char const *argv[])
{
    int size = 5;
    ArrayBasedLinkedList list = ArrayBasedLinkedList(size);
    for (int i = 0; i < size - 2; i++)
    {
        insertAtHead(list, size - 2);
    }
    for (int i = 0; i < size - 2; i++)
    {
        insertAtTail(list, 10);
    }

    for ( int i = 0; i < size - 2; i++)
    {
        deleteFromHead(list);
    }

    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << '\n';
    }

    for (int i = 0; i < size - 2; i++)
    {
        insertAtTail(list, 20);
    }

    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << '\n';
    }
}
