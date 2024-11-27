#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pos = linear_search(arr, 9, 6);
    if (pos != -1)
    {
        cout << "Element found at index " << pos + 1 << "\n";
    } else {
        cout << "Element not found in array.";
    }
}


