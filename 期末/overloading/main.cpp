#include <iostream>
#include "PhoneNumber.h"
#include <sstream>
#include "Array.h"

using namespace std;

int main()
{
    PhoneNumber phone;

    cout << "enter phone number" << endl;

    stringstream ss("11111111111111");
    ss >> phone;

    cout << "the phone number was ";
    cout << phone << endl;

    phone++;
    ++phone;
    phone+=5;

    cout << "[] overloading" << endl;

    Array A(5);
    A[2] = 5;
    //cout << A[2] ;
    cin >> A;
    cout << A;

}
