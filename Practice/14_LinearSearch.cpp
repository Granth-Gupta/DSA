#include <iostream>
using namespace std;

void search(int key, int arr[], int n)
{
    // int n = sizeof(arr) / sizeof(arr[0]); // Error as arr is pointer in function
    // int n = arr.size(); // This line will cause an error because arr is a pointer, not an array. You need to pass the size of the array as an additional parameter.

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }

    cout << "Element not found" << endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // arr is an array here, so this works correctly
    // int n = arr.size(); -> Error: 'arr' is not a class, namespace, or enumeration

    int key;
    cin >> key;

    search(key, arr, n);

    return 0;
}