#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "../file_access/ClientData.h"
using namespace std;

int main()
{
   int accountNumber;
   string lastName;
   string firstName;
   double balance;

   // ofstream constructor opens file
   fstream outCredit("../file_access/credit.dat", ios::in | ios::out | ios::binary);

   if (!outCredit){
        cerr << "file not found" << endl;
        exit(1);
   }

   cout << "Enter account number\n";

   ClientData client;
   cin >> accountNumber;

   while (accountNumber > 0 && accountNumber <= 100){
        cout << "Enter lastName, firstName, balance\n";
        cin >> lastName;
        cin >> firstName;
        cin >> balance;

        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        outCredit.seekp((client.getAccountNumber() - 1) *
                        sizeof(ClientData));

        outCredit.write(reinterpret_cast<const char *>(&client),
                        sizeof(ClientData));

        cout << "Enter account number\n";
        cin >> accountNumber;
   }
}
