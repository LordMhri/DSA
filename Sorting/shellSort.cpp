#include <iostream>

using namespace std;

int shellSort(int arr[], int n)
{
    // choose a big enough gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // perform insertion sort
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= gap and arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, -2, 9, 2, -1, 2, 19, 29, 1, 2};
    int size = sizeof(arr) / sizeof(int);

    shellSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
