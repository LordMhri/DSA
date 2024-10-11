#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
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
    vector<int> arr = {5, 2, 8, 12, 1};
    bubbleSort(arr);
    for (int num:arr){
        cout << num << " ";
    }
    return 0;
}
