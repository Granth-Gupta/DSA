#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Enter a number: ";
    cin >> a;

    int factorial = 1;
    while (a != 1)
    {
        factorial *= a;
        a--;
    }
    
    // printf("Factorial is: %d", factorial);
    cout << "Factorial is: " << factorial;
}