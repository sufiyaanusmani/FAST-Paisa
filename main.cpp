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

FILE *locBit;
FILE *locBit1;
FILE *locBit2;
FILE *locBit3;
FILE *locBit4;
FILE *MainCRET;

int mainMenu();
void loginAsCustomer();
void init();
void fillData(char[256], char[30], char[256]);
int sendMail(int);
void bankPolicy();

class Customer; // formal declaration for use in class: Bank
class TaxationDepartment;
class Bank
{
private:
    const string name;
    unsigned long long int totalAmountInBank;
    int totalAccounts;
public:
    Bank() : name("FAST NUCES BANK")
    {
        totalAmountInBank = calculateTotalAmount();
        totalAccounts = calculateTotalAccounts();
    }
    unsigned long long int calculateTotalAmount();
    int calculateTotalAccounts();
    friend class TaxationDepartment;
};

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
    virtual int generateAccountNumber() = 0;
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
    char *getName();
    int getAccountNumber();
    char getGender();
    int getAge();
    char *getCNIC();
    char *getContactNumber();
    char *getEmail();
    virtual void storeData() = 0;
    void readData();
    void setAge();
    virtual void login() = 0;
    virtual void viewMyInfo() = 0;
    virtual void portal() = 0;
    virtual int portalMenu() = 0;
    virtual void deleteAccount() = 0;
    virtual void accountSetting() = 0;
    virtual void updateEmail(int) = 0;
    virtual void updateInfo(int) = 0;
    virtual void updateContactNumber(int) = 0;
    virtual void changePassword(int) = 0;
};

class Customer : public User
{
private:
    unsigned long long int amount;
    int generateAccountNumber();

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
    void storeData();
    void deleteAccount();
    unsigned long long int getAmount();
    void accountSetting();
    void updateEmail(int);
    void updateInfo(int);
    void updateContactNumber(int);
    void changePassword(int);
};

class Admin : public User
{
private:
    int generateAccountNumber();

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
    void searchCustomer();
    void searchByAccountNumber();
    void searchByName();
    void sortAscending();
    void sortDescending();
    void accountSetting();
    void updateEmail(int);
    void updateInfo(int);
    void updateContactNumber(int);
    void changePassword(int);
    void generateReport();
    void viewCustomerAccounts();
};

class SuperAdmin : public Admin
{
public:
    void addAdmin();
    void deleteAdmin();
    void portal();
    int portalMenu();
    void viewCurrentRevenue();
    void viewAdmins();
    void manageAdmins();
};

class Transaction
{
private:
    int transactionID;
    int accountNumber;
    char customerName[40];
    unsigned long long int amount;
    char transactionType[9];
    int generateTransactionID();

public:
    void storeTransaction(int, char[40], unsigned long long int, char[9]);
    void viewTransactionHistoryAdmin();
    void viewTransactionHistoryCustomer(int);
    char *getName();
    int getAccountNumber();
    unsigned long long int getAmount();
    char *getTransactionType();
    int getTransactionID();
};

class Currency
{
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
    void setRate(float);
    void addCurrency(int, char[25], char[4], float);
};

class TaxationDepartment{
    private:
        const float taxRate;
        Bank bank;
    public:
        TaxationDepartment():taxRate(0.15){

        }
        double calculateTax();
        void showInfo();
};

int main()
{
    // system("mode 134, 32");
    int mainMenuChoice;
    Customer c;
    Admin a;
    Currency cur;
    TaxationDepartment taxationDep;
    // init();
    while (1)
    {
        system("cls");
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
            cur.viewCurrencyRates();
            break;
        case 5:
            system("cls");
            system("title About Us");
            aboutUs();
            break;
        case 6:
            system("cls");
            taxationDep.showInfo();
            break;
        case 7:
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
    bankPolicy();
    char mailContent[256];
    char accNo[7];
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
    cout << "Rs. " << this->amount << endl
         << endl;
    cout << "\nAre your sure you want to create your account: [y/n]: ";
    std::sprintf(accNo, "%llu", accountNumber);
    accNo[6] = '\0';
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
        strcpy(mailContent, "Dear User,\nWelcome to FAST-NUCES BANK. Your account is successfully registered\n");
        strcat(mailContent, "Your account information:\nName: ");
        strcat(mailContent, this->name);
        strcat(mailContent, "\nAccount Number: ");
        strcat(mailContent, accNo);
        strcat(mailContent, "\nCNIC: ");
        strcat(mailContent, this->cnic);
        strcat(mailContent, "\n\nIn case of any queries, please contact us at fastnucesbank@gmail.com\n\nRegards,\nFAST-NUCES BANK");
        fillData("Welcome to FAST-NUCES Bank", this->email, mailContent);
        sendMail(0);
        Sleep(1000);
    }
}

int Customer::generateAccountNumber()
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
    TextColor(4);
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
    TextColor(15);
}

void Customer::storeData()
{
    ofstream fout;
    fout.open("./data/customer.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

unsigned long long int Customer::getAmount()
{
    return amount;
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
    TextColor(4);
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
    TextColor(15);
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
            Customer::accountSetting();
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
    char ch;
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
    cout << "6. Account Settings";
    CursorPosition(33, 19);
    cout << "7. Logout";
    CursorPosition(32, 22);
    TextColor(5);
    cout << "Enter your choice: ";
    fflush(stdin);
    while (1)
    {
        ch = getch();
        if (ch >= '1' && ch <= '7')
        {
            cout << ch;
            choice = ch - '0';
        }
        else if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            cout << "\b \b";
        }
    }
    system("color 0F");
    return choice;
}

void Customer::depositAmount()
{
    Transaction t;
    char mailContent[256], e[30];
    char transactionid[7], amt[20], bal[20];
    unsigned long long int amountToDeposit = 0, newAmount;
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
                newAmount = this->amount;
                strcpy(e, this->email);
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char *)this, sizeof(*this));
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        // SetColor();
        cout << "\nRs. " << amountToDeposit << " deposited successfully" << endl;
        t.storeTransaction(accNo, n, amountToDeposit, "Deposit");
        strcpy(mailContent, "Trx ID: ");
        std::sprintf(transactionid, "%d", t.getTransactionID());
        transactionid[6] = '\0';
        strcat(mailContent, transactionid);
        strcat(mailContent, ". You have successfully deposited Rs. ");
        std::sprintf(amt, "%llu", amountToDeposit);
        amt[strlen(amt)] = '\0';
        strcat(mailContent, amt);
        strcat(mailContent, " and your new balance is Rs. ");
        std::sprintf(bal, "%llu", newAmount);
        bal[strlen(bal)] = '\0';
        strcat(mailContent, bal);
        strcat(mailContent, ". The fee for this transaction is 0.00");

        // strcpy(mailContent, "Trx ID: ");
        // strcat(mailContent, transactionid);
        strcpy(mailContent, "Dear Customer,\nRs. ");
        strcat(mailContent, amt);
        strcat(mailContent, " has been deposited successfully to your account");
        fillData("Amount Deposited", e, mailContent);
        // puts(mailContent);
        // getch();
        sendMail(0);
        Sleep(2000);
    }
amountToDepositEnd:
    system("cls");
}

void Customer::withdrawAmount()
{
    unsigned long long int amountToWithdraw;
    char mailContent[256], amt[20], e[30];
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
                strcpy(e, this->email);
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char *)this, sizeof(*this));
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        // SetColor();
        cout << "\nRs. " << amountToWithdraw << " withdrawn successfully" << endl;
        t.storeTransaction(accNo, n, amountToWithdraw, "Withdraw");
        std::sprintf(amt, "%llu", amountToWithdraw);
        strcpy(mailContent, "Dear Customer,\nRs. ");
        strcat(mailContent, amt);
        strcat(mailContent, " has been withdrawn successfully from your account");
        fillData("Amount Withdrawn", e, mailContent);
        sendMail(0);
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
    while (1)
    {
        cout << "Enter receiver's account number (-1 to go back): ";
        fflush(stdin);
        cin >> receiverAccount;
        system("cls");
        if (receiverAccount == senderAccount)
        {
            cout << "You can not transfer to yourself" << endl;
        }
        else if (receiverAccount == -1)
        {
            goto transferAmountEnd;
        }
        else
        {
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

void Customer::deleteAccount()
{
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
        fout.open("./data/temp.bank", ios::out | ios::binary);
        fin.open("./data/customer.bank", ios::in | ios::binary);
        if (!fin)
        {
            perror("Error");
            Sleep(2000);
            exit(1);
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->accountNumber != accNo)
                {
                    fout.write((char *)this, sizeof(*this));
                }
                fin.read((char *)this, sizeof(*this));
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

void Admin::storeData()
{
    ofstream fout;
    fout.open("./data/admin.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        Sleep(2500);
        exit(1);
    }
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

void Admin::login()
{
    int id;
    SuperAdmin superAdmin;
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
        if (id == 213195)
        {
            cout << "Enter your password: ";
            inputPassword(pass);
            if (strcmp(pass, "sufiyaan") == 0)
            {
                fin.close();
                loadingAnimation();
                superAdmin.portal();
            }
        }
        else
        {
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
}

void Admin::createNewAccount() // this will only be accessed by SuperAdmin
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
        Admin::storeData();
        cout << "Account created successfully\n";
        Sleep(1000);
    }
}

void Admin::portal()
{
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
            viewCustomerAccounts();
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
            system("title ADD NEW CURRENCY");
            cur.addCurrency();
            break;
        case 6:
            system("cls");
            system("title UPDATE CURRENCY RATES");
            cur.updateCurrencyRate();
            break;
        case 7:
            system("cls");
            system("title SEARCH");
            searchCustomer();
            break;
        case 8:
            system("cls");
            system("title CREATING DATABASE BACKUP...");
            createCustomerDatabaseBackup();
            break;
        case 9:
            system("cls");
            system("title ACCOUNT SETTING");
            Admin::accountSetting();
            break;
        case 10:
            main();
            break;
        case 11:
            generateReport();
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

int Admin::portalMenu()
{
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
    for (i = 1; i <= 21; i++)
    {
        CursorPosition(31, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 21; i++)
    {
        CursorPosition(91, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 27);
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
    cout << "5. Add new currency";
    CursorPosition(33, 17);
    cout << "6. Update Currency Rates";
    CursorPosition(33, 19);
    cout << "7. Search and Sort Customers";
    CursorPosition(33, 21);
    cout << "8. Create Customer Database Backup";
    CursorPosition(33, 23);
    cout << "9. Account Settings";
    CursorPosition(33, 25);
    cout << "10. Logout";
    CursorPosition(32, 28);
    cout << "Enter your choice: ";
    fflush(stdin);
    cin >> choice;
    return choice;
}

void Admin::viewMyInfo()
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

    cout << "Press any key to go to your portal\n";
    getch();
    system("color 0F");
}

void Admin::viewCustomerAccounts()
{
    ifstream fin;
    Customer c;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        exit(1);
    }
    fin.read((char *)&c, sizeof(c));
    TextColor(4);
    cout << "Account No  " << setw(40) << "  Name  " << endl;
    TextColor(15);
    while (fin.eof() == 0)
    {
        cout << c.getAccountNumber() << "      " << setw(40) << c.getName() << "  " << c.getAge() << "  " << (c.getGender() == 'm' ? "Male" : "Female") << "  " << c.getContactNumber() << "  " << c.getCNIC() << "  " << setw(30) << c.getEmail() << "  " << c.getAmount() << endl;
        fin.read((char *)&c, sizeof(c));
    }
    fin.close();
    TextColor(13);
    cout << "Press any key to continue..." << endl;
    getch();
}

int Transaction::generateTransactionID()
{
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

void Transaction::storeTransaction(int accountNumber, char name[40], unsigned long long int amount, char type[9])
{
    ofstream fout;
    fout.open("./data/transaction.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        Sleep(3000);
        exit(1);
    }
    this->transactionID = generateTransactionID();
    this->accountNumber = accountNumber;
    strcpy(customerName, name);
    this->amount = amount;
    strcpy(transactionType, type);
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

void Transaction::viewTransactionHistoryAdmin()
{
    ifstream fin;
    fin.open("./data/transaction.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    TextColor(4);
    cout << "Trx ID                  Name  Acc No      Amount  Transaction Type" << endl;
    TextColor(15);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        cout << this->transactionID << "  " << setw(20) << this->customerName << "  " << this->accountNumber << "  " << setw(10) << this->amount << "  " << this->transactionType << endl;
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    TextColor(5);
    cout << "\nPress any key to continue...";
    CursorPosition(0, 0);
    getch();
}

void Transaction::viewTransactionHistoryCustomer(int accNo)
{
    ifstream fin;
    fin.open("./data/transaction.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    cout << "Transaction ID  Amount  Transaction Type" << endl;
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        if (this->accountNumber == accNo)
        {
            cout << this->transactionID << "  "
                 << "  " << this->amount << "  " << this->transactionType << endl;
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    cout << "Press any key to continue..." << endl;
    getch();
}

int User::getAccountNumber()
{
    return accountNumber;
}

void Admin::deleteAccount()
{
    int accountToDelete;
    char ch, choice;
    ofstream fout;
    Customer c;
    bool accountFound = false;
    cout << "Enter account number to delete: ";
    fflush(stdin);
    cin >> accountToDelete;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fin.read((char *)&c, sizeof(c));
    while (fin.eof() == 0)
    {
        if (accountToDelete == c.getAccountNumber())
        {
            c.viewMyInfo();
            accountFound = true;
            break;
        }
        fin.read((char *)&c, sizeof(c));
    }
    fin.close();

    if (accountFound == true)
    {
        cout << "Are you sure you want to delete this account? [y/n]: ";
        while (1)
        {
            ch = getch();
            if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
            {
                cout << ch;
                choice = ch;
                break;
            }
        }
        if (choice == 'y' || choice == 'Y')
        {
            fout.open("./data/temp.bank", ios::out | ios::binary);
            fin.open("./data/customer.bank", ios::in | ios::binary);
            if (!fin)
            {
                perror("Error");
                Sleep(2000);
                exit(1);
            }
            else
            {
                fin.read((char *)&c, sizeof(c));
                while (fin.eof() == 0)
                {
                    if (c.getAccountNumber() != accountToDelete)
                    {
                        fout.write((char *)&c, sizeof(c));
                    }
                    fin.read((char *)&c, sizeof(c));
                }
            }
            fin.close();
            fout.close();
            remove("./data/customer.bank");
            rename("./data/temp.bank", "./data/customer.bank");
            cout << "Account deleted successfully" << endl;
            Sleep(2500);
        }
    }
    else
    {
        cout << "This account does not exists" << endl;
        Sleep(2000);
    }
}

void Admin::createCustomerDatabaseBackup()
{
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
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fout.open(fileName, ios::out | ios::binary);
    fin.read((char *)&c, sizeof(c));
    while (fin.eof() == 0)
    {
        fout.write((char *)this, sizeof(*this));
        fin.read((char *)&c, sizeof(c));
    }
    fin.close();
    fout.close();
    createCustomerDatabaseBackupAnimation();
}

void Admin::createCustomerDatabaseBackupAnimation()
{
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

int Currency::generateCurrencyCode()
{
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

void Currency::addCurrency()
{
    char ch;
    int i;
    i = 0;
    ofstream fout;
    this->code = generateCurrencyCode();
    cout << "Enter currency name: ";
    fflush(stdin);
    gets(name);
    system("cls");
    cout << "Enter symbol (3 characters): ";
    fflush(stdin);
    while (1)
    {
        ch = getch();
        if (ch >= 'A' && ch <= 'Z' && i < 3)
        {
            cout << ch;
            symbol[i] = ch;
            i++;
        }
        else if (ch >= 'a' && ch <= 'z' && i < 3)
        {
            ch = ch - 32;
            cout << ch;
            symbol[i] = ch;
            i++;
        }
        else if (i == 3 && ch == 13)
        {
            break;
        }
    }
    symbol[3] = '\0';
    system("cls");
    cout << "Enter rate of " << name << ": ";
    fflush(stdin);
    float r;
    cin >> r;
    setRate(r);
    fout.open("./data/currency.bank", ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
    cout << "Currency added successfully" << endl;
    Sleep(1500);
}

char *User::getName()
{
    return name;
}

void Currency::viewCurrencyRates()
{
    ifstream fin;
    fin.open("./data/currency.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        cout << this->code << " " << this->name << " " << this->symbol << " " << this->rate << endl;
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    cout << endl
         << "Press any key to continue...";
    getch();
}

void Currency::updateCurrencyRate()
{
    system("cls");
    int code1;
    viewCurrencyRates();
    cout << "\nEnter currency code to update: ";
    cin >> code1;
    bool found = false;
    fstream file;
    ifstream fin;
    float r1;
    fin.open("./data/currency.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        if (this->code == code1)
        {
            found = true;
            break;
        }
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
    if (found == true)
    {
        cout << "Enter new rate: ";
        cin >> r1;
        file.open("./data/currency.bank", ios::in | ios::out | ios::ate | ios::binary);
        file.seekg(0);
        while (file.eof() == 0)
        {
            if (this->code == code1)
            {
                setRate(r1);
                file.seekp(file.tellp() - sizeof(*this));
                file.write((char *)this, sizeof(*this));
                found = true;
            }
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        system("cls");
        cout << "Rate update successfully" << endl;
    }
    else
    {
        system("cls");
        cout << "This currency does not exists, enter valid code" << endl;
    }
    Sleep(1500);
}

void Currency::setRate(float rate)
{
    if (rate < 0)
    {
        this->rate = 0.0;
    }
    else
    {
        this->rate = rate;
    }
}

void Admin::searchCustomer()
{
    int choice;
    cout << "1. Search by Account Number" << endl;
    cout << "2. Search by Name" << endl;
    cout << "3. Sort by amount (ASCENDING)" << endl;
    cout << "4. Sort by amount (DESCENDING)" << endl;
    cout << "5. Go back" << endl
         << endl;
    ;
    TextColor(10);
    cout << "Enter your choice: ";
    fflush(stdin);
    TextColor(15);
    cin >> choice;

    system("cls");
    switch (choice)
    {
    case 1:
        searchByAccountNumber();
        break;
    case 2:
        searchByName();
        break;
    case 3:
        sortAscending();
        break;
    case 4:
        sortDescending();
        break;
    case 5:
        break;
    default:
        cout << "Wrong choice entered, please enter a correct choice" << endl;
        Sleep(1500);
        break;
    }
}

void Admin::searchByAccountNumber()
{
    int accountNumberToSearch;
    ifstream fin;
    bool accountFound = false;
    Customer c;
    system("cls");
    while (1)
    {
        cout << "Enter account number to search: ";
        fflush(stdin);
        cin >> accountNumberToSearch;
        fin.open("./data/customer.bank", ios::in | ios::binary);
        fin.read((char *)&c, sizeof(c));
        while (fin.eof() == 0)
        {
            if (accountNumberToSearch == c.getAccountNumber())
            {
                accountFound = true;
                c.viewMyInfo();
                goto searchByAccountNumberEnd;
            }
            fin.read((char *)&c, sizeof(c));
        }
        if (accountFound == false)
        {
            system("cls");
            cout << "This account does not exists" << endl;
            Sleep(2000);
            goto searchByAccountNumberEnd;
        }
    }
searchByAccountNumberEnd:
    fin.close();
}

void Admin::searchByName()
{
    char name[40];
    bool found = false;
    int total = 0;
    ifstream fin;
    Customer c;
    system("cls");
    cout << "Enter full name: ";
    fflush(stdin);
    gets(name);
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)&c, sizeof(c));
    while (1)
    {
        while (fin.eof() == 0)
        {
            if (strcmp(name, c.getName()) == 0)
            {
                found = true;
                system("color 0B");
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
                total++;
                cout << endl;
            }
            fin.read((char *)&c, sizeof(c));
        }
        if (found == true)
        {
            cout << "There are currently " << total << " account(s) with this name" << endl;
            cout << "\nPress any key to continue..." << endl;
            getch();
        }
        else
        {
            cout << "There are no account with this name" << endl;
            Sleep(2000);
        }
    }
searchByNameEnd:
    fin.close();
}

void Admin::sortAscending()
{
    int size, i, j;
    size = 0;
    Customer *cust;
    Customer c, temp;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)&c, sizeof(c));
    while (fin.eof() == 0)
    {
        size++;
        fin.read((char *)&c, sizeof(c));
    }
    fin.close();
    if (size != 0)
    {
        cust = new Customer[size];
        i = 0;
        fin.open("./data/customer.bank", ios::in | ios::binary);
        fin.read((char *)&c, sizeof(c));
        while (fin.eof() == 0)
        {
            *(cust + i) = c;
            i++;
            fin.read((char *)&c, sizeof(c));
        }
        fin.close();
        for (i = 1; i < size; i++)
        {
            for (j = 0; j < size - i; j++)
            {
                if (cust[j].getAmount() > cust[j + 1].getAmount())
                {
                    temp = cust[j];
                    cust[j] = cust[j + 1];
                    cust[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < size; i++)
        {
            cout << cust[i].getAccountNumber() << "      " << setw(40) << cust[i].getName() << "  " << cust[i].getAge() << "  " << (cust[i].getGender() == 'm' ? "Male" : "Female") << "  " << cust[i].getContactNumber() << "  " << cust[i].getCNIC() << "  " << cust[i].getEmail() << "  " << cust[i].getAmount() << endl;
        }
        cout << "\nPress any to continue..." << endl;
        getch();
    }
    else
    {
        cout << "Empty" << endl;
    }
    delete[] cust;
    cust = NULL;
}

int User::getAge()
{
    return age;
}

char User::getGender()
{
    return gender;
}

char *User::getContactNumber()
{
    return contactNumber;
}

char *User::getCNIC()
{
    return cnic;
}

char *User::getEmail()
{
    return email;
}

void Admin::sortDescending()
{
    int size, i, j;
    size = 0;
    Customer *cust;
    Customer c, temp;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)&c, sizeof(c));
    while (fin.eof() == 0)
    {
        size++;
        fin.read((char *)&c, sizeof(c));
    }
    fin.close();
    if (size != 0)
    {
        cust = new Customer[size];
        i = 0;
        fin.open("./data/customer.bank", ios::in | ios::binary);
        fin.read((char *)&c, sizeof(c));
        while (fin.eof() == 0)
        {
            *(cust + i) = c;
            i++;
            fin.read((char *)&c, sizeof(c));
        }
        fin.close();
        for (i = 1; i < size; i++)
        {
            for (j = 0; j < size - i; j++)
            {
                if (cust[j].getAmount() < cust[j + 1].getAmount())
                {
                    temp = cust[j];
                    cust[j] = cust[j + 1];
                    cust[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < size; i++)
        {
            cout << cust[i].getAccountNumber() << "      " << setw(40) << cust[i].getName() << "  " << cust[i].getAge() << "  " << (cust[i].getGender() == 'm' ? "Male" : "Female") << "  " << cust[i].getContactNumber() << "  " << cust[i].getCNIC() << "  " << cust[i].getEmail() << "  " << cust[i].getAmount() << endl;
        }
        cout << "\nPress any to continue..." << endl;
        getch();
    }
    else
    {
        cout << "Empty" << endl;
    }
    delete[] cust;
    cust = NULL;
}

void Customer::accountSetting()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "1. Update my email" << endl;
        cout << "2. Update my contact number" << endl;
        cout << "3. Change my password" << endl;
        cout << "4. Delete my account" << endl;
        cout << "5. Go back" << endl;
        cout << endl
             << "Enter your choice: ";
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
        case 1:
            Customer::updateEmail(this->accountNumber);
            break;
        case 2:
            Customer::updateContactNumber(this->accountNumber);
            break;
        case 3:
            Customer::changePassword(this->accountNumber);
            break;
        case 4:
            Customer::deleteAccount();
            break;
        case 5:
            goto customerAccountSettingEnd;
            break;
        default:
            cout << "Enter a valid choice" << endl;
            break;
        }
    }
customerAccountSettingEnd:
    system("cls");
}

void Customer::updateInfo(int accNo)
{
    fstream file;
    Customer c;
    file.open("./data/customer.bank", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)&c, sizeof(c));
    while (file.eof() == 0)
    {
        if (c.accountNumber == accNo)
        {
            file.seekp(file.tellp() - sizeof(c));
            file.write((char *)this, sizeof(*this));
            break;
        }
        file.read((char *)&c, sizeof(c));
    }
    file.close();
}

void Customer::updateEmail(int accNo)
{
    setEmail();
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Customer::updateInfo(accNo);
    }
}

void Customer::updateContactNumber(int accNo)
{
    setContactNumber();
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Customer::updateInfo(accNo);
    }
}

void Customer::changePassword(int accNo)
{
    char passToConfirm[20];
    cout << "Enter your password to confirm: ";
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        system("cls");
        system("title ENTER NEW PASSWORD");
        setPassword();
        Customer::updateInfo(accNo);
    }
}

void Admin::accountSetting()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "1. Update my email" << endl;
        cout << "2. Update my contact number" << endl;
        cout << "3. Change my password" << endl;
        cout << "4. Go back" << endl;
        cout << endl
             << "Enter your choice: ";
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
        case 1:
            Admin::updateEmail(this->accountNumber);
            break;
        case 2:
            Admin::updateContactNumber(this->accountNumber);
            break;
        case 3:
            Admin::changePassword(this->accountNumber);
            break;
        case 4:
            goto adminAccountSettingEnd;
            break;
        default:
            cout << "Enter a valid choice" << endl;
            break;
        }
    }
adminAccountSettingEnd:
    system("cls");
}

void Admin::updateInfo(int accNo)
{
    fstream file;
    Admin a;
    file.open("./data/admin.bank", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)&a, sizeof(a));
    while (file.eof() == 0)
    {
        if (a.accountNumber == accNo)
        {
            file.seekp(file.tellp() - sizeof(a));
            file.write((char *)this, sizeof(*this));
            break;
        }
        file.read((char *)&a, sizeof(a));
    }
    file.close();
}

void Admin::updateEmail(int accNo)
{
    setEmail();
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Admin::updateInfo(accNo);
    }
}

void Admin::updateContactNumber(int accNo)
{
    setContactNumber();
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Admin::updateInfo(accNo);
    }
}

void Admin::changePassword(int accNo)
{
    char passToConfirm[20];
    cout << "Enter your password to confirm: ";
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        system("cls");
        system("title ENTER NEW PASSWORD");
        setPassword();
        Admin::updateInfo(accNo);
    }
}

void Admin::generateReport()
{
    ifstream fin;
    ofstream fout;
    Transaction t;
    fin.open("./data/transaction.bank", ios::in | ios::binary);
    fout.open("a.csv", ios::out);
    fout << "Name,Account_Number,Amount,Type" << endl;
    fin.read((char *)&t, sizeof(t));
    while (fin.eof() == 0)
    {
        fout << t.getName() << "," << t.getAccountNumber() << "," << t.getAmount() << "," << t.getTransactionType() << endl;
        fin.read((char *)&t, sizeof(t));
    }
    fin.close();
    fout.close();
}

int Transaction::getAccountNumber()
{
    return accountNumber;
}

char *Transaction::getName()
{
    return customerName;
}

unsigned long long int Transaction::getAmount()
{
    return amount;
}

char *Transaction::getTransactionType()
{
    return transactionType;
}

void init()
{
    locBit = fopen("./tmp/GmailUR.txt", "w");
    locBit1 = fopen("./tmp/Mail.txt", "w");
    locBit2 = fopen("./tmp/Message.txt", "w");
    locBit3 = fopen("./tmp/PassUR.txt", "w");
    locBit4 = fopen("./tmp/Subject.txt", "w");
    MainCRET = fopen("./tmp/Mail.aysoat", "w");
    fprintf(MainCRET, "import smtplib\nurm=open('./tmp/GmailUR.txt','r')\nurp=open('./tmp/PassUR.txt','r')\nsocmail = urm.read()\npassword = urp.read()\nsub = open('./tmp/Subject.txt','r')\nsubject = sub.read()\nsandesh = open('./tmp/Message.txt','r')\nsmessage = sandesh.read()\nmailid = open('./tmp/Mail.txt','r')\nj = mailid.readline()\nEmail=j.split()\ns = smtplib.SMTP('smtp.gmail.com', 587)\ns.starttls()\ns.login(socmail, password)\nbody = ''\nding = 'Subject:{}{}'.format(subject, body)\nmessage = ding+smessage\n#print('Message Sent to',Email)\ns.sendmail(socmail, Email, smessage)\nprint('Done')\n\n");
    fclose(MainCRET);
    //	return 0;
}

void fillData(char SUBJECT[256], char SENDMAIL[30], char MESSAGE[256])
{
    init();
    fprintf(locBit, "%s", "fastnucesbank@gmail.com");
    fprintf(locBit3, "%s", "Hehe.123456");
    fprintf(locBit1, "%s", SENDMAIL);
    fprintf(locBit4, "%s", SUBJECT);
    fprintf(locBit2, "%s", MESSAGE);
    fclose(locBit);
    fclose(locBit1);
    fclose(locBit2);
    fclose(locBit3);
    fclose(locBit4);
}

int sendMail(int returnVal)
{
    system("python ./tmp/Mail.aysoat");
    switch (returnVal)
    {
    case 0:
        return 0;
        break;
    case -1:
        return -1;
        break;
    default:
        return 0;
        break;
    }
    system("attrib -h -s ./tmp/Mail.aysoat");
    return 0;
}

int Transaction::getTransactionID()
{
    return transactionID;
}

void Currency::addCurrency(int code, char n[25], char s[4], float rate)
{
    this->code = code;
    strcpy(name, n);
    strcpy(symbol, s);
    this->rate = rate;
    ofstream fout;
    fout.open("./data/currency.bank", ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

void bankPolicy()
{
    system("cls");
    system("title Bank Policy");
    system("color F0");
    TextColor(0);
    printf("By signing, you, the individual(s) named in this form are:\n\n");
    TextColor(1);
    printf("1. Confirming you are applying to the Bank for banking services;\n");
    printf("2. Confirming that any details you have supplied to us are true and complete;\n");
    printf("3. Authorizing us to:\n");
    printf("        i.  Make credit reference and other inquiries in connection with this application in accordance with our\n");
    printf("            normal procedures; and\n");
    printf("        ii. Disclose information to licensed credit reference agencies and otherwise in accordance with\n");
    printf("            conditions 94-105 of General Terms and Conditions.\n");
    printf("4. Confirming that you understand that credit reference agencies record information and the information they\n");
    printf("   record may be used by other organizations to help make decisions about credit and credit-related services and\n");
    printf("   to manage accounts for customers and for fraud prevention.\n");
    printf("5. Agreeing to be bound by the terms of the application and the Bank's General Terms and Conditions which contain\n");
    printf("   your obligations to us and our obligations to you which may be altered from time to time;\n");
    printf("6. Understanding that the Bank may decline your account without stating a reason.\n");
    printf("7. Contact the admin directly in case of any issues\n");
    printf("\nPress any key to continue...");
    getch();
    system("cls");
    system("color F4");
    TextColor(4);
    printf("Before proceeding further:\n");
    TextColor(0);
    printf("1.	Make sure to record your account number\n");
    printf("2.	In case you forgot your account number, contact the admin, and provide your full information for authentication\n");
    printf("3.	Make sure to log out of your account after use.\n");
    printf("4.	Make sure to read the user guide before using Banking System\n\n");

    TextColor(4);
    printf("The Bank will not be responsible if:\n");
    TextColor(0);
    printf("1.	User forgets to log out of his/her account\n");
    printf("2.	User edits, modifies or deletes the database files\n\n");
    TextColor(2);
    printf("Press any key to continue...");
    getch();
    system("cls");
    system("color 0F");
}

void SuperAdmin::portal()
{
    system("cls");
    int adminPortalChoice, accNo;
    accNo = this->accountNumber;
    ifstream fin;

    while (1)
    {
        adminPortalChoice = SuperAdmin::portalMenu();
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
            viewCustomerAccounts();
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
            system("title ADD NEW CURRENCY");
            cur.addCurrency();
            break;
        case 6:
            system("cls");
            system("title UPDATE CURRENCY RATES");
            cur.updateCurrencyRate();
            break;
        case 7:
            system("cls");
            system("title SEARCH");
            searchCustomer();
            break;
        case 8:
            system("cls");
            system("title CREATING DATABASE BACKUP...");
            createCustomerDatabaseBackup();
            break;
        case 9:
            system("cls");
            system("title MANAGE ADMINS");
            manageAdmins();
            break;
        case 10:
            viewCurrentRevenue();
            break;
        case 11:
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

int SuperAdmin::portalMenu()
{
    int choice;
    system("color 1F");
    int i;
    system("cls");
    system("title ADMIN PORTAL");
    CursorPosition(0, 0);
    TextColor(15);
    currentDateAndTime();
    CursorPosition(0, 2);
    TextColor(15);
    cout << "Welcome, Mr. Sufiyaan Usmani" << endl;
    CursorPosition(32, 5);
    TextColor(4);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 21; i++)
    {
        CursorPosition(31, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 21; i++)
    {
        CursorPosition(91, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 27);
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
    cout << "5. Add new currency";
    CursorPosition(33, 17);
    cout << "6. Update Currency Rates";
    CursorPosition(33, 19);
    cout << "7. Search and Sort Customers";
    CursorPosition(33, 21);
    cout << "8. Create Customer Database Backup";
    CursorPosition(33, 23);
    cout << "9. Manage Admins";
    CursorPosition(33, 25);
    cout << "10. View Revenue";
    CursorPosition(33, 27);
    cout << "11. Logout";
    CursorPosition(32, 30);
    cout << "Enter your choice: ";
    fflush(stdin);
    cin >> choice;
    return choice;
}

int Admin::generateAccountNumber()
{
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/admin.bank", ios::in | ios::binary);
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

void SuperAdmin::manageAdmins()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "1. View admins" << endl;
        cout << "2. Add new admin" << endl;
        cout << "3. Delete admin" << endl;
        cout << "4. Go Back" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            viewAdmins();
        }
        else if (choice == 2)
        {
            addAdmin();
        }
        else if (choice == 3)
        {
            deleteAdmin();
        }
        else if (choice == 4)
        {
            SuperAdmin::portal();
        }
        else
        {
            cout << "Wrong choice entered, enter a valid choice";
            Sleep(1500);
        }
    }
}

void SuperAdmin::addAdmin()
{
    Admin temp;
    system("cls");
    temp.createNewAccount();
}

void SuperAdmin::viewAdmins()
{
    Admin temp;
    ifstream fin;
    fin.open("data/admin.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fin.read((char *)&temp, sizeof(temp));
    while (fin.eof() == 0)
    {
        cout << temp.getAccountNumber() << "      " << setw(40) << temp.getName() << "  " << temp.getAge() << "  " << (temp.getGender() == 'm' ? "Male" : "Female") << "  " << temp.getContactNumber() << "  " << temp.getCNIC() << "  " << temp.getEmail() << endl;
        fin.read((char *)&temp, sizeof(temp));
    }
    fin.close();
    TextColor(13);
    cout << endl
         << "Press any key to continue..." << endl;
    getch();
}

void SuperAdmin::deleteAdmin()
{
    bool found = false;
    Admin temp;
    ifstream fin;
    ofstream fout;
    viewAdmins();
    int accToDelete;
    string name1;
    cout << "Enter account number to delete: ";
    cin >> accToDelete;
    fin.open("data/admin.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    fin.read((char *)&temp, sizeof(temp));
    while (fin.eof() == 0)
    {
        if (accToDelete == temp.getAccountNumber())
        {
            found = true;
            break;
        }
        fin.read((char *)&temp, sizeof(temp));
    }
    fin.close();
    if (found == true)
    {
        fin.open("data/admin.bank", ios::in | ios::binary);
        fout.open("data/temp.bank", ios::out | ios::binary);
        if (!fin)
        {
            perror("Error");
            Sleep(2000);
            exit(1);
        }
        fin.read((char *)&temp, sizeof(temp));
        while (fin.eof() == 0)
        {
            if (temp.getAccountNumber() != accToDelete)
            {
                fout.write((char *)&temp, sizeof(temp));
            }
            fin.read((char *)&temp, sizeof(temp));
        }
    }
    else
    {
        cout << "This account does not exists" << endl;
        Sleep(2000);
    }
    fin.close();
    fout.close();
    remove("./data/admin.bank");
    rename("./data/temp.bank", "./data/admin.bank");
    cout << "Account deleted successfully" << endl;
    Sleep(2500);
    SuperAdmin::portal();
}

void SuperAdmin::viewCurrentRevenue()
{
    Bank bank;
    int count = bank.calculateTotalAccounts();
    unsigned long long int total = bank.calculateTotalAmount();
    system("cls");
    cout << "Total number of accounts: " << count << endl;
    cout << "Total Amount in bank: Rs. " << total << endl;
    cout << endl << "Press any key to continue..." << endl;
    getch();
}

unsigned long long int Bank::calculateTotalAmount()
{
    ifstream fin;
    Customer temp;
    unsigned long long int total = 0;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        exit(1);
    }
    fin.read((char *)&temp, sizeof(temp));
    while (fin.eof() == 0)
    {
        total += temp.getAmount();
        fin.read((char *)&temp, sizeof(temp));
    }
    fin.close();
    return total;
}

int Bank::calculateTotalAccounts(){
    int count = 0;
    ifstream fin;
    Customer temp;
    fin.open("./data/customer.bank", ios::in|ios::binary);
    if(!fin){
        perror("Error");
        exit(1);
    }
    fin.read((char*)&temp, sizeof(temp));
    while(fin.eof() == 0){
        count++;
        fin.read((char*)&temp, sizeof(temp));
    }
    fin.close();
    return count;
}

double TaxationDepartment::calculateTax(){
    double tax = (double)bank.totalAmountInBank * taxRate;
    return tax;
}

void TaxationDepartment::showInfo(){
    system("cls");
    cout << "Bank Name: " << bank.name << endl;
    cout << "Total number of accounts in bank: " << bank.totalAccounts << endl;
    cout << "Total amount in bank: Rs. " << bank.totalAmountInBank << endl;
    cout << "Tax Rate: " << taxRate*100 << " %" << endl;
    cout << "Tax to be collected from bank: Rs. " << calculateTax() << endl;
    cout << endl << "Press any key to continue..." << endl;
    getch();
}