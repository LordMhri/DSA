#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int arr[],int size){
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
        if (arr[j+1] < arr[j])
        {
            swap(arr[j + 1], arr[j]);
        }
        }
        
    }
    
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 8, 12, -1};
    bubbleSort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
