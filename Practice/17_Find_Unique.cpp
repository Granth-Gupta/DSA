#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int ans = arr[0];
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 1, 2, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    int uniqueElement = findUnique(arr, size);

    cout << "The unique element is: " << uniqueElement << endl;

    return 0;
}