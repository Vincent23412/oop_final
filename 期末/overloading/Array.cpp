#include <iostream>
#include "Array.h"
using namespace std;

istream &operator>>(istream &input, Array &a)
{
    for (int i = 0 ; i < a.size; i++)
    {
        input >> a.ptr[i];
    }
    return input;
}

ostream &operator<<(ostream &output, const Array& a)
{
    for (int i = 0; i < a.size; i++)
    {
        output << a.ptr[i] << " ";
    }
}

Array::Array(int arraySize)
{
    size = arraySize;
    ptr = new int[arraySize];
    for (int i = 0; i < arraySize; i++){
        ptr[i] = 0;
    }
}

Array::Array(const Array &arrayToCopy): size(arrayToCopy.size)
{
    ptr = new int[size];
    for (int i = 0 ; i < size; ++i)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

int &Array::operator[](int subscripts)
{
    cout << "in &" << endl;
    return ptr[subscripts];
}

int Array::operator[](int subscripts) const
{
    cout << "in no &" << endl;
    return ptr[subscripts];
}
