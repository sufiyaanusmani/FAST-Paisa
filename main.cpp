#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "ui.h"
#include <windows.h>
#include <ctype.h>
#include <iomanip>
using namespace std;

int mainMenu();
void loginAsCustomer();

class User
{
protected:
    int accountNumber;
    char name[40];
    int age;
    char gender;
    char cnic[14];
    char contactNumber[12];
    char email[30];
    char password[20];
    int generateAccountNumber();
    void inputPassword(char[20]);

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
    int getAccountNumber();
    virtual void storeData() = 0;
    void readData();
    void setAge();
    virtual void login() = 0;
    virtual void viewMyInfo() = 0;
    virtual void portal() = 0;
    virtual int portalMenu() = 0;
    virtual void deleteAccount() = 0;
};

class Customer : public User
{
private:
    unsigned long long int amount;

public:
    void createNewAccount();
    void depositAmount();
    void withdrawAmount();
    void transferAmount();
    void viewTransactionHistory();
    void login();
    void viewMyInfo();
    void portal();
    int portalMenu();
    void viewCustomerAccounts();
    void storeData();
    void deleteAccount();
};

class Admin : public User{
    public:
        void storeData();
        void login();
        void viewMyInfo();
        void portal();
        int portalMenu();
        void deleteAccount();
        void createNewAccount();
        void createCustomerDatabaseBackup();
        void createCustomerDatabaseBackupAnimation();
};

class Transaction{
    private:
        int transactionID;
        int accountNumber;
        char customerName[40];
        unsigned long long int amount;
        char transactionType[9];
        int generateTransactionID();
    public:
        void storeTransaction(int, char [40], unsigned long long int, char [9]);
        void viewTransactionHistoryAdmin();
        void viewTransactionHistoryCustomer(int);
};

class Currency{
    private:
        int code;
        char name[25];
        char symbol[4];
        float rate;
        int generateCurrencyCode();
    public:
        void addCurrency();
        void updateCurrencyRate();
        void viewCurrencyRates();
};

int main(){
    int mainMenuChoice;
    Customer c;
    Admin a;
    while (1)
    {
        mainMenuChoice = mainMenu();
        switch (mainMenuChoice)
        {
        case 1:
            system("cls");
            system("title Admin Login");
            a.login();
            break;
        case 2:
            system("cls");
            system("title Customer Login");
            c.login();
            break;
        case 3:
            system("cls");
            system("title Create New Account");
            c.createNewAccount();
            break;
        case 4:
            system("cls");
            system("title Today's Currency Rates");
            // viewCurrencyRates();
            break;
        case 5:
            system("cls");
            system("title About Us");
            // aboutUs();
            break;
        case 6:
            system("cls");
            CursorPosition(40, 10);
            system("title Good Bye");
            cout << "Thankyou for using our service, :)";
            Sleep(2000);
            exit(0);
            break;
        default:
            system("cls");
            system("title ERROR :(");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "Wrong choice entered, try again!";
            Beep(1000, 300);
            Sleep(2000);
            system("color 0F");
            break;
        }
    }
    return 0;
}


void Customer::createNewAccount()
{
    this->accountNumber = generateAccountNumber();
    setName();
    system("cls");
    setGender();
    system("cls");
    setAge();
    system("cls");
    setCNIC();
    system("cls");
    setEmail();
    system("cls");
    setContactNumber();
    system("cls");
    setPassword();
    this->amount = 0;
    system("color 0F");
    system("cls");
    TextColor(15);
    cout << "Account Number  : ";
    TextColor(9);
    cout << this->accountNumber << endl;
    TextColor(15);
    cout << "Name            : ";
    TextColor(10);
    cout << this->name << endl;
    TextColor(15);
    cout << "Age             : ";
    TextColor(10);
    cout << this->age << endl;
    TextColor(15);
    cout << "Contact Number  : ";
    TextColor(10);
    cout << this->contactNumber << endl;
    TextColor(15);
    cout << "CNIC: ";
    TextColor(10);
    cout << this->cnic << endl;
    TextColor(15);
    cout << "Email: ";
    TextColor(10);
    cout << this->email << endl;
    cout << "Account Balance : ";
    TextColor(10);
    cout << "Rs. " << this->amount << endl << endl;
    cout << "\nAre your sure you want to create your account: [y/n]: ";
    char ch, choice;
    while (1)
    {
        ch = getch();
        if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
        {
            choice = ch;
            cout << ch << endl;
            break;
        }
    }
    system("color 0F");
    if (choice == 'y' || choice == 'Y')
    {
        Customer::storeData();
        cout << "Account created successfully\n";
        Sleep(1000);
    }
}

int User::generateAccountNumber()
{
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File does not exists" << endl;
    }
    else
    {
        while (1)
        {
            num = (rand() % 10000) + 100000;
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->accountNumber == num)
                {
                    isFound = true;
                    break;
                }
                fin.read((char *)this, sizeof(*this));
            }
            if (isFound == false)
            {
                break;
            }
        }
    }
    fin.close();
    return num;
}

void User::setName()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your full name: ";
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32))
        {
            this->name[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->name[i] = '\0';
}

void User::setAge()
{
    char ch, a[3];
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your age : ";
    while (1)
    {
        ch = getch();
        if (ch >= '0' && ch <= '9')
        {
            a[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13 && i == 2)
        {
            break;
        }
    }
    a[3] = '\0';
    this->age = ((a[0] - 48) * 10) + (a[1] - 48);
    if (this->age < 18)
    {
        cout << "Age must be greater than or equal to 18" << endl;
        setAge();
    }
}

void User::setGender()
{
    char ch;
    cout << "Enter your gender (m:male, f:female): ";
    while (1)
    {
        ch = getch();
        if (ch == 'm' || ch == 'f')
        {
            this->gender = ch;
            cout << ch;
            break;
        }
    }
}

void User::setCNIC()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your CNIC (without dash) : ";
    while (1)
    {
        ch = getch();
        if (ch >= '0' && ch <= '9')
        {
            this->cnic[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13 && i == 13)
        {
            break;
        }
    }
    this->cnic[13] = '\0';
}

void User::setContactNumber()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your contact number: ";
    while (1)
    {
        ch = getch();
        if (ch >= '0' && ch <= '9')
        {
            this->contactNumber[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13 && i == 11)
        {
            break;
        }
    }
    this->contactNumber[11] = '\0';
}

void User::setEmail()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your email: ";
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            this->email[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->email[i] = '\0';
}

void User::setPassword()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your password: ";
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            this->password[i] = ch;
            cout << '*';
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->password[i] = '\0';
}

void Customer::storeData()
{
    ofstream fout;
    fout.open("./data/customer.bank", ios::app | ios::binary);
    if(!fout){
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

void User::readData()
{
    ifstream fin;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        cout << "Acc No: " << this->accountNumber << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
        cout << "CNIC: " << this->cnic << endl;
        cout << endl;
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
}

void Customer::login()
{
    int id;
    char pass[20];
    bool idFound = false;
    bool passFound = false;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "ERROR, file does not exist" << endl;
    }
    else
    {
        cout << "Enter account number: ";
        fflush(stdin);
        cin >> id;
        fin.read((char *)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (id == this->accountNumber)
            {
                idFound = true;
                cout << "Enter your password: ";
                inputPassword(pass);
                if (strcmp(password, pass) == 0)
                {
                    passFound = true;
                    fin.close();
                    loadingAnimation();
                    Customer::portal();
                }
                else
                {
                    cout << "Wrong password" << endl;
                    Sleep(1000);
                }
                break;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (idFound == false)
        {
            cout << "This ID does not exists" << endl;
        }
        fin.close();
    }
}

void User::inputPassword(char pass[20])
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            pass[i] = ch;
            cout << '*';
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    pass[i] = '\0';
}

void Customer::viewMyInfo()
{
    system("color 0B");
    system("cls");
    system("title MY INFO");
    cout << "Name: ";
    cout << this->name << endl;
    cout << "Account No: " << this->accountNumber << endl;
    cout << "Age: " << this->age << endl;
    cout << "Gender: " << (this->gender == 'm' ? "Male" : "Female") << endl;
    cout << "Contact Number: " << this->contactNumber << endl;
    cout << "Email: " << this->email << endl;
    cout << "CNIC: " << this->cnic << endl
         << endl;
    cout << "Current Balance: " << this->amount << endl;

    cout << "Press any key to go to your portal\n";
    getch();
    system("color 0F");
}

void Customer::portal()
{
    system("cls");
    int customerPortalChoice, accNo;
    accNo = accountNumber;
    ifstream fin;
    Transaction t;

    while (1)
    {
        fin.open("./data/customer.bank", ios::in | ios::binary);
        if (!fin)
        {
            system("cls");
            perror("Error");
            cout << "\nProgram will exit\n";
            Sleep(2000);
            exit(1);
        }
        fin.read((char *)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (accNo == accountNumber)
            {
                break;
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        customerPortalChoice = Customer::portalMenu();
        switch (customerPortalChoice)
        {
        case 1:
            Customer::viewMyInfo();
            // customerPortal();
            break;
        case 2:
            system("cls");
            system("title DEPOSIT AMOUNT");
            depositAmount();
            break;
        case 3:
            system("cls");
            system("title WITHDRAW AMOUNT");
            withdrawAmount();
            break;
        case 4:
            system("cls");
            system("title TRANSFER AMOUNT");
            transferAmount();
            break;
        case 5:
            system("cls");
            system("title VIEW TRANSACTION HISTORY");
            t.viewTransactionHistoryCustomer(accNo);
            break;
        case 6:
            system("cls");
            system("title DELETE ACCOUNT");
            Customer::deleteAccount();
            break;
        case 7:
            goto customerPortalEnd;
            break;
        default:
            system("cls");
            system("title ERROR");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "\aWrong choice entered, try again! \a";
            Sleep(1500);
            system("color 0F");
            break;
        }
    }
customerPortalEnd:
    system("cls");
}

int Customer::portalMenu()
{
    int choice, i;
    system("color 0F");
    system("cls");
    system("title MY PORTAL");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(0, 2);
    TextColor(9);
    cout << "Welcome, " << this->name << endl;
    cout << "Current Balance: PKR " << this->amount << endl;
    CursorPosition(32, 5);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 14; i++)
    {
        CursorPosition(31, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 14; i++)
    {
        CursorPosition(91, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 20);
        cout << "-";
    }
    TextColor(15);
    CursorPosition(33, 7);
    cout << "1. View my information";
    CursorPosition(33, 9);
    cout << "2. Deposit Money";
    CursorPosition(33, 11);
    cout << "3. Withdraw Money";
    CursorPosition(33, 13);
    cout << "4. Transfer Money";
    CursorPosition(33, 15);
    cout << "5. View My Transaction History";
    CursorPosition(33, 17);
    cout << "6. Delete Account";
    CursorPosition(33, 19);
    cout << "7. Logout";
    CursorPosition(32, 22);
    TextColor(5);
    cout << "Enter your choice: ";
    fflush(stdin);
    cin >> choice;
    system("color 0F");
    return choice;
}

void Customer::depositAmount()
{
    Transaction t;
    unsigned long long int amountToDeposit = 0;
    int accNo = this->accountNumber;
    char n[40];
    strcpy(n, name);
    char type[9];
    strcpy(type, "Deposit");
    cout << "Enter amount to deposit  (-1 to go back): ";
    cin >> amountToDeposit;
    if (amountToDeposit == -1)
    {
        goto amountToDepositEnd;
    }
    else if (amountToDeposit < 0)
    {
        cout << "Amount can not be negative" << endl;
    }
    else
    {
        fstream file;
        file.open("./data/customer.bank", ios::in | ios::out | ios::ate | ios::binary);
        file.seekg(0);
        file.read((char *)this, sizeof(*this));
        while (file.eof() == 0)
        {
            if (this->accountNumber == accNo)
            {
                this->amount = this->amount + amountToDeposit;
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char *)this, sizeof(*this));
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        // SetColor();
        cout << "\nRs. " << amountToDeposit << " deposited successfully" << endl;
        t.storeTransaction(accNo, n, amountToDeposit, "Deposit");
        Sleep(2000);
    }
amountToDepositEnd:
    system("cls");
}

void Customer::withdrawAmount()
{
    unsigned long long int amountToWithdraw;
    int accNo = this->accountNumber;
    Transaction t;
    char n[40];
    strcpy(n, name);
    cout << "Enter amount to withdraw (-1 to go back): ";
    cin >> amountToWithdraw;
    if (amountToWithdraw == -1)
    {
        goto amountToWithdrawEnd;
    }
    else if (amountToWithdraw < 0)
    {
        cout << "Amount can not be negative";
        Sleep(1500);
    }
    else if (amountToWithdraw > this->amount)
    {
        cout << "You don't have enough balance" << endl;
        Sleep(1500);
    }
    else
    {
        fstream file;
        file.open("./data/customer.bank", ios::ate | ios::in | ios::out | ios::binary);
        file.seekg(0);
        file.read((char *)this, sizeof(*this));
        while (file.eof() == 0)
        {
            if (this->accountNumber == accNo)
            {
                this->amount = this->amount - amountToWithdraw;
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char *)this, sizeof(*this));
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        // SetColor();
        cout << "\nRs. " << amountToWithdraw << " withdrawn successfully" << endl;
        t.storeTransaction(accNo, n, amountToWithdraw, "Withdraw");
        Sleep(2000);
    }
amountToWithdrawEnd:
    system("cls");
}

void Customer::transferAmount()
{
    int senderAccount = this->accountNumber;
    char receiverName[40];
    ifstream fin;
    Transaction t;
    char n[40];
    strcpy(n, name);
    int receiverAccount;
    unsigned long long int amountToTransfer, senderAmount;
    senderAmount = this->amount;
    bool receiverFound = false;
    while(1){
        cout << "Enter receiver's account number (-1 to go back): ";
        fflush(stdin);
        cin >> receiverAccount;
        system("cls");
        if(receiverAccount == senderAccount){
            cout << "You can not transfer to yourself" << endl;
        }
        if(receiverAccount == -1){
            goto transferAmountEnd;
        }else{
            break;
        }
    }
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        if (this->accountNumber == receiverAccount)
        {
            receiverFound = true;
            strcpy(receiverName, name);
            break;
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    if (receiverFound == true)
    {
        cout << "Enter amount to transfer: ";
        fflush(stdin);
        cin >> amountToTransfer;
        if (amountToTransfer <= senderAmount)
        {
            fstream file;
            file.open("./data/customer.bank", ios::in | ios::out | ios::ate | ios::binary);
            file.seekg(0);
            file.read((char *)this, sizeof(*this));
            while (file.eof() == 0)
            {
                if (this->accountNumber == senderAccount)
                {
                    this->amount = this->amount - amountToTransfer;
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write((char *)this, sizeof(*this));
                }
                else if (this->accountNumber == receiverAccount)
                {
                    this->amount = this->amount + amountToTransfer;
                    file.seekp(file.tellp() - sizeof(*this));
                    file.write((char *)this, sizeof(*this));
                }
                file.read((char *)this, sizeof(*this));
            }
            file.close();
            cout << "Rs. " << amountToTransfer << " transferred successfully to " << receiverName << endl;
            t.storeTransaction(senderAccount, n, amountToTransfer, "Transfer");
            Sleep(2000);
        }
        else
        {
            cout << "You don't have enough balance" << endl;
            Sleep(1500);
        }
    }
    else
    {
        cout << "This account does not exists" << endl;
        Sleep(1500);
    }
    transferAmountEnd:
        system("cls");
}

void Customer::deleteAccount(){
    int accNo = this->accountNumber;
    char ch, choice;
    system("cls");
    cout << "Are you sure you want to delete your account? [y/n]: ";
    while (1)
    {
        ch = getch();
        if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
        {
            choice = ch;
            cout << ch << endl;
            break;
        }
    }
    system("color 0F");
    if (choice == 'y' || choice == 'Y')
    {
        ifstream fin;
        ofstream fout;
        fout.open("./data/temp.bank", ios::out|ios::binary);
        fin.open("./data/customer.bank", ios::in|ios::binary);
        if(!fin){
            perror("Error");
            Sleep(2000);
            exit(1);
        }else{
            fin.read((char*)this, sizeof(*this));
            while(fin.eof() == 0){
                if(this->accountNumber != accNo){
                    fout.write((char*)this, sizeof(*this));
                }
                fin.read((char*)this, sizeof(*this));
            }
        }
        fin.close();
        fout.close();
        remove("./data/customer.bank");
        rename("./data/temp.bank", "./data/customer.bank");
        cout << "Account deleted successfully" << endl;
        Sleep(2500);
        main();
    }
}

void Admin::storeData(){
    ofstream fout;
    fout.open("./data/admin.bank", ios::app|ios::binary);
    if(!fout){
        perror("Error");
        Sleep(2500);
        exit(1);
    }
    fout.write((char*)this, sizeof(*this));
    fout.close();
}

void Admin::login(){
int id;
    char pass[20];
    bool idFound = false;
    bool passFound = false;
    ifstream fin;
    fin.open("./data/admin.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "ERROR, file does not exist" << endl;
    }
    else
    {
        cout << "Enter account number: ";
        fflush(stdin);
        cin >> id;
        fin.read((char *)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (id == this->accountNumber)
            {
                idFound = true;
                cout << "Enter your password: ";
                inputPassword(pass);
                if (strcmp(password, pass) == 0)
                {
                    passFound = true;
                    fin.close();
                    loadingAnimation();
                    Admin::portal();
                }
                else
                {
                    cout << "Wrong password" << endl;
                    Sleep(1000);
                }
                break;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (idFound == false)
        {
            cout << "This ID does not exists" << endl;
        }
        fin.close();
    }
}

void Admin::createNewAccount(){

}

void Admin::portal(){
    system("cls");
    int adminPortalChoice, accNo;
    accNo = this->accountNumber;
    ifstream fin;

    while (1)
    {
        fin.open("./data/admin.bank", ios::in | ios::binary);
        if (!fin)
        {
            system("cls");
            perror("Error");
            cout << "\nProgram will exit\n";
            Sleep(2000);
            exit(1);
        }
        fin.read((char *)this, sizeof(*this));
         while (fin.eof() == 0)
        {
            if (accNo == accountNumber)
            {
                break;
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        adminPortalChoice = Admin::portalMenu();
        Customer c;
        Transaction t;
        Currency cur;
        switch (adminPortalChoice)
        {
        case 1:
            system("title MY INFO");
            system("color 0B");
            system("cls");
            Admin::viewMyInfo();
            break;
        case 2:
            system("cls");
            system("title CUSTOMER ACCOUNTS INFO");
            c.viewCustomerAccounts();
            break;
        case 3:
            system("cls");
            system("title TRANSACTION HISTORY");
            t.viewTransactionHistoryAdmin();
            break;
        case 4:
            system("cls");
            system("title DELETE ACCOUNT");
            Admin::deleteAccount();
            break;
        case 5:
            system("cls");
            system("title UPDATE CURRENCY RATES");
            cur.addCurrency();
            break;
        case 6:
            system("cls");
            system("title SEARCH");
            // searchCustomer();
            break;
        case 7:
            system("cls");
            system("title CREATING DATABASES BACKUP");
            createCustomerDatabaseBackup();
            break;
        case 8:
            main();
            break;
        default:
            system("cls");
            system("title ERROR");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "\aWrong choice entered, try again! \a";
            Sleep(1500);
            system("color 0F");
            break;
        }
    }
}

int Admin::portalMenu(){
    int choice;
    system("color 0F");
    int i;
    system("cls");
    system("title ADMIN PORTAL");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(0, 2);
    TextColor(9);
    cout << "Welcome, " << this->name << endl;
    CursorPosition(32, 5);
    TextColor(3);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 16; i++)
    {
        CursorPosition(31, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 16; i++)
    {
        CursorPosition(91, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 22);
        cout << "-";
    }
    TextColor(15);
    CursorPosition(33, 7);
    cout << "1. View my information";
    CursorPosition(33, 9);
    cout << "2. View current accounts information";
    CursorPosition(33, 11);
    cout << "3. View Transaction History";
    CursorPosition(33, 13);
    cout << "4. Delete Account";
    CursorPosition(33, 15);
    cout << "5. Update Currency Rates";
    CursorPosition(33, 17);
    cout << "6. Search and Sort Customers";
    CursorPosition(33, 19);
    cout << "7. Create Customer Database Backup";
    CursorPosition(33, 21);
    cout << "8. Logout";
    CursorPosition(32, 24);
    cout << "Enter your choice: ";
    fflush(stdin);
    cin >> choice;
    return choice;
}

void Admin::viewMyInfo(){
    system("color 0B");
    system("cls");
    system("title MY INFO");
    cout << "Name: ";
    cout << this->name << endl;
    cout << "Account No: " << this->accountNumber << endl;
    cout << "Age: " << this->age << endl;
    cout << "Gender: " << (this->gender == 'm' ? "Male" : "Female") << endl;
    cout << "Contact Number: " << this->contactNumber << endl;
    cout << "Email: " << this->email << endl;
    cout << "CNIC: " << this->cnic << endl << endl;

    cout << "Press any key to go to your portal\n";
    getch();
    system("color 0F");
}

void Customer::viewCustomerAccounts(){
    ifstream fin;
    fin.open("./data/customer.bank", ios::in|ios::binary);
    if(!fin){
        perror("Error");
        exit(1);
    }
    fin.read((char*)this, sizeof(*this));
    TextColor(4);
    cout << "Account No  " << setw(40) << "  Name  " << endl;
    TextColor(15);
    while(fin.eof() == 0){
        cout << this->accountNumber << "      " << setw(40) <<  this->name << "  " << this->age << "  " << (this->gender == 'm' ? "Male" : "Female") << "  " << this->contactNumber << "  " << this->cnic << "  " << this->email << "  " << this->amount << endl;
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
    TextColor(13);
    cout << "Press any key to continue..." << endl;
    getch();
}

int Transaction::generateTransactionID(){
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/transaction.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File does not exists" << endl;
    }
    else
    {
        while (1)
        {
            num = (rand() % 10000) + 100000;
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->transactionID == num)
                {
                    isFound = true;
                    break;
                }
                fin.read((char *)this, sizeof(*this));
            }
            if (isFound == false)
            {
                break;
            }
        }
    }
    fin.close();
    return num;
}

void Transaction::storeTransaction(int accountNumber, char name[40], unsigned long long int amount, char type[9]){
    ofstream fout;
    fout.open("./data/transaction.bank", ios::app|ios::binary);
    if(!fout){
        perror("Error");
        Sleep(3000);
        exit(1);
    }
    this->transactionID = generateTransactionID();
    this->accountNumber = accountNumber;
    strcpy(customerName, name);
    this->amount = amount;
    strcpy(transactionType, type);
    fout.write((char*)this, sizeof(*this));
    fout.close();
}

void Transaction::viewTransactionHistoryAdmin(){
    ifstream fin;
    fin.open("./data/transaction.bank", ios::in|ios::binary);
    if(!fin){
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    cout << "Transaction ID  Name  Account No  Amount  Transaction Type" << endl;
    fin.read((char*)this, sizeof(*this));
    while(fin.eof() == 0){
        cout << this->transactionID << "  " << this->customerName << "  " << this->accountNumber << "  " << this->amount << "  " << this->transactionType << endl;
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
    TextColor(5);
    cout << "\nPress any key to continue...";
    getch();
}

void Transaction::viewTransactionHistoryCustomer(int accNo){
    ifstream fin;
    fin.open("./data/transaction.bank", ios::in|ios::binary);
    if(!fin){
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    cout << "Transaction ID  Amount  Transaction Type" << endl;
    fin.read((char*)this, sizeof(*this));
    while(fin.eof() == 0){
        if(this->accountNumber == accNo){
            cout << this->transactionID << "  " << "  " << this->amount << "  " << this->transactionType << endl;
        }
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
    cout << "Press any key to continue..." << endl;
    getch();
}

int User::getAccountNumber(){
    return accountNumber;
}

void Admin::deleteAccount(){
    int accountToDelete;
    char ch, choice;
    ofstream fout;
    Customer c;
    bool accountFound = false;
    cout << "Enter account number to delete: ";
    fflush(stdin);
    cin >> accountToDelete;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in|ios::binary);
    if(!fin){
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fin.read((char*)&c, sizeof(c));
    while(fin.eof() == 0){
        if(accountToDelete == c.getAccountNumber()){
            c.viewMyInfo();
            accountFound = true;
            break;
        }
        fin.read((char*)&c, sizeof(c));
    }
    fin.close();

    if(accountFound == true){
        cout << "Are you sure you want to delete this account? [y/n]: ";
        while(1){
            ch = getch();
            if(ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N'){
                cout << ch;
                choice = ch;
                break;
            }
        }
        if(choice == 'y' || choice == 'Y'){
            fout.open("./data/temp.bank", ios::out|ios::binary);
            fin.open("./data/customer.bank", ios::in|ios::binary);
        if(!fin){
            perror("Error");
            Sleep(2000);
            exit(1);
        }else{
            fin.read((char*)&c, sizeof(c));
            while(fin.eof() == 0){
                if(c.getAccountNumber() != accountToDelete){
                    fout.write((char*)&c, sizeof(c));
                }
                fin.read((char*)&c, sizeof(c));
            }
        }
        fin.close();
        fout.close();
        remove("./data/customer.bank");
        rename("./data/temp.bank", "./data/customer.bank");
        cout << "Account deleted successfully" << endl;
        Sleep(2500);
        }
    }else{
        cout << "This account does not exists" << endl;
        Sleep(2000);
    }
}

void Admin::createCustomerDatabaseBackup(){
    string fileName;
    Customer c;
    ifstream fin;
    ofstream fout;
    fileName = "./data/backup/";
    char fname[16];
    char date[50];
    time_t t;
    time(&t);
    strcpy(date, ctime(&t));
    fileName += date[0];
    fileName += date[1];
    fileName += date[2];
    fileName += " ";
    fileName += date[4];
    fileName += date[5];
    fileName += date[6];
    fileName += " ";
    fileName += date[8];
    fileName += date[9];
    fileName += " ";
    fileName += date[20];
    fileName += date[21];
    fileName += date[22];
    fileName += date[23];
    fileName += ".bank";
    fin.open("./data/customer.bank", ios::in|ios::binary);
    fout.open(fileName, ios::out|ios::binary);
    fin.read((char*)&c, sizeof(c));
    while(fin.eof() == 0){
        fout.write((char*)this, sizeof(*this));
        fin.read((char*)&c, sizeof(c));
    }
    fin.close();
    fout.close();
    createCustomerDatabaseBackupAnimation();
}

void Admin::createCustomerDatabaseBackupAnimation(){
    int i;
    system("cls");
    system("color 09");
    CursorPosition(50, 10);
    printf("Creating Backup");
    CursorPosition(40, 12);
    printf("[");
    CursorPosition(78, 12);
    printf("]");
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        printf("%c", 177);
    }
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        Sleep(35);
        printf("%c", 219);
    }
    CursorPosition(0, 0);
    system("cls");
    system("color 0A");
    printf("Backup Created Successfully");
    Sleep(2000);
    system("cls");
}

int Currency::generateCurrencyCode(){
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/currency.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File does not exists" << endl;
    }
    else
    {
        while (1)
        {
            num = (rand() % 90) + 10;
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->code == num)
                {
                    isFound = true;
                    break;
                }
                fin.read((char *)this, sizeof(*this));
            }
            if (isFound == false)
            {
                break;
            }
        }
    }
    fin.close();
    return num;
}

void Currency::addCurrency(){
    ofstream fout;
    this->code = generateCurrencyCode();
    cout << "Enter currency name: ";
    fflush(stdin);
    gets(name);
    symbol[0] = toupper(name[0]);
    symbol[1] = toupper(name[1]);
    symbol[2] = toupper(name[2]);
    system("cls");
    cout << "Enter rate of " << name << ": ";
    fflush(stdin);
    cin >> this->rate;
    if(this->rate < 0){
        this->rate = 0.0;
    }
    fout.open("./data/currency.bank", ios::app|ios::binary);
    fout.write((char*)this, sizeof(*this));
    fout.close();
    cout << "Currency added successfully" << endl;
    Sleep(1500);
}