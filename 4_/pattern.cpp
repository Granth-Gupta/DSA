#include <iostream>
using namespace std;

// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    int i = 1;
    int count = 1;

    while(i <= n) {
        int j = 1;
        while(j <= n) {
            cout << count << " ";
            j++;
            count++;
        }
        cout << endl;
        i++;
    }

    return 0;
}