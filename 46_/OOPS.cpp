#include <iostream>
#include <string>
using namespace std;

class Human{
    string name;
    public:
    void eat(){
        cout<<"Eating"<<endl;
    }

    void changeName(string newName){
        this->name = newName;
        cout << "Changed name to: " << this->name << endl;
    }
};

class Male: public Human{
    public:
    int age;

    void sleep(){
        cout<<"Sleeping"<<endl;
    }
};

int main(){
    Male m;

    m.age = 16;
    m.changeName("Harry");


    return 0;
}