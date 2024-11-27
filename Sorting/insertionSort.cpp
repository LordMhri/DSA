#include <iostream>

using namespace std;


void insertionSort(int arr[],int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 21, 2, 3, -1, 2, 3, 7};
    int size = sizeof(arr) / sizeof(int);
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
