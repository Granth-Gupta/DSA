#include <iostream>
#include <climits>
#include <array>
using namespace std;

bool linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "Element found at index: " << i << endl;
            return true;
        }
    }
    cout << "Element not found" << endl;
    return false;
}

int main()
{
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int s = 0;
    int e = sizeof(arr) / sizeof(int) - 1;

    while (s < e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        s = s + 1;
        e = e - 1;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}