#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <iostream>
using namespace std;

class Array
{
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);
public:
    Array(int = 10);
    Array(const Array &);
    bool operator==(const Array &) const ;
    int &operator[](int);

    int operator[](int) const;
private:
    int size;
    int *ptr;
};

#endif // ARRAY_H_INCLUDED
