#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ")"
            << number.exchange << "-" << number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    input.ignore();
    input >> setw(3) >> number.areaCode;
    input.ignore(2);
    input >> setw(3) >> number.exchange;
    input.ignore();
    input >> setw(4) >> number.line;
    return input;
}
//前++回傳物件引用
PhoneNumber &PhoneNumber::operator++()
{
    cout << "inside prefix ++" << endl;
    return *this;
}

//後++回傳物件
PhoneNumber PhoneNumber::operator++(int)
{
    cout << "inside postfix function" << endl;
    return *this;
}

//+=
PhoneNumber &PhoneNumber::operator+=(int num){
    for (int i = 0 ;i < num; i++){
        cout << "inside += function" << endl;
    }
    return *this;
}
