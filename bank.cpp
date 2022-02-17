#include "bank.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

void Customer::createNewAccount(){
    this->accountNumber = generateAccountNumber();
    cout << "Enter your full name: ";
    setName();    
}

int User::generateAccountNumber(){
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/customer.bank", ios::in|ios::binary);
    if(!fin){
        cout << "File does not exists" << endl;
    }else{
        while(1){
            num = (rand() % 10000) + 100000;
            fin.read((char*)this, sizeof(*this));
            while(fin.eof() == 0){
                if(this->accountNumber == num){
                    isFound = true;
                    break;
                }
                fin.read((char*)this, sizeof(*this));
            }
            if(isFound == false){
                break;
            }
        }
    }
    fin.close();
    return num;
}

void User::setName(){
    char ch;
    int i, backspaceCount;
    backspaceCount = 0;
    cout << "Enter your name: ";
    while(1){
        ch = getch();
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32)){
            name[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }else if(ch == 8 && backspaceCount > 0){
            cout << "\b \b";
            i--;
            backspaceCount--;
        }else if(ch == 13){
            break;
        }
    }
}