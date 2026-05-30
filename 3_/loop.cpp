#include <iostream>
using namespace std;

int main() {
    int n = 5;

    cout << "Using for loop:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Iteration " << i + 1 << endl;
    }

    cout << "Using while loop:" << endl;
    int j = 0;
    while (j < n) {
        cout << "Iteration " << j + 1 << endl;
        j++;
    }

    cout << "Using do-while loop:" << endl;
    int k = 0;
    do {
        cout << "Iteration " << k + 1 << endl;
        k++;
    } while (k < n);

    return 0;
}