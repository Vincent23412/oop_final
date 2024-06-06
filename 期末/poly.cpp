#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

class Base{
public:
    int a;
    int b;
    int c;
    Base(){
        a = 5;
        b = 10;
        c = 100;
    }
    // virtual
    virtual void print(){
        cout << a << " " << b << " "<< c << endl;
    }
};

class inherBase: public Base{
public:
    int d;
    inherBase(){
        d = 1000;
    }
    virtual void print(){
        cout << a << " " << b << " "<< c << " " << d << endl;
    }
};


int main(){
    Base a;
    inherBase b;
    cout << "original print" << endl;
    a.print();
    b.print();

    cout << endl;

    cout << "basePtr print" << endl;
    cout << "basePtr with base" << endl;
    Base *basePtr = 0;
    basePtr = &a;
    basePtr->print();
    cout << endl;
    cout << "basePtr with inher" << endl;
    basePtr = &b;
    basePtr->print();

    cout << endl;
    cout << "inherPtr print" << endl;
    cout << "inherPtr with base" << endl;
    inherBase *inherPtr  = 0;
    cout << "error" << endl;
    //inherPtr = &a;
    //inherPtr->print();
    cout << endl;
    cout << "inherPtr with inher" << endl;
    inherPtr = &b;
    inherPtr->print();

    cout << endl;
    cout << "use ref vs pointer" << endl;
    Base refBase = b;
    Base *pointBase = &b;
    refBase.print();
    pointBase->print();
    cout << endl;


    // using dynamic cast;
    cout << "using dynamic cast" << endl;
    vector<Base> base(1);
    base[0] = *new inherBase();
    base[0].print();


    inherBase *dynamicInherBase = dynamic_cast<inherBase *>(new Base());

    if (dynamicInherBase) {
        dynamicInherBase->print();
    } else {
        cout << "dynamic_cast failed" << endl;
    }
    cout << typeid(dynamicInherBase).name();

}


