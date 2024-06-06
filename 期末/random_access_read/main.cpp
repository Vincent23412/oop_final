#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "../file_access/ClientData.h"
using namespace std;

void outputLine(ostream&, const ClientData &);

int main()
{
   ifstream inCredit("../file_access/credit.dat", ios::in | ios::binary);

   if (!inCredit){
        cerr << "file not found" << endl;
        exit(1);
   }

   cout << left << setw(10) << "Account" << setw(16)
        << "LastName" << setw(11) << "FirstName" << left
        << setw(10) << right << "Balance" << endl;

   ClientData client;

   inCredit.read(reinterpret_cast<char *>(&client),
                 sizeof(ClientData));

    while (inCredit && !inCredit.eof()){
        if (client.getAccountNumber() != 0){
            outputLine(cout, client);
        }

        inCredit.read(reinterpret_cast<char *>(&client),
                      sizeof(ClientData));
    }
}

void outputLine(ostream &output, const ClientData &record)
{
    output << left << setw(10) << record.getAccountNumber()
            << setw(16) << record.getLastName()
            << setw(11) << record.getFirstName()
            << setw(10) << setprecision(2) << right << fixed
            << showpoint << record.getBalance() << endl;
}
