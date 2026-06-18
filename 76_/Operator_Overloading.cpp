// Operator Overloading - Giving custom meaning to operators for user-defined data types

#include <iostream>
using namespace std;

class Complex{
    private:
        float real;
        float imag;
    public:
        Complex(float r = 0, float i = 0){
            real = r;
            imag = i;
        }

        // Overloading + operator
        Complex operator + (Complex const &obj){
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        void display(){
            cout << real << " + " << imag << "i" << endl;
        }
};

int main(){
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3;

    c3 = c1 + c2; 
    // Using overloaded + operator
    // Objects c1 and c2 are added using the overloaded + operator, and the result is stored in c3.
    // i.e., objects behave like built-in data types when using the + operator.

    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << "c3 (c1 + c2): ";
    c3.display();

    return 0;
}
