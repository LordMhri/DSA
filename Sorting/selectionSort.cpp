#include <iostream>

using namespace std;

void selectionSort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int minIdx = i;
        for (int j = i; j < size; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }        
        }
        swap(arr[i], arr[minIdx]);
    }
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = a;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 21, 2, 3, -1, 2, 3, 7};
    int size = sizeof(arr) / sizeof(int);
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
