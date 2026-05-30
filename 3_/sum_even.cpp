#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Enter the value of a: ";
    cin >> a;

    int sum = 0;

    while(a > 0){
        if (a % 2 == 0){
            sum += a;
        }
        a--;
    }

    cout << "The sum of even numbers: " << sum << endl;

    return 0;
}