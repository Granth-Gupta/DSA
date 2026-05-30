#include <iostream>
using namespace std;

bool LinearSearch(int a[], int size, int key){
    for(int i = 0; i < size; i++){
        if(a[i] == key){
            return true;
        }
    }
    return false;
}

int main(){
    int a[10] = {3, 2, -3, 1, 0, -5, 11, -12, 13, 4};
    cout << "Search key: ";
    
    int k;
    cin >> k;

    bool isPresent = LinearSearch(a, 10, k);
    if(isPresent){
        cout << "Key is present in the array." << endl;
    } else {
        cout << "Key is not present in the array." << endl;
    }
    return 0;
}