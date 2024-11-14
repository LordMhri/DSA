#include <iostream>

using namespace std;

class stack
{
private:
    int top = -1; //keep track of the top element
    int arr[1000]; //size of array
    int size = sizeof(arr) / sizeof(int);

public:
    
    stack() {
        top = -1;
    }


    void push(int x){
        if (top < size - 1)
        {
            arr[++top] = x;
        } else {
            cout << "Stack size exceeded";
        } 
    }

    void pop() {
        if (top < 0)
            cout << "Stack is empty";
         else {
            top -= 1;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


    
};



int main(int argc, char const *argv[])
{
    stack st;
    for (int i = 0; i < 5; i++)
    {
        st.push(i * 2);
    }

    st.display();

    return 0;
}
