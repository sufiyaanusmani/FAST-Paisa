#ifndef UI_H
#define UI_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <cwchar>
using namespace std;

void CursorPosition(int x, int y)
{

    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void loadingAnimation()
{
    int i;
    system("cls");
    system("color 0A");
    CursorPosition(56, 10);
    cout << "Loading";
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
        Sleep(30);
        printf("%c", 219);
    }
    CursorPosition(0, 0);
    system("cls");
    system("color 0F");
}

void TextColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void currentDateAndTime()
{
    time_t t; // not a primitive datatype
    time(&t);

    cout << ctime(&t);
}

void FontSize(int x, int y){

CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = x;                   // Width of each character in the font
cfi.dwFontSize.Y = y;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = 700;                   //For normal: FW_NORMAL
std::wcscpy(cfi.FaceName, L"Courier"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void box(){
	CursorPosition(40,7);
	TextColor(1);
	for(int i=0;i<40;i++)
	    cout<<"-";
    TextColor(2);
    CursorPosition(44,13);
	cout<<"ThankYou for using Our Service:)";
	TextColor(1);
	for(int i=0;i<11;i++){
		CursorPosition(39,8+i);
	    cout<<"|\n";
	}
	CursorPosition(40,19);
	for(int i=0;i<40;i++)
	   cout<<"-";
	for(int i=0;i<11;i++){
	CursorPosition(80,8+i);
    cout<<"|\n";
	}
	cout<<endl;
}

int mainMenu()
{
    int choice, i;
    char ch;
    system("color 0F");
    system("cls");
    system("title FAST NUCES BANK - MAIN MENU");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(32, 3);
    FontSize(0,21);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 8; i++)
    {
        CursorPosition(31, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 8; i++)
    {
        CursorPosition(91, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 12);
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
    cout << "6. Taxation Department";
    CursorPosition(33, 11);
    cout << "7. Exit";
    CursorPosition(32, 15);
    cout << "Enter your choice: ";
    fflush(stdin);
    i = 0;
    while(1){
        ch = getch();
        if(ch >= '1' && ch <= '7' && i == 0){
            cout << ch;
            choice = ch - '0';
            i++;
        }else if(ch == 13 && i == 1){
            break;
        }else if(ch == 8 && i != 0){
            i--;
            cout << "\b \b";
        }
    }
    return choice;
}

void aboutUs(){
    system("cls");
    int j;
    for (j = 21; j >= 0; j--)
    {
        if (j == 21)
        {
            system("color 01");
        }
        if (j == 19)
        {
            system("color 02");
        }
        if (j == 18)
        {
            system("color 03");
        }
        if (j == 17)
        {
            system("color 04");
        }
        if (j == 16)
        {
            system("color 05");
        }
        if (j == 15)
        {
            system("color 06");
        }
        if (j == 14)
        {
            system("color 07");
        }
        if (j == 13)
        {
            system("color 08");
        }
        if (j == 12)
        {
            system("color 09");
        }
        if (j == 11)
        {
            system("color 0A");
        }
        if (j == 10)
        {
            system("color 0B");
        }
        if (j == 9)
        {
            system("color 0C");
        }
        if (j == 8)
        {
            system("color 0D");
        }
        if (j == 7)
        {
            system("color 0E");
        }
        if (j == 6)
        {
            system("color 0F");
        }
        if (j == 5)
        {
            system("color 01");
        }
        if (j == 4)
        {
            system("color 02");
        }
        if (j == 3)
        {
            system("color 03");
        }
        if (j == 2)
        {
            system("color 0C");
        }
        if (j == 1)
        {
            system("color 0E");
        }
        if (j == 0)
        {
            system("color 0F");
        }
        system("cls");
        CursorPosition(46, j - 1);
        printf("THIS SYSTEM IS DESIGNED BY");
        CursorPosition(46, j + 1);
        printf("Sufiyaan Usmani  (21K-3195)");
        CursorPosition(46, j + 2);
        printf("Ahsan Ashraf     (21K-3186)");
        CursorPosition(46, j + 3);
        printf("Qasim Hasan      (21K-3210)");
        CursorPosition(0, 0);
        Sleep(600);
    }
}

#endif