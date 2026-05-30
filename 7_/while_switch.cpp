#include <iostream>
using namespace std;

int main(){
    int i = 0;
    while(1){
        switch(i){
            case 0:
                cout << "i is zero" << endl;
                exit(0);
            case 1:
                cout << "i is one" << endl;
                break;
            case 2:
                cout << "i is two" << endl;
                break;
            case 3:
                cout << "i is three" << endl;
                break;
            case 4:
                cout << "i is four" << endl;
                break;
        }
    }

    return 0;
}