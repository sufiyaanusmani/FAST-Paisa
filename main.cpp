#include <iostream>
#include <fstream>
#include "bank.h"
using namespace std;

int main(){
    Customer c1;
    c1.createNewAccount();
    c1.readData();
    // c1.setEmail();
    return 0;
}