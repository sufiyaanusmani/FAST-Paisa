#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class User{
    protected:
        int accountNumber;
        char name[40];
        char gender;
        char cnic[14];
        char contactNumber[12];
        char email[30];
        char password[20];
        int generateAccountNumber();
    public:
        virtual void createNewAccount() = 0;
        // virtual void viewMyInfo() = 0;
        // virtual void viewTransactionHistory() = 0;
        // virtual void deleteAccount() = 0;
        void setName();
        void setGender();
        void setCNIC();
        void setContactNumber();
        void setEmail();
        void setPassword();
        void storeData();
        void readData();
};

class Customer: public User{
    public:
        void createNewAccount();
        void depositMoney();
        void withdrawMoney();
        void transferMoney();
        void viewTransactionHistory();
        void setAccountStatus(int);
};

void Customer::createNewAccount(){
    this->accountNumber = generateAccountNumber();
    setName();   
    system("cls");
    setGender();
    system("cls");
    setCNIC();
    system("cls");
    setEmail();
    system("cls");
    setContactNumber();
    system("cls");
    setPassword(); 
    storeData();
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
    backspaceCount = i = 0;
    cout << "Enter your full name: ";
    while(1){
        ch = getch();
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32)){
            this->name[i] = ch;
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
    this->name[i] = '\0';
}

void User::setGender(){
    char ch;
    cout << "Enter your gender (m:male, f:female): ";
    while(1){
        ch = getch();
        if(ch == 'm' || ch == 'f'){
            this->gender = ch;
            cout << ch;
            break;
        }
    }
}

void User::setCNIC(){
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your CNIC (without dash) : ";
    while(1){
        ch = getch();
        if(ch >= '0' && ch <= '9'){
            this->cnic[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }else if(ch == 8 && backspaceCount > 0){
            cout << "\b \b";
            i--;
            backspaceCount--;
        }else if(ch == 13 && i == 13){
            break;
        }
    }
    this->cnic[13] = '\0';
}

void User::setContactNumber(){
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your contact number: ";
    while(1){
        ch = getch();
        if(ch >= '0' && ch <= '9'){
            this->contactNumber[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }else if(ch == 8 && backspaceCount > 0){
            cout << "\b \b";
            i--;
            backspaceCount--;
        }else if(ch == 13 && i == 11){
            break;
        }
    }
    this->contactNumber[11] = '\0';
}

void User::setEmail(){
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your email: ";
    while(1){
        ch = getch();
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9')){
            this->email[i] = ch;
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
    this->email[i] = '\0';
}

void User::setPassword(){
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your password: ";
    while(1){
        ch = getch();
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9')){
            this->password[i] = ch;
            cout << '*';
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
    this->password[i] = '\0';
}

void User::storeData(){
    ofstream fout;
    fout.open("./data/customer.bank", ios::app|ios::binary);
    fout.write((char*)this, sizeof(*this));
    fout.close();
}

void User::readData(){
    ifstream fin;
    system("cls");
    fin.open("./data/customer.bank", ios::in|ios::binary);
    fin.read((char*)this, sizeof(*this));
    while(fin.eof() == 0){
        cout << "Acc No: " << this->accountNumber << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
        cout << "CNIC: " << this->cnic << endl;
        cout << endl;
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
}

#endif // !BANK_H