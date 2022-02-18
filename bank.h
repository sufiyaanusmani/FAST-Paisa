#ifndef BANK_H
#define BANK_H
#include <string>

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
        virtual void viewMyInfo() = 0;
        virtual void viewTransactionHistory() = 0;
        virtual void deleteAccount() = 0;
        void setName();
        void setGender();
        void setCNIC();
        void setContactNumber();
        void setEmail();
        void setPassword();
};

class Customer: public User{
    private:
        bool accountStatus;
    public:
        void createNewAccount();
        void depositMoney();
        void withdrawMoney();
        void transferMoney();
        void viewTransactionHistory();
};

#endif // !BANK_H