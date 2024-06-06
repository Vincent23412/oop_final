#ifndef PHONENUMBER_H_INCLUDED
#define PHONENUMBER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class PhoneNumber{
    friend ostream &operator<< (ostream &, const PhoneNumber &);
    friend istream &operator>>(istream &, PhoneNumber &);
public:
    PhoneNumber &operator++();
    PhoneNumber operator++(int);
    PhoneNumber &operator+=(int);
private:
    string areaCode;
    string exchange;
    string line;
};

#endif // PHONENUMBER_H_INCLUDED
