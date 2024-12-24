#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    vector<int> arr;
    int n, element;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Enter array elements\n";
        cout << "2. Sort array using QuickSort\n";
        cout << "3. Print array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                arr.clear();
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> element;
                    arr.push_back(element);
                }
                break;
            case 2:
                quickSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using QuickSort.\n";
                printArray(arr);
                break;
            case 3:
                cout << "Array elements: ";
                printArray(arr);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}