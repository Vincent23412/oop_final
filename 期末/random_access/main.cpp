#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

int main()
{
   // ofstream constructor opens file
   ofstream outCredit("credit.dat", ios::out | ios::binary);

   if (!outCredit){
        cerr << "file not found" << endl;
        exit(1);
   }

   ClientData blankClient;

   for (int i = 0; i < 100; i++){
        outCredit.write(reinterpret_cast<const char *>(&blankClient),
                        sizeof(ClientData));
   }
}
