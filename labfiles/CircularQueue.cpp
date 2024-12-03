#include <iostream>

using namespace std;

class CircularQueue
{   
    private:
        int capacity, front, rear, size;
        int *array;

    public:
    CircularQueue(int cap) {
        capacity = cap;
        size = 0;
        front = rear = -1;
        array = new int[capacity];
    }

    void enqueue(int data) {
        if (size == capacity) {
            cout << "Queue is full\n";
        } else {
            rear = (rear + 1) % capacity;
            array[rear] = data;
            if (front == -1) {
                front = 0;
            }
            size++;
        }
    }

    void peek(){
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << array[front] << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is Empty\n";
        } else {
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            size--;
        }
    }

    string isEmpty(){
        return (front == -1) ? "True" : "False";
    }

    string isFull(){
        return (front != -1) ? "True" : "False";
    }

    void clear(){
        front = rear = -1;
        size = 0;
    }

    void print() {
        if (size == 0) {
            cout << "Queue is empty\n";
        } else {
            int i = front;
            while (true) {
                cout << array[i] << " ";
                if (i == rear) break;
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
    }

    ~CircularQueue() {
        delete[] array;
    }
};

int main() {
    CircularQueue q(5);
    q.isEmpty();
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i + 1);
    }

    q.print();
    q.dequeue();
    q.print();
    q.enqueue(6);
    q.peek();
    q.isEmpty();
    q.print();
    q.clear();
    q.print();

    return 0;
}
