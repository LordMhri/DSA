#include <iostream>

using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void simpleSort(int arr[],int size){
    for (int i = 0; i < size -2 ; i++)
    {
        for (int j = i+1; j < size -1;j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 21, 2, 3, -1, 2, 3, 7};
    int size = sizeof(arr)/sizeof(int);
    simpleSort(arr,size );

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
