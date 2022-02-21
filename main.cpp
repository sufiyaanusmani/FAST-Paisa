#include "bank.h"

int mainMenu();
void loginAsCustomer();

int main(){
    int mainMenuChoice;
    Customer c;
    while (1)
    {
        mainMenuChoice = mainMenu();
        switch (mainMenuChoice)
        {
        case 1:
            system("cls");
            system("title Admin Login");
            // loginAsAdmin();
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
            printf("Thankyou for using our service, :)");
            Sleep(2000);
            exit(0);
            break;
        default:
            system("cls");
            system("title ERROR :(");
            CursorPosition(0, 0);
            system("color 4F");
            printf("Wrong choice entered, try again!");
            Beep(1000, 300);
            Sleep(2000);
            system("color 0F");
            break;
        }
    }
    return 0;
}

int mainMenu()
{
    int choice, i;
    system("color 0F");
    system("cls");
    system("title FAST NUCES BANK - MAIN MENU");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(32, 3);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 7; i++)
    {
        CursorPosition(31, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 7; i++)
    {
        CursorPosition(91, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 11);
        printf("-");
    }
    TextColor(15);
    CursorPosition(33, 5);
    cout << "1. Login as Admin";
    CursorPosition(33, 6);
    cout << "2. Login as Customer";
    CursorPosition(33, 7);
    cout << "3. Create new account";
    CursorPosition(33, 8);
    cout << "4. Check today's currency rates";
    CursorPosition(33, 9);
    cout << "5. About Us";
    CursorPosition(33, 10);
    cout << "6. Exit";
    CursorPosition(32, 15);
    cout << "Enter your choice: ";
    fflush(stdin);
    cin >> choice;
    return choice;
}
