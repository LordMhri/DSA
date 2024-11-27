#include <iostream>

using namespace std;

int binary_search(int arr[],int size,int target){

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pos = binary_search(arr, 9, 6);
    if (pos != -1 )
    {
        cout << "Element found at index " << pos + 1 << " \n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
