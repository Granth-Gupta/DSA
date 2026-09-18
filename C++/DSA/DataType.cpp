#include<iostream>
using namespace std;

int main(){
    // int -> 4 byte
    // float -> 8 byte
    // char -> 1 byte
    // bool -> 1 bit
    // double -> 8 byte

    // unsigned int

    // 'a' -> 97

    int a =123;
    cout << sizeof(a) << endl;

    // char ch = 123456;
    // cout << ch << endl; 

    // @ -> as int 123456 try to convert in char 
    // but it has only 1 byte 
    // only last block bits goes to char bits that is 01000000 = 64
    // at 64 ASCII value -> @

    /*
    Storing -ive number (-5)
    5 = 00000000 00000000 00000000 00000101
    Fing 2's complement

    1) 1'2 complement = 11111111 11111111 1111111 11111010
    2) 2's complement (i.e +1) = 11111111 1111111 1111111 11111011
    */

   /*
   Reading -ive number (-5)
   again find 2's complement of stored form
   1) 1's complement = 00000000 00000000 00000000 00000100
   2) 2's complement = 00000000 00000000 00000000 00000101 
   */
   // 3 & 5 -> 011 & 101 -> 001 -> 1 ans
   // (3>5) && (5>3) -> 1 ans
   
   int c =2; // 00000000 00000000 00000000 00000010
   int b = 5;

    // a^b -> XOR

    cout << (b & c) <<endl;
    cout << (b | c) <<endl;
    cout << (~ c) <<endl;
    cout << (b ^ c) <<endl;

    exit(10);
    // exiting with exit code 10

    // Left shift operator
    cout << (5 << 2) <<endl;
    // 101 (left shift by 2 bits) -> 10100 i.e. 20

    // right shift
    cout << (5 >> 1) <<endl;
    if(true){
        int b =4;
        cout << b << endl;
    }
    cout << b << endl;

}