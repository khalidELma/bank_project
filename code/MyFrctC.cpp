
//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include "clsBankClient.h"

int main()

{

    clsBankClient Client1 = clsBankClient::Find("A101");
    

    Client1.Print();

    system("pause>0");
    return 0;
}