#include <iostream>

using namespace std;

class priorityQueueArray
{
private:
    int size;
    int *array;
    int cap;

public:

    priorityQueueArray(int capacity) {
        size = 0;
        capacity = cap;
        array = new int[capacity];
    };

    void insert(int val)
    {
        if (size == cap)
        {
            cout << "Queue is full\n";
            return;
        }

        int i;
        for (i = size - 1; i >= 0 && array[i] < val; i--)
        {
            array[i + 1] = array[i];
        }
        array[i + 1] = val;
        size++;
    }
};