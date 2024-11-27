#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int target) {
    int ans = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            ans = i;
            break;
        }
    }
    return ans;
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }
    return ans;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void simpleSort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int check[] = {1, 2, 3, 4, 3, 21};
    int idx = linear_search(check, sizeof(check) / sizeof(int), 21);
    cout << "Linear search: found at index " << idx << endl;

    int sorted_check[] = {1, 2, 3, 4, 5, 6, 12};
    idx = binary_search(sorted_check, sizeof(sorted_check) / sizeof(int), 21);
    if(idx == 0) {
        cout << "Element not found in the list" << endl;
    } else {
        cout << "Binary search: found at index " << idx << endl;
        };

    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    simpleSort(arr,n);

    return 0;
}
